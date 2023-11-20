#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula {
    int dado;
    struct celula* prox;
} celula;

int empilha(celula* p, int x) {
    celula* node = malloc(sizeof(celula));
    node->dado = x;
    node->prox = p->prox;
    p->prox = node;
    return 1;
}

int desempilha(celula* p, int* y) {
    if (p == NULL || p->prox == NULL) return 0;

    celula* trash = p->prox;

    *y = p->prox->dado;
    p->prox = p->prox->prox;

    free(trash);
    return 1;
}