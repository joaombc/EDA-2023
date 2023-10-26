#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *esq,  *dir;
} no;

typedef struct pilha {
    no *dado;
    struct pilha *prox;
} pilha;

pilha *cria_pilha() {
    pilha *sk = (pilha*)malloc(sizeof(pilha));
    sk->prox = NULL;
    return sk;
}

bool vazia(pilha *p) {
    return p == NULL || p->prox == NULL;
}

void empilha(pilha *p, no *x) {
    pilha *sk = (pilha*)malloc(sizeof(pilha));
    sk->dado = x;
    sk->prox = p->prox;
    p->prox = sk;
}

void desempilha(pilha *p) {
    pilha *trash = p->prox;
    p->prox = p->prox->prox;
    free(trash);
}

no *topo(pilha *p) {
    pilha *topo = p->prox;
    return topo->dado;
}

void pos_ordem(no *raiz) {
    if (raiz == NULL) {
        printf("\n");
        return;
    }

    pilha *s1 = cria_pilha(),  *s2 = cria_pilha();
    empilha(s1, raiz);
    no *node;

    while (!vazia(s1)) {
        node = topo(s1);
        desempilha(s1);
        empilha(s2, node);

        if (node->esq) empilha(s1, node->esq);
        if (node->dir) empilha(s1, node->dir);
    }

    while (!empty(s2)) {
        printf("%d ", topo(s2)->dado);
        desempilha(s2);
    }
    printf("\n");
}