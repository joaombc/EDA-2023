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
