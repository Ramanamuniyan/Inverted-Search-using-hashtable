#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SUCCESS 0
#define FAILURE -1


typedef struct hash_hash
{
    int index;
    struct hash_hash *link;
}hash_t;

typedef struct file_node
{
    char f_name[100];              
    struct file_node *link;        // Pointer to next file node
}file;

typedef struct main_node
{
    char word[100];
    int file_count;
    struct main_node *m_link;
    struct sub_node *s_link;
}main_t;

typedef struct sub_node
{
    char file_name[100];
    int word_count;
    struct sub_node *sub_link;
}sub_t;

void loading();
int create(hash_t *hash,file *file_list);

int search(hash_t *hash,char *str);

void display(hash_t *hash, int size);

int save(hash_t *hash,int size, char *file);
int update(hash_t *hash,char *str);



file *insert_node(file **head, char *filename);

void print_list(file *head);

sub_t *create_sub(char *filename);
main_t *create_main(char *word, char *filename);

void free_sub(sub_t *sub);
void free_main(main_t *main);

void free_heap(hash_t *);
void free_filename(file *temp);

#endif
