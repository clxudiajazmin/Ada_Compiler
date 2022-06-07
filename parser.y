
%{
	#include "semantics.c"
	#include "symtab.c"
	#include "ast.h"
	#include "ast.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern FILE *yyin;
	extern FILE *yyout;
	extern int lineno;
	extern int yylex();
	void yyerror();

	// for declarations
	void add_to_names(list_t *entry);
	list_t **names;
	int nc = 0;

	// for else ifs
	void add_elseif(AST_Node *elsif);
	AST_Node **elsifs;
	int elseif_count = 0;
%}

/* YYSTYPE union */
%union{
	// different types of values
	Value val;

	// structures
	list_t* symtab_item;
	AST_Node* node;

	// for declarations
	int data_type;
	int const_type;

}


%token<val> CHAR STR INT FLOAT
%token<val> ADDOP MULOP DIVOP INCR OROP ANDOP NOTOP EQUOP RELOP
%token<val> FIRST LAST IMAGE VALUE MIN MAX PRED SUCC
%token<val> PROC IS BEG END
%token<val> SEPARADOR
%token<val> ASSIGN INI LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI DOT COMMA CHANGE
%token<val> TYPE RANGE OF ARRAY TWOPOINTS NEW RET
%token<val> IF THEN ELSE ELSIF
%token<val> FOR IN LOOP REVERSE WHILE
%token<val> PUT GET NEW_LINE 
%token<symtab_item> IDENT 
%token<val> INTCONST 
%token<val> FLOATCONST 
%token<val> STRING 
%token<val> CHARCONST


%left COMMA
%right ASSIGN
%left OROP
%left ANDOP
%left EQUOP
%left RELOP
%left ADDOP
%left MULOP DIVOP
%right NOTOP INCR
%left LPAREN RPAREN LBRACK RBRACK

%type <node> program
%type <node> declarations declaration
%type <data_type> type
%type <symtab_item> name
%type <node> constant
%type <node> expression var_ref
%type <node> for_statement
%type <val> sign
%type <node> statement assigment
%type <node> statements
%type <node> if_statement elsif_part else_part
%type <node> while_statement

%start program

%%
program:procedure;

procedure: PROC IDENT IS declarations BEG statements END IDENT SEMI
;

declarations: declarations declaration
|  declaration
| /* empty */
;

declaration: names  INI type SEMI
{
		int i;
		$$ = new_ast_decl_node($3, names, nc);
		nc = 0;

		AST_Node_Decl *temp = (AST_Node_Decl*) $$;

		// declare types of the names
		for(i=0; i < temp->names_count; i++){
			// variable
			if(temp->names[i]->st_type == UNDEF){
				set_type(temp->names[i]->st_name, temp->data_type, UNDEF);
			}
		}
	}
;


type: INT  		{ $$ = INT_TYPE;   }
	| CHAR 		{ $$ = CHAR_TYPE;   }
	| FLOAT 	{ $$ = REAL_TYPE;   }
;

names: name { add_to_names($1); }
| names COMMA name  { add_to_names($3); }
;


name: IDENT { $$ = $1; }
;

constant: INTCONST 	{ $$ = new_ast_const_node(INT_TYPE, $1);  }
| FLOATCONST		{ $$ = new_ast_const_node(REAL_TYPE, $1);  }
| STRING			{ $$ = new_ast_const_node(CHAR_TYPE, $1);  }
| CHARCONST			{ $$ = new_ast_const_node(CHAR_TYPE, $1);  }
;

statements: statements statement
	{
		AST_Node_Statements *temp = (AST_Node_Statements*) $1;
		$$ = new_statements_node(temp->statements, temp->statement_count, $2);
	}
| statement
	{
		$$ = new_statements_node(NULL, 0, $1);
	}
;

statement: assigment
	{
		$$ = $1; /* just pass information */
		ast_traversal($$); /* just for testing */
	}
| if_statement
	{
		$$ = $1; /* just pass information */
		ast_traversal($$); /* just for testing */
	}
| while_statement
	{ 
	$$ = $1; /* just pass information */
	ast_traversal($$); /* just for testing */
	}
| for_statement { $$ = $1; /* will do it later ! */ }
| put_statement { $$ = NULL; /* will do it later ! */ }
| get_statement { $$ = NULL; /* will do it later ! */ }
| new_line_statement { $$ = NULL; /* will do it later ! */ }
;


if_statement: IF expression THEN statements elsif_part else_part END IF SEMI
	{
		$$ = new_ast_if_node($2, $4, elsifs, elseif_count, $6);
		elseif_count = 0;
		elsifs = NULL;
	}
| IF expression THEN statements else_part END IF SEMI
	{
		$$ = new_ast_if_node($2, $4, NULL, 0, $5);
	}
;

elsif_part: elsif_part ELSIF expression THEN statements
	{
		AST_Node *temp = new_ast_elsif_node($3, $5);
		add_elseif(temp);
	}
|ELSIF expression THEN statements
	{
		AST_Node *temp = new_ast_elsif_node($2, $4);
		add_elseif(temp);
	}
;

else_part: ELSE expression THEN statements
	{
		/* else exists */
		$$ = $2;
	}
| /* empty */
	{
		/* no else */
		$$ = NULL;
	}
;



while_statement: WHILE expression LOOP statements END LOOP SEMI
{
	$$ = new_ast_while_node($2, $4);
}
for_statement: FOR IDENT IN  INTCONST TWOPOINTS INTCONST LOOP statements END LOOP SEMI{
	/* create increment node*/
	AST_Node *incr_node, *asing_node, *exp_node, *constante, *constante_2, *constante_6;
	incr_node = new_ast_incr_node($2, 0, 0);
	AST_Node_Ref *temp = (AST_Node_Ref*) $2;
	constante = new_ast_const_node(INT_TYPE, $4.ival);
	asing_node = new_ast_assign_node(temp->entry, temp->ref, constante);
	constante_2 = new_ast_const_node(INT_TYPE, $2.ival);
	constante_6 = new_ast_const_node(INT_TYPE, $6.ival);
	exp_node =  new_ast_rel_node(1, constante_2, constante_6);

	$$ = new_ast_for_node(asing_node, exp_node, incr_node, $8);
	set_loop_counter($$);
}
| FOR IDENT IN REVERSE INTCONST TWOPOINTS INTCONST LOOP statements END LOOP SEMI{
	/* create increment node*/
	AST_Node *incr_node, *asing_node, *exp_node;
	incr_node = new_ast_incr_node($2, 1, 0);

	AST_Node_Ref *temp = (AST_Node_Ref*) $2;
	asing_node = new_ast_assign_node(temp->entry, temp->ref,$7);
	exp_node =  new_ast_rel_node(0, $2, $5);


	$$ = new_ast_for_node(asing_node, exp_node, incr_node, $9);
	set_loop_counter($$);
}
;

put_statement: PUT LPAREN expression RPAREN SEMI
;

get_statement: GET LPAREN expression RPAREN SEMI
;

new_line_statement: NEW_LINE SEMI
;

expression: expression ADDOP expression
	{
	    $$ = new_ast_arithm_node($2.ival, $1, $3);
	}
| expression MULOP expression
	{
	    $$ = new_ast_arithm_node(MUL, $1, $3);
	}
| expression DIVOP expression
	{
		$$ = new_ast_arithm_node(DIV, $1, $3);
	}
| expression ANDOP expression
	{
		$$ = new_ast_bool_node(AND, $1, $3);
	}
| expression OROP expression
	{
		$$ = new_ast_bool_node(OR, $1, $3);
	}
| expression EQUOP expression
	{
		$$ = new_ast_equ_node($2.ival, $1, $3);
	}
| expression RELOP expression
	{
		$$ = new_ast_rel_node($2.ival, $1, $3);
	}
| NOTOP expression
	{
	    $$ = new_ast_bool_node(NOT, $2, NULL);
	}
| LPAREN expression RPAREN
	{
		$$ = $2; /* just pass information */
	}
| var_ref
	{
		$$ = $1; /* just pass information */
	}
| sign constant
	{
		/* sign */
		if($1.ival == 1){
			AST_Node_Const *temp = (AST_Node_Const*) $2;

			/* inverse value depending on the constant type */
			switch(temp->const_type){
				case INT_TYPE:
					temp->val.ival *= -1;
					break;
				case REAL_TYPE:
					temp->val.fval *= -1;
					break;
				case CHAR_TYPE:
					/* sign before char error */
					fprintf(stderr, "Error having sign before character constant!\n");
					exit(1);
					break;
			}

			$$ = (AST_Node*) temp;
		}
		/* no sign */
		else{
			$$ = $2;
		}
	}
;

sign: ADDOP
	{
		/* plus sign error */
		if($1.ival == ADD){
			fprintf(stderr, "Error having plus as a sign!\n");
			exit(1);
		}
		else{
			$$.ival = 1; /* sign */
		}
	}
	| /* empty */
	{
		$$.ival = 0; /* no sign */
	}
;

assigment: var_ref ASSIGN expression SEMI
{
	AST_Node_Ref *temp = (AST_Node_Ref*) $1;
	$$ = new_ast_assign_node(temp->entry, temp->ref, $3);
}
;

var_ref: name
	{
		$$ = new_ast_ref_node($1, 0); /* no reference */
	}

%%

void add_to_names(list_t *entry){
	// first entry
	if(nc == 0){
		nc = 1;
		names = (list_t **) malloc( 1 * sizeof(list_t *));
		names[0] = entry;
	}
	// general case
	else{
		nc++;
		names = (list_t **) realloc(names, nc * sizeof(list_t *));
		names[nc - 1] = entry;
	}
}

void add_elseif(AST_Node *elsif){
	// first entry
	if(elseif_count == 0){
		elseif_count = 1;
		elsifs = (AST_Node **) malloc(1 * sizeof(AST_Node));
		elsifs[0] = elsif;
	}
	// general case
	else{
		elseif_count++;
		elsifs = (AST_Node **) realloc(elsifs, elseif_count * sizeof(AST_Node));
		elsifs[elseif_count - 1] = elsif;
	}
}

void yyerror ()
{
  fprintf(stderr, "Error de sintaxis en linea %d\n", lineno);
  yylex();
  exit(1);
}

int main (int argc, char *argv[]){

	// initialize symbol table
	init_hash_table();

	// initialize revisit queue
	queue = NULL;

	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);

	printf("Parsing finished!\n");

	if(queue != NULL){
		printf("Warning: Something has not been checked in the revisit queue!\n");
	}

	// symbol table dump
	yyout = fopen("symtab_dump.out", "w");
	symtab_dump(yyout);
	fclose(yyout);

	// revisit queue dump
	yyout = fopen("revisit_dump.out", "w");
	revisit_dump(yyout);
	fclose(yyout);

	return flag;
}
