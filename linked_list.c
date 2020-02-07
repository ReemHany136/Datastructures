#include "linked_list.h"

char createList(ST_list *list){
    list->Headptr = NULL;
}
void insertToList(ST_list *listHead, unsigned char position, int data){

    ST_node * InsertedNode=(ST_node*) malloc(sizeof(ST_node));

    if(InsertedNode!=NULL){
        InsertedNode->data = data;

        if(position == 0){
           if(listHead->Headptr == NULL){
               listHead->Headptr = InsertedNode;
                listHead->Headptr->nxtptr=NULL;
            }
            else{
                InsertedNode->nxtptr = listHead->Headptr;
                listHead->Headptr=InsertedNode;
            }
        }
        else{

            int List_position_counter=1;
            ST_node  *temp =listHead->Headptr;
            while( temp != NULL){
                if(List_position_counter == position){
                    if(position == 1){
                        InsertedNode->nxtptr=listHead->Headptr->nxtptr;
                        listHead->Headptr->nxtptr=InsertedNode;
                    }
                    else{
                        InsertedNode->nxtptr=temp->nxtptr;
                        temp->nxtptr = InsertedNode;
                    }

                   break;
                }
                List_position_counter++;
                temp = temp->nxtptr;

            }
        }
    }

}
void deleteFromList(ST_list *listHead, unsigned char position, int* data){
   if(position == 0){
        (*data) =  listHead->Headptr->data;
        listHead->Headptr=listHead->Headptr->nxtptr;
   }
   else{
        int List_position_counter=0;

        ST_node * currentNode = listHead->Headptr,* prevptr = listHead->Headptr;
        while(currentNode!=NULL){//printf("position=%d\n",List_position_counter);
            if(List_position_counter==position){

                (*data) =  currentNode->data;
                prevptr->nxtptr=currentNode->nxtptr;
            }
            prevptr=currentNode;
            currentNode=currentNode->nxtptr;
            List_position_counter++;
        }
   }
}
ST_node* searchIntoList(ST_list *listHead, int data){
     ST_node * currentNode = listHead->Headptr;
     while(currentNode!=NULL){
        if(currentNode->data == data){
            break;
        }
         currentNode=currentNode->nxtptr;
     }
     return currentNode;
}
void printList(ST_list *listHead){
    ST_node * currentPtr=listHead->Headptr;
     printf("**__Linked List__**\n");
    int position=0;
    while(currentPtr!=NULL){
        printf("Element No.%d: %d\n",position,currentPtr->data);
        currentPtr = currentPtr->nxtptr;
        position++;
    }
    printf("\n");
}
