#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula {
    int dado;
    struct celula* prox;
} celula;

void enfileira(celula** f, int x) {
    celula* nova = malloc(sizeof(celula));
    nova->prox = (*f)->prox;
    (*f)->prox = nova;
    (*f)->dado = x;
    *f = nova;
}

int desenfileira(celula* f, int* y) {
    if (f->prox == f) return 0;

    celula* trash = f->prox;
    *y = f->prox->dado;
    f->prox = f->prox->prox;
    free(trash);
    return 1;
}