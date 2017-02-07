#include "stack.h"
#include "stdio.h"

int createstack(stack *s, int maxsize)
{
    data_t *content = malloc(sizeof(data_t) * maxsize);
    if (content == NULL) {
        fprintf(stderr, "Insufficient memory to initialize stack.\n");
        return 0;
    }
    s->content = content;
    s->top = -1;
    s->maxsize = maxsize;
    
    return 1;
}

int push(stack *stack, data_t value)
{
    if (is_full(stack)) {
        return 0;
    }
    
    stack->top++;
    stack->content[stack->top] = value;
    
    return 1;
}

data_t pop(stack *stack)
{
    data_t data;
    if (is_empty(stack)) {
        return NULL;
    }
    
    data = stack->content[stack->top];
    stack->top--;
    
    return data;
}

data_t peek(stack *stack)
{
    if (is_empty(stack)) {
        return NULL;
    }
    return stack->content[stack->top];
}


int is_empty(stack *stack)
{
    return stack->top == -1;
}

int is_full(stack *stack)
{
    return stack->top == stack->maxsize - 1;
}

void iterate_stack(stack *stack, void (*iterator)(const void *value))
{
    int i = 0;
    for (i = 0; i <= stack->top; i++) {
        iterator(stack->content[i]);
    }
}

void freestack(stack **s)
{
    free(*s);
    *s = NULL;
}
