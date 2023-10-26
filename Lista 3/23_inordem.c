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

void em_ordem(no *raiz) {
    pilha *sk = cria_pilha();
    if (raiz == NULL) {
        printf("\n");
        return;
    }

    no *curr = raiz;
    while (curr != NULL) {
        empilha(sk, curr);
        curr = curr->esq;
    }

    while (!vazia(sk)) {
        curr = topo(sk);
        printf("%d ", curr->dado);
        desempilha(sk);

        if (curr->dir) {
            curr = curr->dir;
            while (curr != NULL) {
                empilha(sk, curr);
                curr = curr->esq;
            }
        }
    }
    printf("\n");
}