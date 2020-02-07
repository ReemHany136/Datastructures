#include "App.h"
#include "Stack.h"
#include "Queue_.h"

uint8_t checkForBalancedParantheses(uint8_t* expression){
    ST_stackInfo  myStack;
    uint16_t index=0;
    uint8_t val;
    createStack(&myStack,1000);
    while(expression[index]!='\0'){
        if(expression[index] == '(' || expression[index] == '[' || expression[index] == '{')
        {
            push(&myStack,expression[index]);  //
        }
        else{
            if(!isEmpty(&myStack)){
                 if(expression[index]==')'){
                   pop(&myStack,&val);

                    if(val!='('){
                        printf("Unbalanced!\n");
                        return 0;
                    }
                }
                else if(expression[index]==']'){
                    pop(&myStack,&val);
                    if(val!='['){
                        printf("Unbalanced!\n");
                        return 0;
                    }
                }
                 else if(expression[index]=='}'){
                    pop(&myStack,&val);
                    if(val!='{'){
                        printf("Unbalanced!\n");
                        return 0;
                    }
                }
            }
            else{
                if(expression[index]==')'||expression[index]=='}'||expression[index]==']'){
                      printf("Unbalanced!\n");
                      return 0;
                }
            }
        }
        index++;
    }
    if(isEmpty(&myStack)){
        printf("Balanced!\n");
        return 1;
    }
    else{
        printf("Unbalanced!\n");
        return 0;
    }
}
sint8_t getExpression(ST_queueInfo* myQueue,sint8_t* expression){

        uint8_t isOperator = FALSE,isNegative = FALSE,flag=FALSE;
        int value=0,iterator_=0;
        createQueue(myQueue,1000);
        if(expression[0]=='-'){
            isNegative = TRUE;
            iterator_++;
        }
        while(expression[iterator_] != '\0'){
            if(expression[iterator_]>='0' && expression[iterator_]<='9'){
                value *= 10;
                value += (expression[iterator_])-48;
                isOperator=FALSE;

            }
            else if(expression[iterator_] == '+' || expression[iterator_] == '-' || expression[iterator_] == '*' || expression[iterator_] == '/'){
                if(isOperator ==FALSE){
                     if(isNegative==TRUE){

                        value*=-1;

                        isNegative =FALSE;
                    }
                    if(expression[iterator_+1] == '-'){
                        //value*=-1;
                        enqueue(myQueue , value);
                        value = 0;
                        isNegative = TRUE;

                    }
                    else if(expression[iterator_+1] == '\0'|| expression[iterator_+1] == '+' || expression[iterator_+1] == '*' || expression[iterator_+1] == '/'){
                        printf("Syntax Error!\n");
                        return -1;
                    }
                    else{
                        enqueue(myQueue , value);
                        value = 0;

                        isNegative = FALSE;
                    }
                    enqueue(myQueue, expression[iterator_]);
                    isOperator =TRUE;
                }
                else{
                    if(isNegative==FALSE){

                        printf("Syntax Error!\n");
                        return -1;
                    }

                }
            }
           /* else{
                printf("Syntax Error!\n");
                return -1;
            }*/
            iterator_++;
        }
    if(isNegative==TRUE){

        value*=-1;

        isNegative =FALSE;
    }
    enqueue(myQueue,value);
    return 0;
}

sint64_t evaluate(sint8_t* expression){
    if(checkForBalancedParantheses(expression)){
        ST_queueInfo myQueue;
        int val,result=0;
        uint8_t operator_;

        if(!getExpression(&myQueue,expression)){
           // printQueue(&myQueue);

            dequeue(&myQueue,&result);
            //dequeue(&myQueue,&operator_);
          while(!isEmptyQ(&myQueue)){
                dequeue(&myQueue,&val);
                if(val=='+' || val=='-' || val=='*' || val=='/'){
                    operator_ =val;
                }
                else{
                    switch(operator_){
                    case '+':
                        result+=val;
                        break;
                     case '-':
                        result-=val;
                        break;
                     case '*':
                        result*=val;
                        break;
                     case '/':
                        result/=val;
                        break;
                    }
                }
            }
            printf("Result of the expression = %d\n",result);
        }

    }

}
