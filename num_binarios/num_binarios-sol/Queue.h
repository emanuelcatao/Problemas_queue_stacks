#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct _queue Queue;

Queue *Queue_create();

bool Queue_enqueue(Queue *, char *);

bool Queue_dequeue(Queue *, char **);

bool Queue_head(Queue *, char **);

void Queue_destroy(Queue *);

unsigned int Queue_size(Queue *);

bool Queue_is_empty(Queue *);

bool Queue_is_full(Queue *);



#endif