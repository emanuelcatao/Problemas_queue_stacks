#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_SIZE 100

typedef struct no {
  int info;
  struct no *prox;
} TNo;

struct stack {
  int qtd;
  TNo *inicio;
};

Stack *Stack_create() {
  Stack *s = calloc(1, sizeof(Stack));
  return s;
}

bool Stack_push(Stack *idk, int info) {
  if (!Stack_is_full(idk)) {
    TNo *novo = calloc(1, sizeof(TNo));
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
    TNo *topo = idk->inicio;
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

char* Stack_to_string(Stack *idk) {
    char *str = malloc((idk->qtd + 1) * sizeof(char));
    if (!Stack_is_empty(idk)) {
        TNo *aux = idk->inicio;
        int cont = 0;
        while (aux != NULL) {
            str[cont] = aux->info;
            aux = aux->prox;
            cont++;
        }
        str[cont] = '\0';
    }
    return str;
}

bool Stack_is_full(Stack *idk) { return false; }

bool Stack_is_empty(Stack *idk) { return (idk->qtd == 0); }

int Stack_size(Stack *idk) { return idk->qtd; }

