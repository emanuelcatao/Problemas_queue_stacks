#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct stack Stack;

Stack *Stack_create();

bool Stack_push(Stack *, int);

bool Stack_pop(Stack *, int *);

bool Stack_head(Stack *, int *);

bool Stack_is_full(Stack *);

bool Stack_is_empty(Stack *);

char* Stack_to_string(Stack *);

int Stack_size(Stack *);
#endif