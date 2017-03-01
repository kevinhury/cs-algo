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

int stack_init(stack *s, int maxsize);
int stack_push(stack *stack, data_t value);
data_t stack_pop(stack *stack);
data_t stack_peek(stack *stack);
int stack_is_empty(stack *stack);
int stack_is_full(stack *stack);
void stack_iterate(stack *stack, void (*iterator)(const void *value));
void stack_free(stack **s);

#endif
