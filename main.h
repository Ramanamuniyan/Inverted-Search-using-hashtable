#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1



typedef struct Sub
{
    char file_name[20];
    int word_count;
    struct Sub *slink;

}Sub_t;

typedef struct Main
{
    char word[100];
   struct Main *mlink;
    int filecount;
    struct Sub *slink;

}Main_t;


typedef struct Hash
{

    int index;
   struct Main *mlink;

}Hash_t;

typedef struct Slist
{
    char *file_name;
    struct Slist *link ;
}Slist_t;


int insertlast(Slist_t **list,char *data);

int validate(char *arg,Slist_t **list);


int initial_hash(Hash_t **hash);


int create_hash(Slist_t *file_list,Hash_t **hash);


int createMnodes(Hash_t **hash,char *buf,int index,char *file_name);





#endif