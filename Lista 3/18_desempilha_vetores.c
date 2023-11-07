#include <stdio.h>

typedef struct pilha{
	int *dados;
	int N, topo;
}pilha;

int desempilha(pilha *p, int *y){
	if(p == NULL || p->topo ==0){
		return 0;
	}
	*y = p->dados[--p->topo];
    return 1;
}