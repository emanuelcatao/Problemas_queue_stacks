#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "StackQueue.h"

typedef struct _no {
  int info;
  struct _no *prox;
} TNo;

struct _STqueue {
  TNo *inicio;
  TNo *fim;
  unsigned int qty;
};

//aux
int _Queue_dequeue(Queue *fila, int *info);

Queue *Queue_create() {
  Queue *nova = malloc(sizeof(Queue));
  if (nova != NULL) {
    nova->inicio = NULL;
    nova->fim = NULL;
    nova->qty = 0;
  }
  return nova;
}

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

int Queue_dequeue(Queue *fila) {
  if (Queue_is_empty(fila))
    return 0;

  int data;
  for(int i =0; i < fila->qty - 1; i++) {
    _Queue_dequeue(fila, &data);
    Queue_enqueue(fila, data);
  }
  _Queue_dequeue(fila, &data);
  return data;
}

int _Queue_dequeue(Queue *fila, int *info) {
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

void Queue_print(Queue *idk) {
  if (!Queue_is_empty(idk)) {
    TNo *aux = idk->inicio;
    while (aux->prox != NULL) {
      printf("%d - ", aux->info);
      aux = aux->prox;
    }
    printf("%d\n", aux->info);
  }
}

unsigned int Queue_size(Queue *fila) { return fila->qty; }

bool Queue_is_empty(Queue *fila) { return fila->qty == 0; }

bool Queue_is_full(Queue *fila) { return false; }

