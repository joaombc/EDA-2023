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


/*
IMPLEMENTAÇÃO COM LISTAS ENCADEADAS
*/

//tipo node
typedef struct registro node;
struct registro {
    Item info;
    node *prox; 
};

//tipo head
typedef struct cabeca head;
struct cabeca {
    int num_itens;
    node *prox;
    node *ultimo;
};

// criar lista
head *criar_lista(){
	head *le =malloc(sizeof(head));
	le->num_itens =0;
	le->prox = NULL;
	le->ultimo = NULL;
	return le;
}

node *criar_no(Item x){
	node *no = malloc(sizeof(no));
	no->prox = NULL;
	no->info = x;
	return no;
}

// lista vazia
int vazia(head *p){
	return p->prox == NULL;
}


// EMPILHA
void empilha(head *lista)