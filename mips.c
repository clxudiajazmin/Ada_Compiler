#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mips.h"
#include "semantics.h"
#include "symtab.c"

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