#include "queue.h"
#include <stdlib.h>

int queue_init(queue *q, int maxssize)
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

data_t queue_front(queue *q)
{
    if (queue_is_empty(q)) {
        return NULL;
    }
    return q->content[q->front + 1];
}

data_t queue_rear(queue *q)
{
    if (queue_is_empty(q)) {
        return NULL;
    }
    return q->content[q->rear];
}

int queue_is_empty(queue *q)
{
    return q->count == 0;
}

int queue_is_full(queue *q)
{
    return q->count == q->maxsize;
}

int queue_count(queue *q)
{
    return q->count;
}

int queue_enqueue(queue *q, data_t value)
{
    if (queue_is_full(q)) {
        return 0;
    }
    
    q->rear = (q->rear + 1) % q->maxsize;
    q->content[q->rear] = value;
    q->count += 1;
    
    return 1;
}

data_t queue_dequeue(queue *q)
{
    data_t data;
    if (queue_is_empty(q)) {
        return NULL;
    }
    
    q->front = (q->front + 1) % q->maxsize;
    data = q->content[q->front];
    q->count -= 1;
    
    return data;
}
