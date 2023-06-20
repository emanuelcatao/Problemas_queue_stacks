#include "Queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void concatenarCaracteres(char* str, char c) {
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    str[i] = c;
    str[i + 1] = '\0';
}

void generate(int n) {
  Queue *queue = Queue_create();
  Queue_enqueue(queue, "1");

  char *front, *copy, *copy1;
  for(int i = 0; i < n; i++) {
    Queue_dequeue(queue, &front);

    copy = strdup(front);
    copy1 = strdup(front);
    concatenarCaracteres(copy1, '0');
    concatenarCaracteres(copy, '1');
    Queue_enqueue(queue, copy1);
    Queue_enqueue(queue, copy);

    printf("%s ", front);

    free(front);
  }

  Queue_destroy(queue);
}


int main(void) {
  int n;
  scanf("%d", &n);
  generate(n);
  printf("\n");

  return 0;
}