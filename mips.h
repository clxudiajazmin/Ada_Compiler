// main assembly code genereation function, called from parser.y before flag
void generate_code();

// generation declaration assembly code
void generate_data_declarations(FILE *fp);

// Variable Array 
static char **var_name; 
static int var_count = 0; 
static int temp_count = 0; 
void insertVar(char *name);
int getVarIndex(char *name);
void printVarArray();

//Adjacency List
typedef struct AdjList{
	int index;
	struct AdjList *next;
}AdjList;

//Adjacency Graph
typedef struct AdjGraph{
	AdjList **adj;
	int vertexCount;
}AdjGraph;

/* Graph Functions */
static AdjGraph *g;
void initGraph();
void insertEdge(int i, int j);
void printGraph();
int* greedyColoring();


void main_reg_allocation(AST_Node *node);