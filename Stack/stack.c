#include "stack.h"

stack *createstack()
{
    stack *s = malloc(sizeof(stack));
    s->top = 0;
    return s;
}

int push(stack *stack, data_t value)
{
    if (is_full(stack)) {
        return 0;
    }
    
    stack->top++;
    stack->_stack[stack->top] = value;
    
    return 1;
}

data_t pop(stack *stack)
{
    data_t data;
    if (is_empty(stack)) {
        return NULL;
    }
    
    data = stack->_stack[stack->top];
    stack->top--;
    
    return data;
}

data_t peek(stack *stack)
{
    return stack->_stack[stack->top];
}


int is_empty(stack *stack)
{
    return stack->top == -1;
}

int is_full(stack *stack)
{
    return stack->top == MAX_SIZE;
}

void freestack(stack **s)
{
    free(*s);
    *s = NULL;
}
