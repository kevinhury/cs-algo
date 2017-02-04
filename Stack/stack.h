#ifndef Stack_h
#define Stack_h

#include <stdio.h>

#define MAX_SIZE 10
typedef int data_t;

typedef struct stack
{
    data_t _stack[MAX_SIZE];
    data_t top;
} stack;


int push(stack *stack, data_t value);
data_t pop(stack *stack);
data_t peek(stack *stack);
int is_empty(stack *stack);
int is_full(stack *stack);

#endif
