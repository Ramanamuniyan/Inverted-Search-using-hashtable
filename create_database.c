#include "main.h"


int initial_hash(Hash_t **hash)
{

    for(int i=0;i<28;i++)
    {
        hash[i].index=i;
        hash[i].mlink=NULL;
    }

    return SUCCESS;
}


int create_hash(Slist_t *file_list,Hash_t **hash)
{

    while(file_list)
    {

    FILE *file=fopen(file_list->file_name,"r");
    
    if(!file)
    {
    perror("File not fount");
    return FAILURE;
    }

    char buf[20];
    while( fscanf(file,"%s",buf) != EOF)
    {

        int index; // indexing
        if(isalpha(buf[0]))
        index =  toupper(buf[0]) % 65 ;

        if(isdigit(buf[0]))
        index =buf[0] %48;
        else
        index=27;


        createMnodes(hash,buf,index,file_list->file_name);

        


    }

    fclose(file);

    file_list->link;


    }

    return SUCCESS

}


int createMnodes(Hash_t **hash,char *buf,int index,char *file_name)
{

    Main_t *temp=(hash[index])->mlink;
    Main_t *prev=NULL;
    Main_t *mnew=malloc(sizeof(Main_t));
    if(!mnew)
    {
        perror("Main node");
        return FAILURE;
    }

        strcpy(mnew->word,buf);
        // mnew->filecount=1;

        mnew->mlink=NULL;
        mnew->slink=NULL;

        Sub_t *snew=malloc(sizeof(Sub_t));  // create sub node
        if(!snew)
        {
            perror("Sub node failure");
            return FAILURE;
        }
        strcpy(snew->file_name,file_name);   //copying the file name in the sub node 
        snew->slink=NULL;

          //linking snew

    if(! hash[index]->mlink ) // checking the the word to be adddes 
    {

        mnew->filecount=1;
        hash->mlink=mnew;

 
        snew->word_count=1;

        mnew->slink=snew;

    }

    else   // more than one word is present than traverse the main and sub nodes
    {
       
        while(!temp)
        {
            if(strcmp(buf,temp->word) == 0)  //comparing the words while traversing to increase the count 
            {                              //word check
                if(strcmp(file_name, temp->slink->file_name == 0)) //word same, file same
                {
                temp->slink->word_count += 1;
                // temp=temp->mlink

                }
                else //word  same file diff 
                temp->filecount+=1;
            }


             //word diff
            prev = temp;
            temp = temp->mlink;

        }

        mnew->slink=snew;
        prev=mnew;

    }


return SUCCESS;

}


