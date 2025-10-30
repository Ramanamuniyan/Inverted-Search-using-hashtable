#include "main.h"

int main(int argc,char *argv[])
{
    // int size=27;
    hash_t hash[28];
    // Initialize hash table
    for (int i = 0; i < 28; i++)
    {
        hash[i].index = i;
        hash[i].link = NULL;
    }
    

    if(argc <= 1)
    {
        printf("Usage: ./a.out <File.txt>\n");
        return FAILURE;
    }

    file *file_list = NULL;

    for(int i=1;i<argc;i++)
    {
        int len=strlen(argv[i]);
        if(len <= 4 || strcmp(argv[i] + len -4,".txt") != 0)
        {
            printf("Error: It's not valid file\nUsage:<file.txt>\n");
            continue;
        }

        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("Error: File not available\n");
            continue;
        }
        // check if file is empty
        fseek(fp, 0, SEEK_END);
        if (ftell(fp) == 0)
        {
            printf("Error: File is empty\n");
            fclose(fp);
            continue;
        }
        fclose(fp);

        // add valid file to linked list
        if(insert_node(&file_list, argv[i])==NULL)
        {
            printf("\n Duplicate found\n");
        }
    }
    // if no valid files found
    if (file_list == NULL)
    {
        printf("\nNo valid files to store. Exiting...\n");
        return FAILURE;
    }

    printf("\nValid files stored in linked list:\n");
    print_list(file_list);
    

    int choice,flag_create=0;

    do
    {
        printf("\n::: MENU :::\n");
        printf("1. Create_Database\n");
        printf("2. Display_Database\n");
        printf("3. Search\n");
        printf("4. Save\n");
        printf("5. Update_Database\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (!(choice < 9 && choice >0)) 
        break;

        switch (choice)
        {
        case 1:
            if(!flag_create)
            {

                loading();
                if(create(hash, file_list)==SUCCESS)
                    printf("\nDatabase Created Successfull \n");
                else
                    printf("\nDatabase Not Created\n");
            }
            else 
            {
                printf("\nDatabase already created\n");
            }
            flag_create=1;
            break;

        case 2:
            display(hash, 28);
            break;

        case 3:

            char word[20];
            printf("Enter the word: ");
            scanf("%s",word);
            search(hash,word);
            break;
        
        case 4:

            char filename[20];
            
            printf("Enter the Filename :");
            scanf("%s",filename);

            if(!strstr(filename,".txt"))
            strcat(filename,".txt");
           // puts(filename);

            save(hash,28,filename);

            break;

            case 5:

            char str[20];
            printf("Enter the Backup file name :");
            scanf("%s",str);
            if(!strstr(str,".txt"))
            {

                puts("Enter the correct backup.txt");
                //return FAILURE;
                continue;
            }

            update(hash,str);
            break;
        default:
            break;
        }

    } while (choice != 6);
    


    free_filename(file_list);
    free_heap(hash);
    return 0;

}