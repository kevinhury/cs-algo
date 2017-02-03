#include "linkedlist.h"

node *createnode(data_t value)
{
    node *head = malloc(sizeof(node));
    head->next = NULL;
    head->value = value;
    
    return head;
}

void print_list(node *head)
{
    node *current = head;
    
    while (current != NULL)
    {
        printf("%d ", current->value);
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
    
    current->next = malloc(sizeof(node));
    current->next->value = value;
    current->next->next = NULL;
}

void prepend(node **head, data_t value)
{
    node *n = createnode(value);
    n->next = *head;
    *head = n;
}

data_t extract(node *head)
{
    node *current;
    data_t retval;
    if (head->next == NULL)
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
    retval = (*head)->value;
    free(*head);
    *head = next;
    
    return retval;
}

int remove_by_value(node **head, data_t value)
{
    int retval = 0;
    node *current = *head;
    node *temp = NULL;
    
    if (current->value == value) return remove_first(head);
    
    while (current->next->value != value)
    {
        if (current->next == NULL) return -1;
        current = current->next;
        retval++;
    }
    
    temp = current->next;
    current->next = temp->next;
    free(temp);
    
    return retval;
}

data_t remove_by_index(node **head, int index)
{
    int i = 0;
    data_t retval = 0;
    node *current = *head;
    node *temp = NULL;
    
    if (index == 0) return remove_first(head);
    
    for (i = 0; i < index - 1; i++)
    {
        if (current->next == NULL) return retval;
        current = current->next;
    }
    
    temp = current->next;
    retval = temp->value;
    current->next = temp->next;
    free(temp);
    
    return retval;
}

void freelist(node *head)
{
    if (head->next) freelist(head->next);
    free(head);
}
