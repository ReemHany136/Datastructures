#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"

typedef struct ST_stackInfo{
   int* stackPtr;
   uint32_t size;
   uint32_t counter;
}ST_stackInfo;

void createStack(ST_stackInfo *info, int size);
void push(ST_stackInfo *info, int data);
void pop(ST_stackInfo *info, int* data);
int isFull(ST_stackInfo *info);
int isEmpty(ST_stackInfo *info);
void printStack(ST_stackInfo *info);
#endif // __STACK_H__
