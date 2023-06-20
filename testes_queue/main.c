#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
  int info;
  struct _no *prox;
} TNo;
struct _queue {
  TNo *inicio;
  TNo *fim;
  unsigned int qty;
};

typedef struct _queue Queue;

Queue *Queue_create() {
  Queue *nova = malloc(sizeof(Queue));
  if (nova != NULL) {
    nova->inicio = NULL;
    nova->fim = NULL;
    nova->qty = 0;
  }
  return nova;
}

bool Queue_is_empty(Queue *fila) { return fila->qty == 0; }

bool Queue_is_full(Queue *fila) { return false; }

bool Queue_enqueue(Queue *fila, int info) {
  if (Queue_is_full(fila))
    return false;
  TNo *novo = calloc(1, sizeof(TNo));
  if (novo == NULL)
    return false;
  novo->info = info;
  novo->prox = NULL;
  if (Queue_is_empty(fila))
    fila->inicio = novo;
  else
    fila->fim->prox = novo;
  fila->fim = novo;
  fila->qty++;
  return true;
}

bool Queue_dequeue(Queue *fila, int *info) {
  if (Queue_is_empty(fila))
    return false;
  *info = fila->inicio->info;
  TNo *toBeDeleted = fila->inicio;
  fila->inicio = fila->inicio->prox;
  fila->qty--;
  free(toBeDeleted);
  return true;
}

bool Queue_head(Queue *fila, int *info) {
  if (Queue_is_empty(fila))
    return false;
  *info = fila->inicio->info;
  return true;
}

void Queue_destroy(Queue *fila) {
  TNo *aux = fila->inicio, *toBeDeleted;
  while (aux) {
    toBeDeleted = aux;
    aux = aux->prox;
    free(aux);
  }
  free(fila);
}

unsigned int Queue_size(Queue *fila) { return fila->qty; }

typedef struct no {
  int info;
  struct no *prox;
} TSNo;

struct stack {
  int qtd;
  TSNo *inicio;
};

typedef struct stack Stack;

Stack *Stack_create() {
  Stack *s = calloc(1, sizeof(Stack));
  return s;
}

bool Stack_is_full(Stack *idk) { return false; }

bool Stack_is_empty(Stack *idk) { return (idk->qtd == 0); }

bool Stack_push(Stack *idk, int info) {
  if (!Stack_is_full(idk)) {
    TSNo *novo = calloc(1, sizeof(TSNo));
    if (novo != NULL) {
      novo->info = info;
      novo->prox = idk->inicio;
      idk->inicio = novo;
      idk->qtd++;
      return true;
    }
  }
  return false;
}

bool Stack_pop(Stack *idk, int *info) {
  if (!Stack_is_empty(idk)) {
    TSNo *topo = idk->inicio;
    *info = topo->info;
    idk->qtd--;
    idk->inicio = topo->prox;
    free(topo);
    return true;
  }
  return false;
}

bool Stack_head(Stack *idk, int *info) {
  if (!Stack_is_empty(idk)) {
    int topo = idk->inicio->info;
    *info = topo;
    return true;
  }
  return false;
}

int Stack_size(Stack *idk) { return idk->qtd; }

void Stack_destroy(Stack *pilha) {
  if (pilha != NULL) {
    int temp;
    while (Stack_pop(pilha, &temp))
      ;
    free(pilha);
  }
}


void ex_5_concatenate(Queue* fila1, Queue* fila2)
{
  int temp;
  while(Queue_dequeue(fila2, &temp))
    Queue_enqueue(fila1, temp);
}

void ex_6_reverse(Queue *fila) {
  Stack *aux = Stack_create();
  int temp;
  while (Queue_dequeue(fila, &temp))
    Stack_push(aux, temp);

  while (Stack_pop(aux, &temp))
    Queue_enqueue(fila, temp);
  Stack_destroy(aux);
}

void print_queue(Queue *fila) {
  Queue *fila_aux = Queue_create();
  int temp;
  while (Queue_dequeue(fila, &temp)) {
    printf("%d, ", temp);
    Queue_enqueue(fila_aux, temp);
  }
  while (Queue_dequeue(fila_aux, &temp))
    Queue_enqueue(fila, temp);
  Queue_destroy(fila_aux);
  putchar('\n');
}

int main(void) {
  int temp;
  Queue *fila = Queue_create();
  for (int i = 0; i < 12; i++) {
    if (!Queue_enqueue(fila, i))
      printf("Fila cheia ao tentar inserir %d\n", i);
  }

  Queue *fila2 = Queue_create();
  for (int i = 12; i <= 16; i++) {
    if (!Queue_enqueue(fila2, i))
      printf("Fila cheia ao tentar inserir %d\n", i);
  }
  //print_queue(fila);
  //ex_6_reverse(fila);
  puts("Fila1:");
  print_queue(fila);
  puts("Fila2:");
  print_queue(fila2);
  ex_5_concatenate(fila, fila2);
  puts("Fila1:");
  print_queue(fila);
  puts("Fila2:");
  print_queue(fila2);
  

  return 0;
}