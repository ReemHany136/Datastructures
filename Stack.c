
#include "Stack.h"

void createStack(ST_stackInfo *info, int size){

    info->stackPtr = (int*)malloc(size*sizeof(int));
    info->size = size;
    info->counter=0;
}
void push(ST_stackInfo *info, int data){
    if((isFull(info))==0){

        info->stackPtr[info->counter++] = data;

     //   info->stackPtr++;
   //     info->counter++;
    }

}
void pop(ST_stackInfo *info, int* data){
    int* ptr = info->stackPtr;

    if(!(isEmpty(info))){

        (info->counter)--;

        *((char*)data) = (ptr[info->counter]);
    }

   // info->counter--;
}
int isFull(ST_stackInfo *info){
    if(info->counter < info->size)
        return 0;
    else
        return 1;
}
int isEmpty(ST_stackInfo *info){
    if(info->counter>0)
        return 0;
    else
        return 1;
}

void printStack(ST_stackInfo *info){
    uint32_t iterator_=0;
    printf("**__Stack__**\n");
    for(iterator_ = 0; iterator_< info->counter ;iterator_++){
        printf("Element no.%d : %c\n",iterator_,info->stackPtr[iterator_]);
    }
    printf("\n");
}
