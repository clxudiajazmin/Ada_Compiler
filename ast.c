#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

AST_Node *new_ast_for_node(AST_Node *initialize, AST_Node *condition, AST_Node *increment, AST_Node *for_branch){
	// allocate memory
	AST_Node_For *v = malloc (sizeof (AST_Node_For));
	
	// set entries
	v->type = FOR_NODE;
	v->initialize = initialize;
	v->condition = condition;
	v->increment = increment;
	v->for_branch = for_branch;
	
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


/* Tree Traversal */

void ast_print_node(AST_Node *node){
	/* temp nodes */
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
			printf("Basic Node\n");
			break;
		case DECL_NODE:
			temp_decl = (struct AST_Node_Decl *) node;
			printf("Declaration Node of data-type %d for %d names\n",
				temp_decl->data_type, temp_decl->names_count);
			break;
		case CONST_NODE:
			temp_const = (struct AST_Node_Const *) node;
			printf("Constant Node of const-type %d with value ", temp_const->const_type);
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
			}
			break;
		case STATEMENTS:
			temp_statements = (struct AST_Node_Statements *) node;
			printf("Statements Node with %d statements\n", temp_statements->statement_count);
			break;
		case IF_NODE:
			temp_if = (struct AST_Node_If *) node;
			printf("If Node with %d elseifs and ", temp_if->elseif_count);
			if(temp_if->else_branch == NULL){
				printf("no else\n");
			}
			else{
				printf("else\n");
			}			
			break;
		case ELSIF_NODE:
			printf("Elsif Node\n");
			break;
		case ASSIGN_NODE:
			temp_assign = (struct AST_Node_Assign *) node;
			printf("Assign Node of entry %s\n", temp_assign->entry->st_name);
			break;
		case SIMPLE_NODE:
			temp_simple = (struct AST_Node_Simple *) node;
			printf("Simple Node of statement %d\n", temp_simple->statement_type);
			break;
		case ARITHM_NODE:
			temp_arithm = (struct AST_Node_Arithm *) node;
			printf("Arithmetic Node of operator %d\n", temp_arithm->op);
			break;
		case BOOL_NODE:
			temp_bool = (struct AST_Node_Bool *) node;
			printf("Boolean Node of operator %d\n", temp_bool->op);
			break;
		case REL_NODE:
			temp_rel = (struct AST_Node_Rel *) node;
			printf("Relational Node of operator %d\n", temp_rel->op);
			break;
		case EQU_NODE:
			temp_equ = (struct AST_Node_Equ *) node;
			printf("Equality Node of operator %d\n", temp_equ->op);
			break;
		case REF_NODE:
			temp_ref = (struct AST_Node_Ref *) node;
			printf("Reference Node of entry %s\n", temp_ref->entry->st_name);
			break;
		default: /* wrong choice case */
			fprintf(stderr, "Error in node selection!\n");
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
		printf("Condition:\n");
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
	/* for case */
	else if(node->type == FOR_NODE){
		AST_Node_For *temp_for = (struct AST_Node_For *) node;
		ast_print_node(node);
		printf("Initialize:\n");
		ast_traversal(temp_for->initialize);
		printf("Condition:\n");
		ast_traversal(temp_for->condition);
		printf("Increment:\n");
		ast_traversal(temp_for->increment);
		printf("For branch:\n");
		ast_traversal(temp_for->for_branch);
	}
	/* assign case */
	else if(node->type == ASSIGN_NODE){
		AST_Node_Assign *temp_assign = (struct AST_Node_Assign *) node;
		ast_print_node(node);
		printf("Assigning:\n");
		ast_traversal(temp_assign->assign_val);
	}
	/* others */
	else{
		ast_print_node(node);
	}
}