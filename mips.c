#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mips.h"

void generate_code()
{
    FILE *fp;
    fp = fopen("out.s", "w"); // Open the output of the ast tree
    generate_data_declarations(fp);

    fclose(fp);
}

void generate_data_declarations(FILE *fp)
{
    /* print .data */
    fprintf(fp, ".data\n");
    /* loop through the symbol table's lists */
    int i;
    for (i = 0; i < SIZE; i++)
    {
        /* if hashtable list not empty */
        if (hash_table[i] != NULL)
        {
            list_t *l = hash_table[i];
            /* loop through list */
            while (l != NULL)
            {
                /* Simple Variables */
                if (l->st_type == INT_TYPE)
                {
                    fprintf(fp, "%s: .word %d\n", l->st_name, l->val.ival);
                }
                else if (l->st_type == REAL_TYPE)
                {
                    fprintf(fp, "%s: .double %f\n", l->st_name, l->val.fval);
                }
                else if (l->st_type == CHAR_TYPE)
                {
                    fprintf(fp, "%s: .byte \'%c\'\n", l->st_name, l->val.cval);
                }
                l = l->next;
            }
        }
    }
    fprintf(fp, "# messages\n");
    for (i = 0; i < num_of_msg; i++)
    {
        fprintf(fp, "msg%d: .asciiz %s\n", (i + 1), str_messages[i]);
    }
}

// VAR

void insertVar(char *name)
{
    /* first insertion */
    if (var_count == 0)
    {
        var_name = (char **)malloc(1 * sizeof(char *));
        var_name[0] = (char *)malloc((strlen(name) + 1) * sizeof(char));
        strcpy(var_name[0], name);

        var_count++;
    }
    else
    {
        /* check if variable already exists */
        int flag = 0;
        int i;
        for (i = 0; i < var_count; i++)
        {
            if (strcmp(var_name[i], name) == 0)
            {
                flag = 1;
                break;
            }
        }

        /* not inserted yet */
        if (flag == 0)
        {
            var_name = (char **)realloc(var_name, (var_count + 1) * sizeof(char *));
            var_name[var_count] = (char *)malloc((strlen(name) + 1) * sizeof(char));
            strcpy(var_name[var_count], name);

            var_count++;
        }
    }
}
int getVarIndex(char *name)
{
    int index = -1;

    int i;
    for (i = 0; i < var_count; i++)
    {
        if (strcmp(var_name[i], name) == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}
void printVarArray()
{
    int i;
    printf("VarArray:\n");
    for (i = 0; i < var_count; i++)
    {
        printf("%d: %s\n", i, var_name[i]);
    }
    printf("\n");
}


// GRAPH


void initGraph(){
	g = (AdjGraph*) malloc(sizeof(AdjGraph));
	g->adj = NULL;
	g->vertexCount = 0;
}

void insertEdge(int i, int j){
	
	AdjList *l;
	
	// check if less than zero (constant in operation)
	if(i < 0 || j < 0){
		return;
	}
	
	/* find max */
	int max;
	if(i > j){
		max = i;
	}
	else{
		max = j;
	}

	/* variable count is max + 1 */
	max = max + 1;

	/* manage space */
	if (g->vertexCount == 0){ /* first allocation */
		g->adj = (AdjList**) malloc(max * sizeof(AdjList*));
		g->vertexCount = max;
	}
	else if(g->vertexCount < max){ /* allocate space for more variables */
		g->adj = (AdjList**) realloc(g->adj, max * sizeof(AdjList*));
		g->vertexCount = max;
	}
	
	/* insert edge i-j */
	l = g->adj[i];
	
	while ((l != NULL) && (l->index != j)) l = l->next;
	
	if (l == NULL){
		l = (AdjList*) malloc(sizeof(AdjList));
		l->index = j;
		l->next = g->adj[i];
		g->adj[i] = l;
	}
	
	/* insert edge j-i */
	l = g->adj[j];
	
	while ((l != NULL) && (l->index != i)) l = l->next;
	
	if (l == NULL){
		l = (AdjList*) malloc(sizeof(AdjList));
		l->index = i;
		l->next = g->adj[j];
		g->adj[j] = l;
	}
}

void printGraph(){	
	int i;
	AdjList *l;
	
	printf("AdjGraph:\n");
	for(i = 0 ; i < g->vertexCount; i++){
		printf("%d: ", i);
		l = g->adj[i];
		while(l != NULL){
			printf("%d ", l->index);
			l = l->next;
		}
		printf("\n");
	}
	printf("\n");
}
int *greedyColoring(){
	
	AdjList *l;
	int i;
	
	int V = g->vertexCount;
	
	// color array
	int *colors;
	colors = (int*) malloc(V * sizeof(int));

	// initialize all vertices to '-1', which means unassigned
	for(i = 0; i < V; i++){
		colors[i] = -1;
	}

	// assign first color (0) to first vertex
	colors[0] = 0;

	// boolean array that shows us which colors are still available
	int *available;
	available = (int*) malloc(V * sizeof(int));

	// starting off, all colors are available
	for(i = 0; i < V; i++){
		available[i] = 1;
	}

	// assign colors to the remaining V-1 vertices
	int u;
	for (u = 1; u < V; u++) {
		// process adjacent vertices and flag their colors as unavailable
		l = g->adj[u];
		while (l != NULL) {
			i = l->index;
			if (colors[i] != -1) {
				available[colors[i]] = 0;
			}
			l = l->next;
		}

		// find the first avaiable color
		int cr;
		for (cr = 0; cr < V; cr++) {
			if (available[cr] == 1){
				break;
			}
		}

		// assign the first avaiable color
		colors[u] = cr;

		// reset values back to true for the next iteration
		for(i = 0; i < V; i++){
			available[i] = 1;
		}
	}
	
	return colors;
}