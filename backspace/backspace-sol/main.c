#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* doBackspace(char *str) {
    Stack *stack = Stack_create();

    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        char caracter = str[i];

        if (caracter == '\n') break;

        if (caracter != '#') {
            Stack_push(stack, caracter);
        } else if (!Stack_is_empty(stack)) {
            int info;
            Stack_pop(stack, &info);
        }
    }

    char* result = Stack_to_string(stack);
    free(stack);
    return result;
}   

int main() {
    char input1[100], input2[100];
    fgets(input1, 100, stdin);
    fgets(input2, 100, stdin);

    char* result1 = doBackspace(input1);
    char* result2 = doBackspace(input2);

    if (strcmp(result1, result2) == 0)
        printf("true\n");
    else
        printf("false\n");

    free(result1);
    free(result2);

    return 0;
}