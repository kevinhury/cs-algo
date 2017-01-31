#ifndef LinkedList
#define LinkedList

#include <stdlib.h>
#include <stdio.h>

typedef int data_t;

typedef struct node {
    data_t value;
    struct node *next;
} node;


void print_list(node *head);
void push(node *head, data_t value);
data_t pop(node *head);
data_t remove_first(node **head);
data_t remove_by_index(node **head, int index);
int remove_by_value(node **head, data_t value);

#endif
