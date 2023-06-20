#ifndef STACKQUEUE_H
#define STACKQUEUE_H
#include <stdbool.h>

typedef struct _STqueue Queue;

Queue *Queue_create();

bool Queue_enqueue(Queue *, int);

int Queue_dequeue(Queue *);

bool Queue_head(Queue *, int *);

void Queue_destroy(Queue *);

unsigned int Queue_size(Queue *);

bool Queue_is_empty(Queue *);

bool Queue_is_full(Queue *);

void Queue_print(Queue *);

#endif