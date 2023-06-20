#include "StackQueue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  Queue *queue = Queue_create();

	int value, index = 0;
	char command;
    while (1) {
        command = getchar();
        if (command == '0') {
            break;
        } else if (command == 'e') {
            scanf("%*s %d", &value);
            Queue_enqueue(queue, value);
            index++;
        } else if (command == 'd') {
					scanf("%*s");
          Queue_dequeue(queue);
        }
    }
  Queue_print(queue);
  return 0;
}