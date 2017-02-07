#ifndef queue_h
#define queue_h

#include <stdio.h>

typedef void* data_t;

typedef struct queue
{
    int front, rear;
    int count, maxsize;
    data_t *content;
} queue;


int createqueue(queue *q, int maxssize);
data_t front(queue *q);
data_t rear(queue *q);
int is_empty(queue *q);
int is_full(queue *q);
int contains(queue *q);
int size(queue *q);
int enqueue(queue *q, data_t value);
data_t dequeue(queue *q);

#endif /* queue_h */
