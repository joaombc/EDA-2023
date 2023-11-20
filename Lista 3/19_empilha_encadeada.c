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