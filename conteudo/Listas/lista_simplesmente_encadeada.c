typedef int Item;

typedef struct node no;
struct node no{
	Item info;
	node *prox;
}

/*
					_________________   __________________
				 no |				no  |				 no
			info | prox			info| prox			  info|prox------ NULL


pode ou n ter cabeça
	se tem cabeça: elementos da lista a partir do segundo no, primeiro no ignorado

		__________________	_________________   	__________________ ______________________________________
cabeça	|				 no |				no      |				 no 							cauda   |
---|*prox			info | *prox			info| *prox			  info|*prox------ NULL			  ---- | *prox


*/



//  Listas simplemente encadeadas com cabeca


//nos da lista
typedef struct node no;
struct node no{
	Item info;
	node *prox;
}

// so para a cabeça
typedef struct head cabeca;
struct head{
	int tam;
	no *prox
	no *ultimo
}


// novo elemento
no *novo = malloc(sizeof(no));
novo ->prox = NULL;
novo_info = 2;


//criando a lista e inserindo o novo elemento
cabeca *lista = malloc(sizeof(cabeca));
lista ->tam = 1
lista ->prox = novo;
lista ->ultimo = novo;


// EXERCICIOS

/*Escreva uma função que conte o número de células de uma lista encadeada.
Faça duas versões: uma iterativa e uma recursiva.*/

int contarCelulasIterativa(cabeca *lista) {
    int count = 0;
    no *atual = lista->prox;

    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }

    return count;
}

int contarCelulasRecursiva(no *atual) {
    if (atual == NULL) {
        return 0;
    }
    return 1 + contarCelulasRecursiva(atual->prox);
}

/*Escreva uma função que concatene duas listas encadeadas.
Faça duas versões: uma iterativa e uma recursiva. */

void concatenarListasIterativa(cabeca *lista1, cabeca *lista2) {
    no *atual = lista1->ultimo;
    atual->prox = lista2->prox;
    lista1->ultimo = lista2->ultimo;
    lista1->tam += lista2->tam;
}


void concatenarListasRecursiva(cabeca *lista1, no *novo_inicio, no *novo_final, int tamanho_novo) {
    lista1->ultimo->prox = novo_inicio;
    lista1->ultimo = novo_final;
    lista1->tam += tamanho_novo;
}

/* Escreva uma função que insira uma nova célula com conteúdo x
imediatamente depois da k-ésima célula de uma lista encadeada. Faça duas
versões: uma iterativa e uma recursiva. */

int inserirAposKIterativa(cabeca *lista, int k, int x) {
    no *atual = lista->prox;
    int i = 1;
    while (atual != NULL && i < k) {
        atual = atual->prox;
        i++;
    }

    if (atual == NULL) {
        return 0;  // A lista não tem k células.
    }

    no *novo = malloc(sizeof(no));
    novo->dado = x;
    novo->prox = atual->prox;
    atual->prox = novo;

    lista->tam++;
    if (atual == lista->ultimo) {
        lista->ultimo = novo;
    }

    return 1;  // Inserção bem-sucedida.
}


int inserirAposKRecursiva(cabeca *lista, no *atual, int k, int x) {
    if (atual == NULL) {
        return 0;  // A lista não tem k células.
    }

    if (k == 1) {
        no *novo = malloc(sizeof(no));
        novo->dado = x;
        novo->prox = atual->prox;
        atual->prox = novo;

        lista->tam++;
        if (atual == lista->ultimo) {
            lista->ultimo = novo;
        }

        return 1;  // Inserção bem-sucedida.
    }

    return inserirAposKRecursiva(lista, atual->prox, k - 1, x);
}