#include "stack.h"
#include <stdio.h>
#include <string.h>

int doBalance(char *str) {
    Stack *stack = StackCreate();

    char brackets[3][2] = {{'(', ')'},{'[', ']'},{'{', '}'}};

    for (int i = 0; i < 100; i++) {
        char bracket = str[i];
        if (bracket == '\n') break;
        int aberto = 0;

        for (int j = 0; j < 3; j++) {
            if (bracket == brackets[j][0]) {
                push(stack, bracket);
                aberto = 1;
                break;
            }
        }

        if (!aberto) {
            char poppedBracket = pop(stack);
            int EhBracketCorrespondente = 0;

            for (int j = 0; j < 3; j++) {
                if (poppedBracket == brackets[j][0] && bracket == brackets[j][1]) {
                    EhBracketCorrespondente = 1;
                    break;
                }
            }
            if (!EhBracketCorrespondente){
                return 0;
            }
        }
    }
    
    return getTop(stack) == 0;
}

int main() {
    char input[100];
    fgets(input, 100, stdin);

    if(doBalance(input))
        printf("true\n");
    else printf("false\n");

    return 0;
}