#include  "main.h"

int save(hash_t *hash,int size, char *file)
{

    FILE *filename=fopen(file,"w");
    if(!filename)
    {
        perror("");
        return FAILURE;
    }
    
    for (int i = 0; i < size; i++)
    {
        if (hash[i].link != NULL) // if index has data
        {
            main_t *mtemp = (main_t *)hash[i].link; // point to first main node
            while (mtemp) // traverse all main nodes
            {
                sub_t *stemp = mtemp->s_link; // point to first subnode
               // int first = 1; // flag for first line of word
                fprintf(filename,"#%d;%s;%d;", i, mtemp->word, mtemp->file_count);
                while (stemp) // traverse all subnodes
                {  
                        // Print
                        fprintf(filename,"%s;%d;", stemp->file_name, stemp->word_count); 
                        stemp = stemp->sub_link; // move to next subnode
                }
                fprintf(filename,"#\n");
                mtemp = mtemp->m_link; // move to next main node
            }
        }
    }
    return SUCCESS;
}
