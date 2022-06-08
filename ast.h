/* ---------------------NODE TYPES-------------------------- */

typedef enum Node_Type {
	BASIC_NODE,   //  0 - no special usage (for roots only)
	// declarations
	DECLARATIONS, //  1 - declarations
	DECL_NODE,    //  2 - declaration
	CONST_NODE,   //  3 - constant
	// statements
	STATEMENTS,   //  4 - statements
	IF_NODE,      //  5 - if statement
	ELSIF_NODE,   //  6 - else if branch
	WHILE_NODE,   //  8 - while statement
	ASSIGN_NODE,  //  9 - assigment
	SIMPLE_NODE,  // 10 - continue or break statement
	// expressions
	ARITHM_NODE,  // 14 - arithmetic expression
	BOOL_NODE,    // 15 - boolean expression
	REL_NODE,     // 16 - relational expression
	EQU_NODE,     // 17 - equality expression
	REF_NODE,	  // 18 - identifier in expression
}Node_Type;

/* --------------------OPERATOR TYPES----------------------- */

typedef enum Arithm_op{
	ADD,  // + operator
	SUB,  // - operator
	MUL,  // * operator
	DIV , // / operator
}Arithm_op;

typedef enum Bool_op{
	OR,  // || operator
	AND, // && operator
	NOT  // ! operator
}Bool_op;

typedef enum Rel_op{
	GREATER,        // > operator
	LESS,           // < operator
	GREATER_EQUAL,  // >= operator
	LESS_EQUAL     // <= operator
}Rel_op;

typedef enum Equ_op{
	EQUAL,    // == operator
	NOT_EQUAL // != operator
}Equ_op;

/* -----------------------AST NODES------------------------- */

/* The basic node */
typedef struct AST_Node{
	enum Node_Type type; // node type
	
	struct AST_Node *left;  // left child
	struct AST_Node *right; // right child
}AST_Node;

/* Declarations */
typedef struct AST_Node_Declarations{
	enum Node_Type type; // node type
	
	// declarations
	struct AST_Node **declarations;
	int declaration_count;
}AST_Node_Declarations;

typedef struct AST_Node_Decl{
	enum Node_Type type; // node type
	
	// data type
	int data_type;
	
	// symbol table entries of the variables
	list_t **names;
	int names_count;
}AST_Node_Decl;

typedef struct AST_Node_Const{
	enum Node_Type type; // node type
	
	// data type
	int const_type;
	
	// constant value
	Value val;
}AST_Node_Const;

/* Statements */
typedef struct AST_Node_Statements{
	enum Node_Type type; // node type
	
	// statements
	struct AST_Node **statements;
	int statement_count;
}AST_Node_Statements;

typedef struct AST_Node_If{
	enum Node_Type type; // node type
	
	// condition
	struct AST_Node *condition;
	
	// if branch
	struct AST_Node *if_branch;
	
	// else if branches
	struct AST_Node **elsif_branches;
	int elseif_count;
	
	// else branch
	struct AST_Node *else_branch;
}AST_Node_If;

typedef struct AST_Node_Elsif{
	enum Node_Type type; // node type
	
	// condition
	struct AST_Node *condition;
	
	// branch
	struct AST_Node *elsif_branch;
}AST_Node_Elsif;

typedef struct AST_Node_While{
	enum Node_Type type; // node type
	
	// condition
	struct AST_Node *condition;
	
	// branch
	struct AST_Node *while_branch;
}AST_Node_While;

typedef struct AST_Node_Assign{
	enum Node_Type type; // node type
	
	// symbol table entry
	list_t *entry;
	
	// reference or not
	int ref; // 0: not reference, 1: reference
	
	// assignment value
	struct AST_Node *assign_val;
}AST_Node_Assign;

typedef struct AST_Node_Simple{
	enum Node_Type type; // node type
	
	// continue: '0', break: '1'
	int statement_type;
}AST_Node_Simple;

/* Expressions */
typedef struct AST_Node_Arithm{
	enum Node_Type type; // node type
	
	struct AST_Node *left;  // left child
	struct AST_Node *right; // right child
	
	// data type of result
	int data_type;
	
	// operator
	enum Arithm_op op;
	
	/* register assignment stuff */
	int g_index;
}AST_Node_Arithm;

typedef struct AST_Node_Bool{
	enum Node_Type type; // node type
	
	struct AST_Node *left;  // left child
	struct AST_Node *right; // right child
	
	// data type of result
	int data_type;
	
	// operator
	enum Bool_op op;
	
	/* register assignment stuff */
	int g_index;
}AST_Node_Bool;

typedef struct AST_Node_Rel{
	enum Node_Type type; // node type
	
	struct AST_Node *left;  // left child
	struct AST_Node *right; // right child
	
	// data type of result
	int data_type;
	
	// operator
	enum Rel_op op;
	
	/* register assignment stuff */
	int g_index;
}AST_Node_Rel;

typedef struct AST_Node_Equ{
	enum Node_Type type; // node type
	
	struct AST_Node *left;  // left child
	struct AST_Node *right; // right child
	
	// data type of result
	int data_type;
	
	// operator
	enum Equ_op op;
	
	/* register assignment stuff */
	int g_index;
}AST_Node_Equ;

typedef struct AST_Node_Ref{
	enum Node_Type type; // node type
	
	// symbol table entry
	list_t *entry;
	
	// reference or not
	int ref; // 0: not reference, 1: reference
}AST_Node_Ref;

/* Static AST Structures */
static AST_Node* main_decl_tree; /* main function's declarations AST Tree */
static AST_Node* main_func_tree; /* main function's statements AST Tree */
static AST_Node* opt_func_tree; /* optional functions AST Tree */

/* ------------------AST NODE MANAGEMENT-------------------- */

/* The basic node */
AST_Node *new_ast_node(Node_Type type, AST_Node *left, AST_Node *right); 	 // simple nodes

/* Declarations */
AST_Node *new_declarations_node(AST_Node **declarations, int declaration_count, AST_Node *declaration);
AST_Node *new_ast_decl_node(int data_type, list_t **names, int names_count); // declaration
AST_Node *new_ast_const_node(int const_type, Value val);					 // constant

/* Statements */
AST_Node *new_statements_node(AST_Node **statements, int statement_count, AST_Node *statement);
AST_Node *new_ast_if_node(AST_Node *condition, AST_Node *if_branch, AST_Node **elsif_branches, 
	int elseif_count, AST_Node *else_branch);
AST_Node *new_ast_elsif_node(AST_Node *condition, AST_Node *elsif_branch);
AST_Node *new_ast_while_node(AST_Node *condition, AST_Node *while_branch);
AST_Node *new_ast_assign_node(list_t *entry, int ref, AST_Node *assign_val);
AST_Node *new_ast_simple_node(int statement_type);

/* Expressions */
AST_Node *new_ast_arithm_node(enum Arithm_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_bool_node(enum Bool_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_rel_node(enum Rel_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_equ_node(enum Equ_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_ref_node(list_t *entry, int ref);
int expression_data_type(AST_Node *node);                                    // returns the data type of an expression
int getGraphIndex(AST_Node *node);

/* Tree Traversal */
void ast_print_node(AST_Node *node);	// print information of node
void ast_traversal(AST_Node *node);		// tree traversal (for testing right now)