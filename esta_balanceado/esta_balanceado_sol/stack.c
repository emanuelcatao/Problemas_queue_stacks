#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_SIZE 100

struct stack {
    char data[MAX_SIZE];
    int top;
};

Stack *StackCreate(){
    Stack *s = calloc(1, sizeof(Stack));
    return s;
}

void push(Stack *stack, char element) {
    stack->data[stack->top] = element;
    stack->top++;
}

char pop(Stack *stack) {
    if (stack->top == 0)
        return '\0';
    stack->top--;
    return stack->data[stack->top];
}

int getTop(Stack *stack) {
    return stack->top;
}

