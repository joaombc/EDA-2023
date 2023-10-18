#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função iterativa para imprimir a lista encadeada
void imprime(celula *le) {
    celula *atual = le->prox;

    if (atual == NULL) {
        printf("NULL\n");
        return;
    }

    while (atual != NULL) {
        printf("%d", atual->dado);
        if (atual->prox != NULL) {
            printf(" -> ");
        } else {
            printf(" -> NULL\n");
        }
        atual = atual->prox;
    }
}

// Função recursiva para imprimir a lista encadeada
void imprime_rec(celula *le) {
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d", le->prox->dado);

    if (le->prox->prox != NULL) {
        printf(" -> ");
        imprime_rec(le->prox);
    } else {
        printf(" -> NULL\n");
    }
}