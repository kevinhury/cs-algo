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


int queue_create(queue *q, int maxssize);
data_t queue_front(queue *q);
data_t queue_rear(queue *q);
int queue_is_empty(queue *q);
int queue_is_full(queue *q);
int queue_count(queue *q);
int queue_enqueue(queue *q, data_t value);
data_t queue_dequeue(queue *q);
void queue_destroy(queue **q);

#endif /* queue_h */
