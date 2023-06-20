#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct no {
  int info;
  struct no *prox;
} TNo;

struct stack {
  int qtd;
  TNo *inicio;
};

///////////////////////////////// < O que vai no stack.h >
typedef struct stack Stack;

Stack *Stack_create();
bool Stack_push(Stack *, int);
bool Stack_pop(Stack *, int *);
bool Stack_head(Stack *, int *);
bool Stack_is_full(Stack *);
bool Stack_is_empty(Stack *);
int Stack_size(Stack *);

/////////////////////////////////

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

bool Stack_is_full(Stack *idk) { return false; }

bool Stack_is_empty(Stack *idk) { return (idk->qtd == 0); }

int Stack_size(Stack *idk) { return idk->qtd; }


int main(void) {
  int temp;
  Stack *piula1 = Stack_create();
  for(int i=0; i<12; i++){
    if(!Stack_push(piula1, i))
      printf("Stack overflow ao tentar inserir %d\n", i);
  }
  while(Stack_pop(piula1, &temp))
      printf("Valor removido: %d\n", temp);
  return 0;
}