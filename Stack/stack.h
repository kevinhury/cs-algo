#ifndef Stack_h
#define Stack_h

#include <stdlib.h>

typedef void* data_t;

typedef struct stack
{
    int top;
    int maxsize;
    data_t *content;
} stack;

int createstack(stack *s, int maxsize);
int push(stack *stack, data_t value);
data_t pop(stack *stack);
data_t peek(stack *stack);
int is_empty(stack *stack);
int is_full(stack *stack);
void iterate_stack(stack *stack, void (*iterator)(const void *value));
void freestack(stack **s);

#endif
