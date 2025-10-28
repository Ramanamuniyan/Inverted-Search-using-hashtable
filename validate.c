#include "main.h"

int insert_last(Slist_t **head, char *data)
{
    if (head == NULL || data == NULL)
        return FAILURE;

    Slist_t *new = malloc(sizeof(Slist_t));
    if (new == NULL)
        return FAILURE;

    new->file_name = strdup(data);  // make a copy of filename
    new->link = NULL;

    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        Slist_t *temp = *head;
        while (temp->link)
            temp = temp->link;

        temp->link = new;
    }

    return SUCCESS;
}

int validate(char *filename, Slist_t **head)
{
    if (filename == NULL || head == NULL)
        return FAILURE;

    if (strstr(filename, ".txt") != NULL)
    {
        if (insert_last(head, filename) == SUCCESS)
        {
            printf("FOUND: %s\n", filename);
            return SUCCESS;
        }
        else
        {
          
            return FAILURE;
        }
    }
    else
    {
        printf("INVALID FILE (not .txt): %s\n", filename);
        return FAILURE;
    }
}
