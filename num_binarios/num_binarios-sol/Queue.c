#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Queue.h"

typedef struct _no {
  char *str;
  struct _no *prox;
} TNo;

struct _queue {
  TNo *inicio;
  TNo *fim;
  unsigned int qty;
};

Queue *Queue_create() {
  Queue *nova = malloc(sizeof(Queue));
  if (nova != NULL) {
    nova->inicio = NULL;
    nova->fim = NULL;
    nova->qty = 0;
  }
  return nova;
}

bool Queue_enqueue(Queue *fila, char *info) {
  if (Queue_is_full(fila))
    return false;
  TNo *novo = calloc(1, sizeof(TNo));
  if (novo == NULL)
    return false;
  novo->str = strdup(info);
  novo->prox = NULL;
  if (Queue_is_empty(fila))
    fila->inicio = novo;
  else
    fila->fim->prox = novo;
  fila->fim = novo;
  fila->qty++;
  return true;
}

bool Queue_dequeue(Queue *fila, char **info) {
  if (Queue_is_empty(fila))
    return false;
  *info = fila->inicio->str;
  TNo *toBeDeleted = fila->inicio;
  fila->inicio = fila->inicio->prox;
  fila->qty--;
  free(toBeDeleted);
  return true;
}

bool Queue_head(Queue *fila, char **info) {
  if (Queue_is_empty(fila))
    return false;
  *info = fila->inicio->str;
  return true;
}

void Queue_destroy(Queue *fila) {
  TNo *aux = fila->inicio, *toBeDeleted;
  while (aux) {
    toBeDeleted = aux;
    aux = aux->prox;
    free(toBeDeleted->str);
    free(toBeDeleted);
  }
  free(fila);
}

unsigned int Queue_size(Queue *fila) { return fila->qty; }

bool Queue_is_empty(Queue *fila) { return fila->qty == 0; }

bool Queue_is_full(Queue *fila) { return false; }