typedef int Item;

typedef struct node no;
struct node no{
	Item info;
	no *ant;
	node *prox;
}

typedef struct head cabeca;
struct head{
	int tam;
	no *prox
	no *ultimo
}

// CRIAÇÃO

cabeca *criar(){
	cabeca *l = malloc(sizeof(cabeca));
	l->tam = 0;
	l->prox = NULL;
	l->ultimo = NULL;

	return l;
}

no *criar_no(Item x){
	no *novo = malloc(sizeof(no));
	novo->ant = NULL;
	novo->prox = NULL;
	novo->info = x;

	return novo;
}

// PERCORRER

int vazia(cabeca *lista){
	return (lista->prox->NULL);
}

int tamanho_lista(cabeca *lista){
	return lista->num_itens;
}

no *inicio(cabeca *lista){
	return lista->prox;
}

no *ultimo(cabeca *lista){
	return lista->ultimo;
}

//inserir no inicio da lista
void insere_inicio(cabeca *lista, node *novo){
	if(vazia(lista)) lista->ultimo = novo;
	else lista->prox->ant = novo
	lista->num_itens++;

	novo->ant = NULL;
	novo->prox = lista->prox;
	lista->prox = novo;
}

// inserir no final da lista
void insere_fim(cabeca *lista , node *novo){
	if(vazia(lista)) return insere_inicio(lista,novo);

	novo->ant = lista->ultimo;
	novo->prox = NULL;

	lista->ultimo->prox = novo;
	lista->ultimo = novo;
	lista->num_itens++;
}

//inserir depois de um no de referencia
void insere_depois_ref(cabeca *lista, node *ref, node *novo){
	if(lista->ultimo == ref) return insere_fim(lista,novo);
	
	novo->ant = ref;
	novo->prox = ref->prox;

	ref->ant = novo;
	ref->prox->ant = novo;

	lista->num_itens++;
}


void insere_antes_ref(head *lista, node *ref, node *novo){
	if(lista->prox == ref) return insere_inicio(lista, novo);

	return insere_depois_ref(lista, ref->ant, novo);
}


void remove_no(cabeca *lista, node *lixo){
if(lixo->ant) lixo->ant->prox = lixo->prox; //se nao for o primeiro elemento
    else lista->prox = lixo->prox;
    
    if(lixo->prox) lixo->prox->ant = lixo->ant; //se nao for o ultimo elemento
    else lista->ultimo = lixo->ant; //cabeca != node
    
    //cabeca != node
    lista->num_itens--;
}