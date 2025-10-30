 #include "main.h"

int search(hash_t *hash,char *str)

{

    if(!hash)
    puts("List Empty");
   
    int i= tolower(str[0])%'a';



    // for (int i = 0; i < size; i++)
    // {
        if (hash[i].link != NULL) // if index has data
        {
            main_t *mtemp = (main_t *)hash[i].link; // point to first main node
            while (mtemp) // traverse all main nodes
            {
                if(strcmp(mtemp->word,str)==0)
                {
                if(mtemp->file_count>1)
                printf("%s word is present in  %d files\n",str,mtemp->file_count);
                else
                printf("%s word is present in  %d file\n",str,mtemp->file_count);
                    
                puts("In files :");
                sub_t *stemp = mtemp->s_link; // point to first subnode
                         // flag for first line of word

            
                while (stemp) // traverse all subnodes
                {
                    
                    printf("%-10s %3d time[s]\n",stemp->file_name,stemp->word_count);
                    stemp = stemp->sub_link; // move to next subnode
                }

                }
                mtemp = mtemp->m_link; // move to next main node
            }

           // return SUCCESS;
        }
    // }

    

    printf("%s : word not found\n",str);
    return FAILURE;
    
}