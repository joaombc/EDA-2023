#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula* prox;
} celula;

void divide_lista(celula* l, celula* l1, celula* l2) {
    while (l->prox != NULL) {
        l = l->prox;
        if (l->dado & 1) {
            l1->prox = l;
            l1 = l1->prox;
            l2->prox = NULL;
        }
        else {
            l2->prox = l;
            l2 = l2->prox;
            l1->prox = NULL;
        }
    }
}
