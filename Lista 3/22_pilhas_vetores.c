#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* v; // Vetor que contem os elementos da pilha
    int N; // Tamanho de v
    int topo; // Indicador do topo
} pilha;

int desempilha(pilha* p, int* y) {
    if (p == NULL || p->topo == 0) return 0;

    *y = p->v[--p->topo];
    return 1;
}

void redimenciona(pilha* p) {
    int N = 2 * p->N;
    int* dados = malloc(N * sizeof(int));

    for (int i = 0; i < p->topo; i++) dados[i] = p->v[i];
    p->N = N;

    free(p->v);
    p->v = dados;
}

int empilha(pilha* p, int x) {
    if (p->topo == p->N) redimenciona(p);

    p->v[p->topo++] = x;
    return 1;
}