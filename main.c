#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue_.h"
#include "linked_list.h"
#include "App.h"

typedef enum Tests{
    StackTest,QueueTest,BalancedParanthesesTest,EvaluateExpressionTest,LinkedListTest
}Tests;

int main()
{
    Tests Test= LinkedListTest;
    uint8_t val;
    ST_stackInfo  myStack;
    ST_queueInfo myQueue;
    ST_list myList;
    ST_node *output;

    switch(Test){
    case StackTest:
        createStack(&myStack,15);
        push(&myStack,'1');
        push(&myStack,'2');
        push(&myStack,'3');
        push(&myStack,'4');
        push(&myStack,'5');


        printStack(&myStack);

        pop(&myStack,&val);
        pop(&myStack,&val);
        pop(&myStack,&val);

        printStack(&myStack);
        break;
    case BalancedParanthesesTest:
        checkForBalancedParantheses("{}((){[]})");
        break;
    case QueueTest:
         createQueue(&myQueue,5);
         enqueue(&myQueue,1);
         enqueue(&myQueue,2);
         enqueue(&myQueue,3);
         enqueue(&myQueue,4);
         enqueue(&myQueue,5);

         printQueue(&myQueue);

         dequeue(&myQueue,&val);
         dequeue(&myQueue,&val);
         dequeue(&myQueue,&val);

         printQueue(&myQueue);
        break;
    case EvaluateExpressionTest:
        evaluate("(1+2-(4*5))");
        break;
    case LinkedListTest:
        createList(&myList);
        insertToList(&myList,0,1);
        insertToList(&myList,1,2);
        insertToList(&myList,2,3);
        insertToList(&myList,3,4);
        insertToList(&myList,0,5);


        printList(&myList);

        deleteFromList(&myList,1,&val);

        printList(&myList);
        output = searchIntoList(&myList,3);

        printf("\nSearched Value = %d",output->data);

        break;
    }


    /*Stack testing*/


    //int val;

    printf("\n");



    //evaluate("{2}");
    return 0;
}
