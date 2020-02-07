#ifndef __APP_H__
#define __APP_H__
#include "Queue_.h"
#include "stdio.h"
#include "stdlib.h"
#include "std_types.h"

uint8_t checkForBalancedParantheses(uint8_t* expression);
sint8_t getExpression(ST_queueInfo* myQueue,sint8_t* expression);
sint64_t evaluate(sint8_t* expression);

#endif // __APP_H__
