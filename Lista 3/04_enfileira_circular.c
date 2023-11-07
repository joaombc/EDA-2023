#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int redimenciona(fila *f) {
    f->dados = realloc(f->dados, 2  *f->N  *sizeof(int));
    if (f->dados == NULL) return 0;

    int j = f->p, next = f->p;
    
    int resto = f->N % 2;
    if (f->p > (f->N / 2) + resto) {
        j += f->N;
        next += f->N;
    }

    for (int i = f->p; i != f->u; i = (i + 1) % f->N) {
        f->dados[j] = f->dados[i];
        j = (j + 1) % (2  *f->N);
    }

    f->p = next;
    f->u = j;
    f->N *= 2;

    return 1;
}

int enfileira(fila *f, int x) {
    if ((f->u + 1) % f->N == f->p && !redimenciona(f)) return 0;

    f->dados[f->u++] = x;
    if (f->u == f->N) f->u = 0;
    return 1;
}