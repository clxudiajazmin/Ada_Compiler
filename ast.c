#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* flag variable that shows revisit in assignment expression */
int cont_revisit = 0; // 1: contains revisit, 0: not

/* ------------------AST NODE MANAGEMENT-------------------- */
/* The basic node */
AST_Node *new_ast_node(Node_Type type, AST_Node *left, AST_Node *right){
	// allocate memory
	AST_Node *v = malloc (sizeof (AST_Node));
	
	// set entries
	v->type = type;
	v->left = left;
	v->right = right;
	
	// return the result
	return v;
}

/* Declarations */
AST_Node *new_declarations_node(AST_Node **declarations, int declaration_count, AST_Node *declaration){
	// allocate memory
	AST_Node_Declarations *v = malloc (sizeof (AST_Node_Declarations));
	
	// set node type
	v->type = DECLARATIONS;
	
	// first declaration
	if(declarations == NULL){
		declarations = (AST_Node**) malloc (sizeof (AST_Node*));
		declarations[0] = declaration;
		declaration_count = 1;
	}
	// add new declaration
	else{
		declarations = (AST_Node**) realloc (declarations, (declaration_count + 1) * sizeof (AST_Node*));
		declarations[declaration_count] = declaration;
		declaration_count++;
	}
	
	// set entries
	v->declarations = declarations;
	v->declaration_count = declaration_count;
	
	// return type-casted result
	return (struct AST_Node *) v;
}

AST_Node *new_ast_decl_node(int data_type, list_t **names, int names_count){
	// allocate memory
	AST_Node_Decl *v = malloc (sizeof (AST_Node_Decl));
	
	// set entries
	v->type = DECL_NODE;
	v->data_type = data_type;
	v->names = names;
	v->names_count = names_count;
	
	// return type-casted result
	return (struct AST_Node *) v;
}

AST_Node *new_ast_const_node(int const_type, Value val){
	// allocate memory
	AST_Node_Const *v = malloc (sizeof (AST_Node_Const));
	
	// set entries
	v->type = CONST_NODE;
	v->const_type = const_type;
	v->val = val;
	
	// return type-casted result
	return (struct AST_Node *) v;
}

/* Statements */

AST_Node *new_statements_node(AST_Node **statements, int statement_count, AST_Node *statement){
	// allocate memory
	AST_Node_Statements *v = malloc (sizeof (AST_Node_Statements));
	
	// set node type
	v->type = STATEMENTS;
	
	// first statement
	if(statements == NULL){
		statements = (AST_Node**) malloc (sizeof (AST_Node*));
		statements[0] = statement;
		statement_count = 1;
	}
	// add new statement
	else{
		statements = (AST_Node**) realloc (statements, (statement_count + 1) * sizeof (AST_Node*));
		statements[statement_count] = statement;
		statement_count++;
	}
	
	// set entries
	v->statements = statements;
	v->statement_count = statement_count;
	
	// return type-casted result
	return (struct AST_Node *) v;
}

AST_Node *new_ast_if_node(AST_Node *condition, AST_Node *if_branch, AST_Node **elsif_branches,
	int elseif_count, AST_Node *else_branch){
	// allocate memory
	AST_Node_If *v = malloc (sizeof (AST_Node_If));
	
	// set entries
	v->type = IF_NODE;
	v->condition = condition;
	v->if_branch = if_branch;
	v->elsif_branches = elsif_branches;
	v->elseif_count = elseif_count;
	v->else_branch = else_branch;
	
	// return type-casted result
	return (struct AST_Node *) v;
}

AST_Node *new_ast_endif_node(){
	return (struct AST_Node *) v;
}

AST_Node *new_ast_elsif_node(AST_Node *condition, AST_Node *elsif_branch){
	// allocate memory
	AST_Node_Elsif *v = malloc (sizeof (AST_Node_Elsif));
	
	// set entries
	v->type = ELSIF_NODE;
	v->condition = condition;
	v->elsif_branch = elsif_branch;
	
	// return type-casted result
	return (struct AST_Node *) v;
}

AST_Node *new_ast_while_node(AST_Node *condition, AST_Node *while_branch){
	// allocate memory
	AST_Node_While *v = malloc (sizeof (AST_Node_While));
	
	// set entries
	v->type = WHILE_NODE;
	v->condition = condition;
	v->while_branch = while_branch;
	
	// return type-casted result
	return (struct AST_Node *) v;
}

AST_Node *new_ast_assign_node(list_t *entry, int ref, AST_Node *assign_val){
	// allocate memory
	AST_Node_Assign *v = malloc (sizeof (AST_Node_Assign));
	
	// set entries
	v->type = ASSIGN_NODE;
	v->entry = entry;
	v->ref = ref;
	v->assign_val = assign_val;
	
	// return type-casted result
	return (struct AST_Node *) v;
}

AST_Node *new_ast_simple_node(int statement_type){
	// allocate memory
	AST_Node_Simple *v = malloc (sizeof (AST_Node_Simple));
	
	// set entries
	v->type = SIMPLE_NODE;
	v->statement_type = statement_type;
	
	// return type-casted result
	return (struct AST_Node *) v;
}
/* Expressions */

AST_Node *new_ast_arithm_node(enum Arithm_op op, AST_Node *left, AST_Node *right){
	// allocate memory
	AST_Node_Arithm *v = malloc (sizeof (AST_Node_Arithm));
	
	// set entries
	v->type = ARITHM_NODE;
	v->op = op;
	v->left = left;
	v->right = right;	
	
	// set data type
	v->data_type = get_result_type(
			expression_data_type(left),  /* data type of left expression */
			expression_data_type(right), /* data type of right expression */
			ARITHM_OP                    /* operation type */
	);
	
	// return type-casted result
	return (struct AST_Node *) v;
}

AST_Node *new_ast_bool_node(enum Bool_op op, AST_Node *left, AST_Node *right){
	// allocate memory
	AST_Node_Bool *v = malloc (sizeof (AST_Node_Bool));
	
	// set entries
	v->type = BOOL_NODE;
	v->op = op;
	v->left = left;
	v->right = right;
	
	// set data type
	if(v->op != NOT){ /* AND or OR */
		v->data_type = get_result_type(
			expression_data_type(left),  /* data type of left expression */
			expression_data_type(right), /* data type of right expression */
			BOOL_OP                      /* operation type */
		);	
	}
	else{ /* NOT */
		v->data_type = get_result_type(
			expression_data_type(left), /* data type of left expression */
			UNDEF,                      /* there is no right expression */
			NOT_OP                      /* operation type */
		);	
	}
	
	// return type-casted result
	return (struct AST_Node *) v;
}

AST_Node *new_ast_rel_node(enum Rel_op op, AST_Node *left, AST_Node *right){
	// allocate memory
	AST_Node_Rel *v = malloc (sizeof (AST_Node_Rel));
	
	// set entries
	v->type = REL_NODE;
	v->op = op;
	v->left = left;
	v->right = right;
	
	// set data type
	v->data_type = get_result_type(
			expression_data_type(left),  /* data type of left expression  */
			expression_data_type(right), /* data type of right expression */
			REL_OP                       /* operation type */
	);
	
	// return type-casted result
	return (struct AST_Node *) v;
}

AST_Node *new_ast_equ_node(enum Equ_op op, AST_Node *left, AST_Node *right){
	// allocate memory
	AST_Node_Equ *v = malloc (sizeof (AST_Node_Equ));
	
	// set entries
	v->type = EQU_NODE;
	v->op = op;
	v->left = left;
	v->right = right;
	
	// set data type
	v->data_type = get_result_type(
			expression_data_type(left),  /* data type of left expression  */
			expression_data_type(right), /* data type of right expression */
			EQU_OP                       /* operation type */
	);
	
	// return type-casted result
	return (struct AST_Node *) v;	
}

AST_Node *new_ast_ref_node(list_t *entry, int ref){
	// allocate memory
	AST_Node_Ref *v = malloc (sizeof (AST_Node_Ref));
	
	// set entries
	v->type = REF_NODE;
	v->entry = entry;
	v->ref = ref;
	
	// return type-casted result
	return (struct AST_Node *) v;	
}

int expression_data_type(AST_Node *node){
	/* temp nodes */
	AST_Node_Arithm *temp_arithm;
	AST_Node_Bool *temp_bool;
	AST_Node_Rel *temp_rel;
	AST_Node_Equ *temp_equ;
	AST_Node_Ref *temp_ref;
	AST_Node_Const *temp_const;
	
	/* return type depends on the AST node type */
	switch(node->type){
		case ARITHM_NODE: /* arithmetic expression */
			temp_arithm = (AST_Node_Arithm *) node;
			
			/* set datatype again */
			temp_arithm->data_type = get_result_type(
				expression_data_type(temp_arithm->left),  /* data type of left expression */
				expression_data_type(temp_arithm->right), /* data type of right expression */
				ARITHM_OP                    /* operation type */
			);
			
			return temp_arithm->data_type; 
			break;
		case BOOL_NODE:   /* boolean expression */
			temp_bool = (AST_Node_Bool *) node;
			
			/* set datatype again */
			if(temp_bool->op != NOT){ /* AND or OR */
				temp_bool->data_type = get_result_type(
					expression_data_type(temp_bool->left),  /* data type of left expression */
					expression_data_type(temp_bool->right), /* data type of right expression */
					BOOL_OP                      /* operation type */
				);	
			}
			else{ /* NOT */
				temp_bool->data_type = get_result_type(
					expression_data_type(temp_bool->left), /* data type of left expression */
					UNDEF,                      /* there is no right expression */
					NOT_OP                      /* operation type */
				);	
			}
			
			return temp_bool->data_type;
			break;
		case REL_NODE:    /* relational expression */
			temp_rel = (AST_Node_Rel *) node;
			
			/* set datatype again */
			temp_rel->data_type = get_result_type(
					expression_data_type(temp_rel->left),  /* data type of left expression  */
					expression_data_type(temp_rel->right), /* data type of right expression */
					REL_OP                       /* operation type */
			);
			
			return temp_rel->data_type;
			break;
		case EQU_NODE:    /* equality expression */
			temp_equ = (AST_Node_Equ *) node;
			
			/* set datatype again */
			temp_equ->data_type = get_result_type(
					expression_data_type(temp_equ->left),  /* data type of left expression  */
					expression_data_type(temp_equ->right), /* data type of right expression */
					EQU_OP                       /* operation type */
			);
			
			return temp_equ->data_type;
			break;
		case REF_NODE:    /* identifier reference */
			temp_ref = (AST_Node_Ref *) node;
			/* if "simple" type */
			int type = temp_ref->entry->st_type;
			if(type == INT_TYPE	|| type == REAL_TYPE || type == CHAR_TYPE){
				return temp_ref->entry->st_type;
			}
			/* if array or pointer */
			else{
				return temp_ref->entry->inf_type;
			}
			break;
		case CONST_NODE:  /* constant */
			temp_const = (AST_Node_Const *) node;
			return temp_const->const_type; /* constant data type */
			break;
		default: /* wrong choice case */
			fprintf(stderr, "Error en selección de nodo!\n");
			exit(1);
	}
}

int getGraphIndex(AST_Node *node){
	/* temp nodes */
	AST_Node_Arithm *temp_arithm;
	AST_Node_Bool *temp_bool;
	AST_Node_Rel *temp_rel;
	AST_Node_Equ *temp_equ;
	AST_Node_Ref *temp_ref;
	
	/* return type depends on the AST node type */
	switch(node->type){
		case ARITHM_NODE: /* arithmetic expression */
			temp_arithm = (AST_Node_Arithm *) node;
			
			return temp_arithm->g_index; 
			break;
		case BOOL_NODE:   /* boolean expression */
			temp_bool = (AST_Node_Bool *) node;
			
			return temp_bool->g_index;
			break;
		case REL_NODE:    /* relational expression */
			temp_rel = (AST_Node_Rel *) node;
			
			return temp_rel->g_index;
			break;
		case EQU_NODE:    /* equality expression */
			temp_equ = (AST_Node_Equ *) node;
			
			return temp_equ->g_index;
			break;
		case REF_NODE:    /* identifier reference */
			temp_ref = (AST_Node_Ref *) node;
			
			return temp_ref->entry->g_index;
			break;
		case CONST_NODE:  /* constant */
			return -1;
			break;
		default: /* wrong choice case */
			fprintf(stderr, "Error en nodo de selección!\n");
			exit(1);
	}
}

/* Tree Traversal */

void ast_print_node(AST_Node *node){
	/* temp nodes */
	AST_Node_Declarations *temp_declarations;
	AST_Node_Decl *temp_decl;
	AST_Node_Const *temp_const;
	AST_Node_Statements *temp_statements;
	AST_Node_If *temp_if;
	AST_Node_Assign *temp_assign;
	AST_Node_Simple *temp_simple;
	AST_Node_Arithm *temp_arithm;
	AST_Node_Bool *temp_bool;
	AST_Node_Rel *temp_rel;
	AST_Node_Equ *temp_equ;
	AST_Node_Ref *temp_ref;
	
	switch(node->type){
		case BASIC_NODE:
			printf("nodo Básico\n");
			break;
		case DECLARATIONS:
			temp_declarations = (struct AST_Node_Declarations *) node;
			printf("Nodo de declaración con %d declaraciones\n", temp_declarations->declaration_count);
			break;
		case DECL_NODE:
			temp_decl = (struct AST_Node_Decl *) node;
			printf("Nodo de declaración de data-type %d para %d nombres\n",
				temp_decl->data_type, temp_decl->names_count);
			break;
		case CONST_NODE:
			temp_const = (struct AST_Node_Const *) node;
			printf("Nodo Constante de const-type %d con valor ", temp_const->const_type);
			switch(temp_const->const_type){
				case INT_TYPE:
					printf("%d\n", temp_const->val.ival);
					break;
				case REAL_TYPE:
					printf("%.2f\n", temp_const->val.fval);
					break;
				case CHAR_TYPE:
					printf("%c\n",  temp_const->val.cval);
					break;
				case STR_TYPE:
					printf("%s\n",  temp_const->val.sval);
					break;
			}
			break;
		case STATEMENTS:
			temp_statements = (struct AST_Node_Statements *) node;
			printf("Nodo de Statements con %d statements\n", temp_statements->statement_count);
			break;
		case IF_NODE:
			temp_if = (struct AST_Node_If *) node;
			printf("Nodo If con %d elseifs y ", temp_if->elseif_count);
			if(temp_if->else_branch == NULL){
				printf("no else\n");
			}
			else{
				printf("else\n");
			}			
			break;
		case ELSIF_NODE:
			printf("Nodo Elsif\n");
			break;
		case WHILE_NODE:
			printf("Nodo While\n");
			break;
		case ASSIGN_NODE:
			temp_assign = (struct AST_Node_Assign *) node;
			printf("Nodo de Asignación de entrada %s\n", temp_assign->entry->st_name);
			break;
		case SIMPLE_NODE:
			temp_simple = (struct AST_Node_Simple *) node;
			printf("Nodo simple de statement %d\n", temp_simple->statement_type);
			break;
		case ARITHM_NODE:
			temp_arithm = (struct AST_Node_Arithm *) node;
			printf("Nodo Aritmético con operador %d con resultado de tipo %d\n", temp_arithm->op, temp_arithm->data_type);
			break;
		case BOOL_NODE:
			temp_bool = (struct AST_Node_Bool *) node;
			printf("Nodo booleano de operador %d\n", temp_bool->op);
			break;
		case REL_NODE:
			temp_rel = (struct AST_Node_Rel *) node;
			printf("Nodo relacional de operador %d\n", temp_rel->op);
			break;
		case EQU_NODE:
			temp_equ = (struct AST_Node_Equ *) node;
			printf("Nodo de igualdad de operador %d\n", temp_equ->op);
			break;
		case REF_NODE:
			temp_ref = (struct AST_Node_Ref *) node;
			printf("Nodo de referencia de entrada %s\n", temp_ref->entry->st_name);
			break;
		default: /* wrong choice case */
			fprintf(stderr, "Error en selección de nodo!\n");
			exit(1);
	}
}

void ast_traversal(AST_Node *node){
	int i;
	
	/* check if empty */
	if(node == NULL){
		return;
	}
	
	/* left and right child cases */
	if(node->type == BASIC_NODE || node->type == ARITHM_NODE || node->type == BOOL_NODE
	|| node->type == REL_NODE || node->type == EQU_NODE){
		ast_traversal(node->left);
		ast_traversal(node->right);
		ast_print_node(node); // postfix
	}
	/* declarations case */
	else if(node->type == DECLARATIONS){
		AST_Node_Declarations *temp_declarations = (struct AST_Node_Declarations *) node;	
		ast_print_node(node);	
		for(i = 0; i < temp_declarations->declaration_count; i++){
			ast_traversal(temp_declarations->declarations[i]);
		}
	}
	/* statements case */
	else if(node->type == STATEMENTS){
		AST_Node_Statements *temp_statements = (struct AST_Node_Statements *) node;	
		ast_print_node(node);	
		for(i = 0; i < temp_statements->statement_count; i++){
			ast_traversal(temp_statements->statements[i]);
		}
	}
	/* the if case */
	else if(node->type == IF_NODE){
		AST_Node_If *temp_if = (struct AST_Node_If *) node;	
		ast_print_node(node);
		
		printf("Condición:\n");
		ast_traversal(temp_if->condition);
		
		printf("If branch:\n");
		ast_traversal(temp_if->if_branch);
		
		if(temp_if->elseif_count > 0 ){
			printf("Else if branches:\n");
			for(i = 0; i < temp_if->elseif_count; i++){
				printf("Else if branch%d:\n", i);
				ast_traversal(temp_if->elsif_branches[i]);
			}	
		}
	
		if(temp_if->else_branch != NULL){
			printf("Else branch:\n");
			ast_traversal(temp_if->else_branch);
		}
	}
	/* the else if case */
	else if(node->type == ELSIF_NODE){
		AST_Node_Elsif *temp_elsif = (struct AST_Node_Elsif *) node;
		ast_print_node(node);
		ast_traversal(temp_elsif->condition);
		ast_traversal(temp_elsif->elsif_branch);
	}
	/* while case */
	else if(node->type == WHILE_NODE){
		AST_Node_While *temp_while = (struct AST_Node_While *) node;
		ast_print_node(node);
		printf("Condición:\n");
		ast_traversal(temp_while->condition);
		printf("While branch:\n");
		ast_traversal(temp_while->while_branch);
	}
	/* assign case */
	else if(node->type == ASSIGN_NODE){
		AST_Node_Assign *temp_assign = (struct AST_Node_Assign *) node;
		ast_print_node(node);
		printf("Asignando:\n");
		ast_traversal(temp_assign->assign_val);
	}
	/* others */
	else{
		ast_print_node(node);
	}
}