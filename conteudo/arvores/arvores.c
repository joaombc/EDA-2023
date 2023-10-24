typedef struct No{
	int dado;
	struct No *esq, *dir; // pai
}No;

typedef No *p_no;

p_no criar_arvore(int x, p_no esq, p_no dir){
	p_no r = malloc(sizeof(No));
	r->dado = x;
	r->esq = esq;
	r->dir = dir;
	return r;
}

p_no procurar_no(p_no raiz, int x){
	p_no esq;
	if(raiz == NULL || raiz -> dado == x){
		return raiz;
	}
	esq = procurar_no(raiz-> esq, x);
	if (esq !=NULL){
		return esq;
	}
	return procurar_no(raiz->dir, x);
}

int numeros_nos(p_no raiz){
	if(raiz == NULL){
		return 0;
	}
	return numeros_nos(raiz->esq)+ numeros_nos(raiz->dir) +1;
}

int altura(p_no raiz){
	int h_esq, h_dir;
	if(raiz == NULL){
		return 0;
	}
	h_esq = altura(raiz->esq);
	h_dir = altura(raiz->dir);
	return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

/////////////////////////////////////////////////
// AS MESMAS FUNÇÕES SÓ QUE SEM RECURSIVIDADE //
///////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* esq;
    struct No* dir;
} No;

typedef No* p_no;

p_no criar_arvore(int x, p_no esq, p_no dir) {
    p_no r = malloc(sizeof(No));
    r->dado = x;
    r->esq = esq;
    r->dir = dir;
    return r;
}

p_no procurar_no(p_no raiz, int x) {
    p_no temp = raiz;
    while (temp != NULL && temp->dado != x) {
        if (x < temp->dado) {
            temp = temp->esq;
        } else {
            temp = temp->dir;
        }
    }
    return temp;
}

int numeros_nos(p_no raiz) {
    int count = 0;
    if (raiz == NULL) {
        return 0;
    }

    p_no stack[1000]; // Tamanho arbitrário da pilha
    int top = 0;
    p_no temp = raiz;

    while (temp != NULL || top > 0) {
        while (temp != NULL) {
            stack[top++] = temp;
            temp = temp->esq;
        }

        temp = stack[--top];
        count++;
        temp = temp->dir;
    }

    return count;
}

int altura(p_no raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int h = 0;
    p_no stack[1000]; // Tamanho arbitrário da pilha
    int top = 0;
    p_no temp = raiz;
    int max_h = 0;

    while (temp != NULL || top > 0) {
        while (temp != NULL) {
            stack[top++] = temp;
            temp = temp->esq;
            h++;
            if (h > max_h) {
                max_h = h;
            }
        }

        temp = stack[--top];
        temp = temp->dir;
        h--;
    }

    return max_h;
}

// EXERCICIO DO TORNEIO
p_no torneio(int *v, int l, int r) {
	p_no esq, dir;
	int valor, m = (l + r) / 2;
	if (l == r)
		return criar_arvore(v[l], NULL, NULL);
	esq = torneio(v, l, m);
	dir = torneio(v, m+1, r);
	valor = esq->dado > dir->dado ? esq->dado : dir->dado;
	return criar_arvore(valor, esq, dir);
}

//Percursos em profundidade
//PRE ORDEM
void pre_ordem(p_no raiz) {
	if (raiz != NULL) {
		printf("%d ", raiz->dado); /* visita raiz */
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}

void pre_ordem(p_no raiz) {
	p_pilha p; /* pilha de p_no */
	p = criar_pilha();
	empilhar(p, raiz);
	while(!pilha_vazia(p)) {
		raiz = desempilhar(p);
		if (raiz != NULL) {
			empilhar(p, raiz->dir);
			empilhar(p, raiz->esq);
			printf("%d ", raiz->dado); /* visita raiz */
		}
	}
	destruir_pilha(p);
}

//POS ORDEM
void pos_ordem(p_no raiz) {
	if (raiz != NULL) {
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		printf("%d ", raiz->dado); /* visita raiz */
	}
}

//INORDEM
void inordem(p_no raiz) {
	if (raiz != NULL) {
		inordem(raiz->esq);
		printf("%d ", raiz->dado); /* visita raiz */
		inordem(raiz->dir);
	}
}

// PERCURSO EM LARGURA
void percurso_em_largura(p_no raiz) {
	p_fila f;
	f = criar_fila();
	enfileirar(f, raiz);
	while(!fila_vazia(f)) {
		raiz = desenfileirar(f);
		if (raiz != NULL) {
			enfileirar(f, raiz->esq);
			enfileirar(f, raiz->dir);
			printf("%d ", raiz->dado); /* visita raiz */
		}
	}
	destruir_fila(f);
}

/* EXERCÍCIOS */

//////////////////////////////////////////
// verifica se duas arvores são iguais //
////////////////////////////////////////

int sao_iguais(p_no raiz1, p_no raiz2) {
    // Se ambas as árvores são nulas, elas são iguais.
    if (raiz1 == NULL && raiz2 == NULL) {
        return 1;
    }

    // Se uma árvore é nula e a outra não, elas não são iguais.
    if (raiz1 == NULL || raiz2 == NULL) {
        return 0;
    }

    // Verifique se os valores dos nós correspondentes são iguais.
    if (raiz1->dado != raiz2->dado) {
        return 0;
    }

    // Recursivamente verifique as subárvores esquerdas e direitas.
    int esq_iguais = sao_iguais(raiz1->esq, raiz2->esq);
    int dir_iguais = sao_iguais(raiz1->dir, raiz2->dir);

    // As árvores são iguais apenas se ambas as subárvores esquerdas e direitas forem iguais.
    return esq_iguais && dir_iguais;
}

////////////////////////////////////////////
// APAGAR TODAS AS FOLHAS COM UM VALOR X //
//////////////////////////////////////////

p_no apagar_folhas_com_valor(p_no raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    // Verifique se o nó atual é uma folha com o valor dado.
    if (raiz->esq == NULL && raiz->dir == NULL && raiz->dado == valor) {
        free(raiz); // Libera a memória do nó.
        return NULL;
    }

    // Recursivamente processe as subárvores esquerda e direita.
    raiz->esq = apagar_folhas_com_valor(raiz->esq, valor);
    raiz->dir = apagar_folhas_com_valor(raiz->dir, valor);

    return raiz;
}

///////////////////////////////////////////////////////////////////////////
// Escreva uma função que calcula o número de folhas em uma árvore dada //
/////////////////////////////////////////////////////////////////////////

int numero_de_folhas(p_no raiz) {
    if (raiz == NULL) {
        return 0;
    }
    
    // Se o nó atual é uma folha (sem filhos), retorne 1.
    if (raiz->esq == NULL && raiz->dir == NULL) {
        return 1;
    }
    
    // Caso contrário, conte as folhas nas subárvores esquerda e direita e some-as.
    int folhas_esq = numero_de_folhas(raiz->esq);
    int folhas_dir = numero_de_folhas(raiz->dir);
    
    return folhas_esq + folhas_dir;
}