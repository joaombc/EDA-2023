#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pilha {
    int* dados;
    int N, topo;
} pilha;

void redimenciona(pilha* p) {
    int N = 2 * p->N;
    int* dados = malloc(N * sizeof(int));

    for (int i = 0; i < p->topo; i++) dados[i] = p->dados[i];
    p->N = N;

    free(p->dados);
    p->dados = dados;
}

int empilha(pilha* p, int x) {
    if (p->topo == p->N) redimenciona(p);

    p->dados[p->topo++] = x;
    return 1;
}