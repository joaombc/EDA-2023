#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) {
        // Não é possível remover o próximo elemento
        return 0;
    }

    celula *proxima = p->prox;
    p->prox = proxima->prox;
    free(proxima);
    return 1;
}

void remove_elemento(celula *le, int x) {
    celula *atual = le;

    while (atual->prox != NULL) {
        if (atual->prox->dado == x) {
            celula *removida = atual->prox;
            atual->prox = removida->prox;
            free(removida);
            return;
        }
        atual = atual->prox;
    }
}

void remove_todos_elementos(celula *le, int x) {
    celula *atual = le;

    while (atual->prox != NULL) {
        if (atual->prox->dado == x) {
            celula *removida = atual->prox;
            atual->prox = removida->prox;
            free(removida);
        } else {
            atual = atual->prox;
        }
    }
}