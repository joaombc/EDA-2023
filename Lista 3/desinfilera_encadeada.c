#include <stdio.h>

typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

int desenfileira(celula *f, int *y){
	 if (f == NULL || f->prox == NULL) return 0;

    celula *lixo = f->prox;

    *y = f->prox->dado;
    f->prox = f->prox->prox;

    free(lixo);
    return 1;


}