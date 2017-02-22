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

data_t extract(node *head)
{
    node *current;
    data_t retval;
    if (head->next != NULL)
    {
        retval = head->value;
        free(head);
        return retval;
    }
    
    current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    
    retval = current->next->value;
    free(current->next);
    current->next = NULL;
    return retval;
}

data_t remove_first(node **head)
{
    node *next;
    data_t retval = 0;
    if (*head == NULL) return retval;
    
    next = (*head)->next;
    next->prev = NULL;
    retval = (*head)->value;
    free(*head);
    *head = next;
    
    return retval;
}

size_t remove_by_value(node **head, data_t value)
{
    size_t retval = 0;
    node *current = *head;
    node *temp = NULL;
    
    if (current->value == value) {
        remove_first(head);
        return retval;
    }
    
    while (current->next->value != value)
    {
        if (current->next == NULL) return -1;
        current = current->next;
        retval++;
    }
    
    current->next->next->prev = current;
    temp = current->next;
    current->next = temp->next;
    free(temp);
    
    return retval;
}

data_t remove_by_index(node **head, size_t index)
{
    size_t i = 0;
    data_t retval = 0;
    node *current = *head;
    node *temp = NULL;
    
    if (index == 0) return remove_first(head);
    
    for (i = 0; i < index - 1; i++)
    {
        if (current->next == NULL) return retval;
        current = current->next;
    }
    
    current->next->next->prev = current;
    temp = current->next;
    retval = temp->value;
    current->next = temp->next;
    free(temp);
    
    return retval;
}

void freelist(node **head)
{
    if (*head == NULL) return;
    freelist(&((*head)->next));
    free(*head);
    *head = NULL;
}
