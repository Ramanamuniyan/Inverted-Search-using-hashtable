#include "main.h"

sub_t *create_sub(char *filename)
{
    sub_t *s_new=malloc(sizeof(sub_t));
    if (s_new == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(s_new->file_name, filename);

    
    s_new->word_count=1;
    s_new->sub_link=NULL;
    return s_new;
}

main_t *create_main(char *word, char *filename)
{
    main_t *m_new=malloc(sizeof(main_t));
    if (m_new == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(m_new->word, word);
    m_new->file_count=1;
    m_new->m_link=NULL;
    m_new->s_link=create_sub(filename);
    return m_new;
    
}

int create(hash_t *hash,file *file_list)
{
    file *fileptr=file_list;
    while(fileptr)
    {
        FILE *fptr=fopen(fileptr->f_name,"r");
        if(!fptr)
        {
            printf("File '%s' not found\n", fileptr->f_name);
            fileptr = fileptr->link;
            continue;
        }
        
        char word[100];
        while (fscanf(fptr, "%99s", word) == 1)
        {
            // read the content word by word
            int index;

            if (isalpha(word[0]))
                index = tolower(word[0]) - 'a';
            else if (isdigit(word[0]))
                index = 26;
            else
                index = 27;


            main_t *m_temp= (main_t *)hash[index].link;
          //  main_t *m_prev;
            int word_found=0;
            // searching word in main node
            while (m_temp != NULL)
            {
                if(strcmp(m_temp->word,word) == 0)
                {
                    word_found=1;
                    break;
                }
               // m_prev=m_temp;
                m_temp=m_temp->m_link;
            }
            //found word, check sub node
            if(word_found)
            {
                sub_t *s_temp=m_temp->s_link;
                sub_t *s_prev=NULL;
                int file_found=0;
                while (s_temp != NULL)
                {
                    if(strcmp(s_temp->file_name,fileptr->f_name)==0)
                    {
                        s_temp->word_count++;
                        file_found=1;
                        break;
                    }
                    s_prev=s_temp;
                    s_temp=s_temp->sub_link;
                }
                // file not found,add new sub node
                if(!file_found)
                {
                    sub_t *new_sub=create_sub(fileptr->f_name);
                    if(!new_sub)
                    {
                        fclose(fptr);
                        return FAILURE;;
                    }
                    s_prev->sub_link=new_sub;
                    m_temp->file_count++;
                }
            }
            else
            {
                // word not found,create main node
                main_t *new_main = create_main(word, fileptr->f_name);
                if (!new_main)
                {
                    fclose(fptr);
                    return FAILURE;
                }

                // Insert new main node at beginning of hash[index]
                new_main->m_link = (main_t *) hash[index].link;
                hash[index].link = (hash_t *)new_main;
            }    
                    
        }
        printf("%s - file created\n",fileptr->f_name);
        fclose(fptr);
        fileptr = fileptr->link;
        
    }
    // printf("\nDatabase Created\n");
    return SUCCESS;
}
    
    



