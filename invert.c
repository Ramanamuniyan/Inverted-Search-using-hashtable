#include "main.h"

file *insert_node(file **head, char *filename)
{
    file *new=malloc(sizeof(file));
    if(new == NULL)
    {
        printf("\nMemory allocation failed\n");
        return NULL;
    }
    strcpy(new->f_name,filename);
    new->link=NULL;

    if(*head == NULL)
    {
        *head = new;
        return new;
    }
    
    file *temp=*head;
    file *prev=NULL;
    while (temp != NULL)
    {
        if(strcmp(temp->f_name,filename)==0)
        {
            free(new);
            return *head;
        }
        prev=temp;
        temp=temp->link;
    }
    prev->link=new;
    return *head;
}

void print_list(file *head)
{
    while (head)
    {
        printf("%s\n", head->f_name);
        head = head->link;
    }
}

void loading()
{
    for(int i=0;i<=100;i++)
    {
        printf("Loading...........%d\r",i);
        fflush(stdout);
        usleep(15555);
    }
    return;
}

void free_sub(sub_t *sub)
{
    if(sub)
    {
        free_sub(sub->sub_link);
        free(sub);
    }

}

void free_main(main_t *maint)
{

    if(maint)
    {
    free_main(maint->m_link);
    free_sub(maint->s_link);
    free(maint);

    }
}

void free_heap(hash_t *hash)
{

    for(int i=0;i<28;i++)
    {
       main_t *temp= (main_t *)hash[i].link;
        if(temp)
        {
            free_main(temp);
            temp = NULL;  // avoid dangling pointer
        }

    }
}

void free_filename(file *temp)
{


    if(temp)
    {
        free_filename(temp->link);
        free(temp);
       
    }
     temp=NULL;
}
