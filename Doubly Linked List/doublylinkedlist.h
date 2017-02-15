#ifndef doublylinkedlist_h
#define doublylinkedlist_h

#include <stdio.h>

typedef void* data_t;

typedef struct node {
    data_t value;
    struct node *prev;
    struct node *next;
} node;

/**
 * Creates a new (dynamic) linked list node with a given value.
 * The node is dynamically allocated so it needs to be free.
 *
 * @param value The new node's data.
 *
 * @return Pointer to the newly created node.
 */
node *createnode(data_t value);

/**
 * Starts an iteration from a given node in a linked list.
 *
 * @param head The node to start the iteration from.
 * @param iterator A function pointer that gets called every iteration.
 */

void iterate(node *head, void (*iterator)(const void *value));

/**
 * Creates a new node with a given value and attaches it to the rear of the given linked list.
 *
 * @param head The linked list head to append it.
 * @param value The new node's data.
 */

void append(node *head, data_t value);

/**
 * Creates a new node with a given value and attaches it to the front of the given linked list.
 * Modify The given linked list pointer to the newly created node.
 *
 * @param head The linked list head pointer to prepend it to.
 * @param value The new node's data.
 */
void prepend(node **head, data_t value);

/**
 * Extracts the last node in a the given linked list.
 * The last node gets free after the operation is finished.
 *
 * @param head The head of the linked list.
 *
 * @return The data of the last node.
 */
data_t extract(node *head);

/**
 * Extracts the first node in a the given linked list.
 * The first node gets free after the operation is finished.
 * The head pointer changes to the next node, or NULL if the linked list is empty.
 *
 * @param head The head of the linked list.
 *
 * @return The data of the first node.
 */
data_t remove_first(node **head);

/**
 * Removes a node by a given index in the the given linked list.
 * The node gets free after the operation is finished.
 * The pointer changes to the next node, or NULL if the linked list is empty.
 *
 * @param head The head of the linked list.
 * @param index The index to remove from the linked list.
 *
 * @return The data of the removed node.
 */
data_t remove_by_index(node **head, int index);

/**
 * Removes a node by a given value in the the given linked list.
 * The node gets free after the operation is finished.
 * The pointer changes to the next node, or NULL if the linked list is empty.
 *
 * @param head The head of the linked list.
 * @param value The value to remove from the linked list.
 *
 * @return The index of the removed node.
 */
int remove_by_value(node **head, data_t value);

/**
 * Frees the given linked list and modify the list's pointer to NULL.
 *
 * @param head Pointer to the list.
 */
void freelist(node **head);

#endif /* doublylinkedlist_h */
