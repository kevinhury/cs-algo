#include "queue.h"
#include <stdlib.h>

int createqueue(queue *q, int maxssize)
{
    data_t *content = malloc(sizeof(data_t) * maxssize);
    if (content == NULL) {
        fprintf(stderr, "Insufficient memory to initialize stack.\n");
        return 0;
    }
    q->content = content;
    q->front = -1;
    q->rear = -1;
    q->count = 0;
    q->maxsize = maxssize;
    
    return 1;
}

data_t front(queue *q)
{
    if (is_empty(q)) {
        return NULL;
    }
    return q->content[q->front + 1];
}

data_t rear(queue *q)
{
    if (is_empty(q)) {
        return NULL;
    }
    return q->content[q->rear];
}

int is_empty(queue *q)
{
    return q->count == 0;
}

int is_full(queue *q)
{
    return q->count == q->maxsize;
}

int count(queue *q)
{
    return q->count;
}

int enqueue(queue *q, data_t value)
{
    if (is_full(q)) {
        return 0;
    }
    
    q->rear = (q->rear + 1) % q->maxsize;
    q->content[q->rear] = value;
    q->count += 1;
    
    return 1;
}

data_t dequeue(queue *q)
{
    data_t data;
    if (is_empty(q)) {
        return NULL;
    }
    
    q->front = (q->front + 1) % q->maxsize;
    data = q->content[q->front];
    q->count -= 1;
    
    return data;
}
