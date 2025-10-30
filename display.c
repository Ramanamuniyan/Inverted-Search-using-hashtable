#include "main.h"

void display(hash_t *hash, int size)
{
    printf("[Index]  [Word]     [Filecount] [Filenames]  [Wordcount]\n");

   int flag =1;
    for (int i = 0; i < size; i++)
    {
        if (hash[i].link != NULL)
        {
            flag=0;
            main_t *mtemp = (main_t *)hash[i].link;
            while (mtemp)
            {
                printf("[%-2d]     [%-7s]  [%-2d]        ", i, mtemp->word, mtemp->file_count);

                sub_t *stemp = mtemp->s_link;
                // int total_wordcount = 0;
                // int first = 1;

                while (stemp)
                {
                   
                    printf("[%-7s]       [%-2d]    ", stemp->file_name,stemp->word_count);
                    //total_wordcount += stemp->word_count;
                   // first = 0;
                    stemp = stemp->sub_link;
                }

                printf("\n");

                //printf("]    [%d]\n", total_wordcount);
                mtemp = mtemp->m_link;
            }
        }
    }

    if(flag)
    puts("Hash table is empty ");

    return;

}
