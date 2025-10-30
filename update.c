#include "main.h"

int update(hash_t *hash, char *str)
{
    FILE *file = fopen(str, "r");
    if (!file)
    {
        perror("File open failed");
        return FAILURE;
    }

    char buff[200];

    while (fgets(buff, sizeof(buff), file))
    {
        if (buff[0] != '#')
        {
            puts("Invalid backup file format");
            fclose(file);
            return FAILURE;
        }

        int index = -1, filecount = 0, wordcount = 0;
        char word[20], filename[20];

        // Read first 1 filename and count
        sscanf(buff, "#%d;%19[^;];%d;%19[^;];%d;", &index, word, &filecount, filename, &wordcount);

        //printf("%d %s %d %s %d\n", index, word, filecount, filename, wordcount);

        // Create main node
        hash[index].link = (hash_t *) create_main(word, filename);
        main_t *temp = (main_t *)hash[index].link;
        temp->s_link->word_count = wordcount;

        // If more files exist
        if (filecount > 1)
        {
            // Find position after 1st filename & wordcount
            char *ptr = strchr(buff, ';'); // after index
            ptr = strchr(ptr + 1, ';');    // after word
            ptr = strchr(ptr + 1, ';');    // after filecount
            ptr = strchr(ptr + 1, ';');    // after first filename
            ptr = strchr(ptr + 1, ';');    // after first wordcount
            ptr++;                         // now points to second filename

            for (int i = 1; i < filecount; i++)
            {
                if (sscanf(ptr, "%19[^;];%d;", filename, &wordcount) != 2)
                    break;

                sub_t *new = create_sub(filename);
                new->word_count = wordcount;

                // Insert at first
                new->sub_link = temp->s_link;
                temp->s_link = new;

                // move ptr to next filename pair
                char *next = strchr(ptr, ';'); // after filename
                if (!next)
                    break;
                next = strchr(next + 1, ';'); // after wordcount
                if (!next)
                    break;
                ptr = next + 1;
            }
        }
    }

    fclose(file);
    return SUCCESS;
}
