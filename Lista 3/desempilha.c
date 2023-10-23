#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desempilha(celula *p, int *y) {
    if (p->prox == NULL) {
        return 0;
    }

    celula *pi = p->prox; // Nó a ser removido
    *y = pi->dado;
    p->prox = pi->prox;
    free(pi);
    return 1;
}