#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack *StackCreate();

void init(Stack *);

char pop(Stack *);

void push(Stack *, char);

int getTop(Stack *);

#endif