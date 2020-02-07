#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"

typedef struct ST_queueInfo{
   int* queue_;
   uint32_t queueSize;
   uint32_t start_index;
   uint32_t end_index;
  // uint8_t
}ST_queueInfo;

void createQueue(ST_queueInfo* info, int maxSize);
void enqueue(ST_queueInfo *info, int data);
void dequeue(ST_queueInfo *info, int* data);

int isFullQ(ST_queueInfo *info);
int isEmptyQ(ST_queueInfo *info);
void printQueue(ST_queueInfo *info);


#endif // __QUEUE_H__
