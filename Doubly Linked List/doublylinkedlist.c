#include "doublylinkedlist.h"
#include <stdlib.h>

node *createnode(data_t value)
{
    node *head = malloc(sizeof(node));
    head->prev = NULL;
    head->next = NULL;
    head->value = value;
    
    return head;
}

void iterate(node *head, void (*iterator)(const void *value))
{
    node *current = head;
    while (current != NULL)
    {
        iterator(current->value);
        current = current->next;
    }
}

void append(node *head, data_t value)
{
    node *current = head;
    
    while (current->next != NULL)
    {
        current = current->next;
    }
    
    current->next = createnode(value);
    current->next->prev = current;
}

void prepend(node **head, data_t value)
{
    node *n = createnode(value);
    n->next = *head;
    (*head)->prev = n;
    *head = n;
}
