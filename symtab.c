#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantics.h"
#include "symtab.h"

/* current scope */
int cur_scope = 0;

/* flag variable for declaring */
int declare = 0; // 1: declaring variable, 0: not

// Symbol Table Functions

void init_hash_table(){
	int i; 
	hash_table = malloc(SIZE * sizeof(list_t*));
	for(i = 0; i < SIZE; i++) hash_table[i] = NULL;
}

unsigned int hash(char *key){
	unsigned int hashval = 0;
	for(;*key!='\0';key++) hashval += *key;
	hashval += key[0] % 11 + (key[0] << 3) - key[0];
	return hashval % SIZE;
}

void insert(char *name, int len, int type, int lineno){
	unsigned int hashval = hash(name);
	list_t *l = hash_table[hashval];
	
	while ((l != NULL) && (strcmp(name,l->st_name) != 0)) l = l->next;
	
	/* variable not yet in table */
	if (l == NULL){
		/* check if we are really declaring */
		if(declare == 1){
			/* set up entry */
			l = (list_t*) malloc(sizeof(list_t));
			strncpy(l->st_name, name, len);
			l->st_type = type;
			l->scope = cur_scope;
			l->lines = (RefList*) malloc(sizeof(RefList));
			l->lines->lineno = lineno;
			l->lines->next = NULL;
			
			/* add to hashtable */
			l->next = hash_table[hashval];
			hash_table[hashval] = l; 
			printf("Inserted %s for the first time with linenumber %d!\n", name, lineno);
		}
		else{
			/* add it to check it again later */
			l = (list_t*) malloc(sizeof(list_t));
			strncpy(l->st_name, name, len);
			l->st_type = type;
			l->scope = cur_scope;
			l->lines = (RefList*) malloc(sizeof(RefList));
			l->lines->lineno = lineno;
			l->lines->next = NULL;
			l->next = hash_table[hashval];
			hash_table[hashval] = l;
			printf("Inserted %s at line %d to check it again later!\n", name, lineno);
			
			/* Adding identifier to the revisit queue! */
			add_to_queue(l->st_name, PARAM_CHECK);
		}
	}
	/* found in table */
	else{
		// just add line number
		if(declare == 0){
			/* find last reference */
			RefList *t = l->lines;
			while (t->next != NULL) t = t->next;
			
			/* add linenumber to reference list */
			t->next = (RefList*) malloc(sizeof(RefList));
			t->next->lineno = lineno;
			t->next->next = NULL;
			printf("Found %s again at line %d!\n", name, lineno);
		}
		/* new entry */
		else{
			/* same scope - multiple declaration error! */
			if(l->scope == cur_scope){
				fprintf(stderr, "A multiple declaration of variable %s at line %d\n", name, lineno);
 				exit(1);
			}
			/* other scope - create new entry */
			else{
				/* set up entry */
				l = (list_t*) malloc(sizeof(list_t));
				strncpy(l->st_name, name, len);  
				l->st_type = type;
				l->scope = cur_scope;
				l->lines = (RefList*) malloc(sizeof(RefList));
				l->lines->lineno = lineno;
				l->lines->next = NULL;
				
				/* add to hashtable */
				l->next = hash_table[hashval];
				hash_table[hashval] = l; 
				printf("Inserted %s for a new scope with linenumber %d!\n", name, lineno);
			}	
		}		
	}
}

list_t *lookup(char *name){ /* return symbol if found or NULL if not found */
	unsigned int hashval = hash(name);
	list_t *l = hash_table[hashval];
	while ((l != NULL) && (strcmp(name,l->st_name) != 0)) l = l->next;
	return l;
}

void symtab_dump(FILE * of){  /* dump file */
  int i;
  fprintf(of,"------------ -------------- ------ ------------\n");
  fprintf(of,"Name         Type           Scope  Line Numbers\n");
  fprintf(of,"------------ -------------- ------ ------------\n");
  for (i=0; i < SIZE; ++i){ 
	if (hash_table[i] != NULL){ 
		list_t *l = hash_table[i];
		while (l != NULL){ 
			RefList *t = l->lines;
			fprintf(of,"%-13s",l->st_name);
			if (l->st_type == INT_TYPE)                fprintf(of,"%-15s","int");
			else if (l->st_type == REAL_TYPE)          fprintf(of,"%-15s","real");
			else if (l->st_type == CHAR_TYPE)          fprintf(of,"%-15s","char");
			else fprintf(of,"%-15s","undef"); // if UNDEF or 0
			fprintf(of,"  %d  ",l->scope);
			while (t != NULL){
				fprintf(of,"%4d ",t->lineno);
			t = t->next;
			}
			fprintf(of,"\n");
			l = l->next;
		}
    }
  }
}

// Type Functions

void set_type(char *name, int st_type, int inf_type){ // set the type of an entry (declaration)
	/* lookup entry */
	list_t *l = lookup(name);
	
	/* set as "main" type */
	l->st_type = st_type;	
	
	/* if array, pointer or function */
	if(inf_type != UNDEF){
		l->inf_type = inf_type;
	}	
}

int get_type(char *name){ // get the type of an entry
	/* lookup entry */
	list_t *l = lookup(name);
	
	/* if "simple" type */
	if(l->st_type == INT_TYPE || l->st_type == REAL_TYPE || l->st_type == CHAR_TYPE){
		return l->st_type;
	}
	/* if array, pointer or function */
	else{
		return l->inf_type;
	}
}

// Scope Management Functions

void hide_scope(){ /* hide the current scope */
	list_t *l;
	int i;
	printf("Hiding scope \'%d\':\n", cur_scope);
	/* for all the lists */
	for (i = 0; i < SIZE; i++){
		if(hash_table[i] != NULL){
			l = hash_table[i];
			/* Find the first item that is from another scope */
			while(l != NULL && l->scope == cur_scope){
				printf("Hiding %s..\n", l->st_name);
				l = l->next;
			}
			/* Set the list equal to that item */
			hash_table[i] = l;
		}
	}
	cur_scope--;
}

void incr_scope(){ /* go to next scope */
	cur_scope++;
}

// Revisit Queue Functions

void add_to_queue(char *name, int type){ /* add to queue */
	revisit_queue *q;
	
	/* queue is empty */
	if(queue == NULL){
		/* set up entry */
		q = (revisit_queue*) malloc(sizeof(revisit_queue));
		q->st_name = name;
		q->revisit_type = type;
		q->next = NULL;
		
		/* q "becomes" the queue */
		queue = q;
	}
	/* queue not empty */
	else{
		/* find last element */
		q = queue;
		while(q->next != NULL) q = q->next;
		
		/* add element to the end */
		q->next = (revisit_queue*) malloc(sizeof(revisit_queue));
		q->next->st_name = name;
		q->next->revisit_type = type;
		q->next->next = NULL;
	}		
}

int revisit(char *name){ /* revisit entry by also removing it from queue */
	revisit_queue *q;
	
	/* special case - first entry */
	if( strcmp(queue->st_name, name) == 0 ){
		
		/* revisit entry depending on the type */
		switch(queue->revisit_type){
			case PARAM_CHECK:
				/* TO DO: run parameter check */
				break;
			/* ... */
		}
		
		/* remove entry by setting queue to "next" */
		queue = queue->next;
		
		return 0; // success
	}
	
	/* search for the entry that points to it */
	q = queue;
	while( strcmp(q->next->st_name, name) != 0 ) q = q->next;
	
	/* check if entry was not found */
	if(q == NULL){
		return 1;  // not found
	}
	
	/* revisit entry depending on the type */
	switch(q->next->revisit_type){
		case PARAM_CHECK:
			/* TO DO: run parameter check */
			break;
		/* ... */
	}
	
	/* remove entry by making the previous entry point at */
	/* the "next" of the entry that we want to remove  */
	q->next = q->next->next;	
	
	return 0; // success
}

void revisit_dump(FILE *of){
	int i;
	revisit_queue *q;
	q = queue;
	
	fprintf(of,"------------ -------------\n");
	fprintf(of,"Identifier   Revisit Type\n");
	fprintf(of,"------------ -------------\n");
  	while(q != NULL){
  		fprintf(of, "%-13s", q->st_name);
  		if(q->revisit_type == PARAM_CHECK){
  			fprintf(of,"%s","Parameter Check");
		}
		// more later on
		fprintf(of, "\n");
  		q = q->next;	
	}
}