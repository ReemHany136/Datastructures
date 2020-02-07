#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"

typedef struct ST_node{
    struct ST_node* nxtptr;
    int data;
    int position;
}ST_node;
typedef struct ST_list{
    int counter;
    ST_node* Headptr;
}ST_list;



char createList(ST_list *list);
void insertToList(ST_list *listHead, unsigned char position, int data);
void printList(ST_list *listHead);
void deleteFromList(ST_list *listHead, unsigned char position, int* data);
ST_node* searchIntoList(ST_list *listHead, int data);


#endif // __LINKED_LIST_H__
