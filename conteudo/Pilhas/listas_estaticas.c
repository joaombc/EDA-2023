typedef char Item;

/*
IMPLEMENTAÇÃO COM ARRAYS
*/

typedef struct pilha_t Pilha;
struct pilha_t{
	Item *item;
	int topo;
}

Pilha *criar(int maxN){
	Pilha *p = malloc(sizeof *p);
	p->item = malloc(maxN*sizeof Item);
	p->topo = 0;
	return p;
}

int vazia(Pilha *p){
	return p->topo == 0;
}

void empilhar(Pilha *p, Item *p){
	p->item[p->topo++] == item
}

Item desmpilhar(Pilha *p){
	return p->item[--p->topo];
}

Item espiar(Pilha *p){
	return p->item[p->topo-1];
}
