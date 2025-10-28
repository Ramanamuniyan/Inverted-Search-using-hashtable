#include "main.h"


int main(int argc, char *argv[])
{
    Slist_t *file_list = NULL;

    for (int i = 1; i < argc; i++)
    {
        validate(argv[i], &file_list);
    }


    Hash_t hash[28];
    if(initial_hash(&hash))
    puts("Initialize of hash not done");


    //create data base

    if(create_hash(file_list,&hash))
    puts("Creating hash not done");
    else
    puts("Creating hash not done");

    

    



    return 0;
}