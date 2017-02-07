#ifndef Stack_h
#define Stack_h

#include <stdlib.h>

#define MAX_SIZE 10
typedef void* data_t;

typedef struct stack
{
    int top;
    data_t _stack[MAX_SIZE];
} stack;

stack *createstack();
int push(stack *stack, data_t value);
data_t pop(stack *stack);
data_t peek(stack *stack);
int is_empty(stack *stack);
int is_full(stack *stack);

#endif
