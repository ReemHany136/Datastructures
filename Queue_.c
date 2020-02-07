#include "Queue_.h"
#include "math.h"

uint8_t isRotated = FALSE;

void createQueue(ST_queueInfo* info, int maxSize){
    info->queue_ = (int*)malloc(maxSize*sizeof(int));
    info->queueSize = maxSize;
    info->start_index=0;
    info->end_index=0;
}
void enqueue(ST_queueInfo *info, int data){
    if(!isFullQ(info)){
       // printf("\nQueue=%d  %c\n",data,data);
        info->queue_[info->end_index] = data;
        info->end_index++;
        if(info->end_index == info->queueSize){
            info->end_index = 0;
            isRotated = TRUE;
        }
    }
}
void dequeue(ST_queueInfo *info, int* data){
    if(!isEmptyQ(info)){
        *(data) = info->queue_[info->start_index];
        info->start_index++;
        if(info->start_index == info->queueSize){
            info->start_index = 0;
             isRotated = FALSE;
        }
    }
}
int isFullQ(ST_queueInfo *info){
    int no_Of_elements = abs(info->end_index - info->start_index);
    if(no_Of_elements == 0 && isRotated == TRUE){
        return 1;
    }
    return 0;
}
int isEmptyQ(ST_queueInfo *info){
    int no_Of_elements = abs(info->end_index - info->start_index);
    if(no_Of_elements == 0 && isRotated == FALSE){
        return 1;
    }
    return 0;
}
void printQueue(ST_queueInfo *info){
    uint32_t start=info->start_index , end = info->end_index;
     printf("**__Queue__**\n");
    if(!isFullQ(info)){
        while(start!=end){
            printf("Index No.%d: %d\n",start,info->queue_[start]);
            start++;
            if(start == info->queueSize){
                start=0;
            }
        }
        printf("\n");
    }
    else{
        printf("Index No.%d: %d\n",start,info->queue_[start]);
        start++;
        if(start == info->queueSize){
            start=0;
        }
         while(start!=end){
            printf("Index No.%d: %d\n",start,info->queue_[start]);
            start++;
            if(start == info->queueSize){
                start=0;
            }
        }
        printf("\n");
    }
   // else

}
