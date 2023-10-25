#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct pilha {
    no *dado;
    struct pilha *prox;
} pilha;

pilha *cria_pilha() {
    pilha *nova = (pilha*)malloc(sizeof(pilha));
    nova->prox = NULL;
    return nova;
}

bool empty(pilha *p) {
    return p == NULL || p->prox == NULL;
}

void empilha(pilha *p, no *x) {
    pilha *nova = (pilha*)malloc(sizeof(pilha));
    nova->dado = x;
    nova->prox = p->prox;
    p->prox = nova;
}

void desempilha(pilha *p) {
    pilha *trash = p->prox;
    p->prox = p->prox->prox;
    free(trash);
}

no* topo(pilha *p) {
    pilha *topo = p->prox;
    return topo->dado;
}

void pre_ordem(no *raiz) {
    if (raiz == NULL) {
        printf("\n");
        return;
    }

    pilha *nova = cria_pilha();
    empilha(nova, raiz);

    while (!empty(nova)) {
        no *node = topo(nova);
        desempilha(nova);

        printf("%d ", node->dado);

        if (node->dir) empilha(nova, node->dir);
        if (node->esq) empilha(nova, node->esq);

    }
    printf("\n");
}