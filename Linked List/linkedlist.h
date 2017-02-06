#ifndef LinkedList
#define LinkedList

#include <stdlib.h>
#include <stdio.h>

typedef void* data_t;

typedef struct node {
    data_t value;
    struct node *next;
} node;


node *createnode(data_t value);
void iterate(node *head, void (*iterator)(const void *value));
void append(node *head, data_t value);
void prepend(node **head, data_t value);
data_t extract(node *head);
data_t remove_first(node **head);
data_t remove_by_index(node **head, int index);
int remove_by_value(node **head, data_t value);
void freelist(node *head);

#endif
