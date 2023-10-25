#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula {
    int dado;
    struct celula* prox;
} celula;



int enfileira(celula* f, int x) {
    celula* nova = malloc(sizeof(celula));
    if (nova == NULL) return NULL;

    nova->prox = f->prox;
    f->prox = nova;
    f->dado = x;
    return nova;
}