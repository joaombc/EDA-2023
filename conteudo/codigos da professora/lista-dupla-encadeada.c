#include <stdio.h>
#include <stdlib.h>

/*
Listas Duplamente Encadeadas

        Formas de implementaÃ§Ã£o
            Aponta para o elemento anterior e prÃ³ximo
            Consome espaÃ§o adicional e manutenÃ§Ã£o dos apontadores
            PorÃ©m facilita operaÃ§Ãµes inserÃ§Ãµes/remoÃ§Ãµes anteriores
            InserÃ§Ã£o/RemoÃ§Ã£o antes e apÃ³s um elemento em tempo constante
            Sem cabeÃ§a, com cabeÃ§a, com cauda, com cabeÃ§a e cauda
            CabeÃ§a do mesmo tipo dos elementos do corpo
            CabeÃ§a com elementos diferentes do corpo
        
        Utilizado em algoritmos com manipulaÃ§Ãµes frequentes, como os algoritmos de ordenaÃ§Ã£o
    
*/

/*
 * Tipos de dados dos elementos da lista
 *  Item: tipo do conteÃºdo dos nÃ³s
 *  node: tipo de cada nÃ³
 *  head: tipo da cabeÃ§a da lista
 */
typedef int Item;

typedef struct registro node;
struct registro {
    Item info;
    node *ant; //<<<<<<<<<<<<<<<<<<<<<<<<<<<
    node *prox;
};

//tipo head
typedef struct cabeca head;
struct cabeca {
    int num_itens;
    node *prox;
    node *ultimo;
};


//PROTÃ“TIPO DAS OPERAÃ‡Ã•ES BÃSICAS
head *criar_lista();
node *criar_no(Item);

int vazia(head*);
int tamanho_lista(head *);

node *busca_inicio(head *);
node *busca_anterior(node *);
node *busca_proximo(node *);
node *busca_fim(head *);

void insere_inicio(head *, node *);
void insere_fim(head *, node *);
void insere_depois(head *, node *, node *);
void insere_antes(head *, node *, node *);

void remove_no(head *, node *);

//OPERAÃ‡Ã•ES ADICIONAIS
//UTILIZAR FUNÃ‡Ã•ES BASES





head * criar_lista()
{
    head *le = malloc(sizeof(head));
    le->num_itens = 0;
    le->prox = NULL;
    le->ultimo = NULL;
    return le;
}

node *criar_no(Item x)
{
    node *no = malloc(sizeof(node));
    no->ant = NULL;            //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    no->prox = NULL;
    no->info = x;
    return no;
}

int vazia(head *p)
{
  return (p->prox==NULL); 
}

int tamanho_lista(head *lista)
{
    //cabeca != node
    return lista->num_itens;
    
    //cabeca == node
    //int tam = 0;
    //node *aux = busca_inicio(lista);
    //while(aux != NULL && aux->prox != NULL){
      //  aux= aux->prox;
      // tam++;
    //}
    //return tam;
    
}

node *busca_inicio(head *lista)
{
  return lista->prox;
}

node *busca_anterior(node *no)   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
{
  return no->ant;
}

node *busca_proximo(node *no)
{
  return no->prox;
}

node *busca_fim(head *lista)
{

    //cabeca != node
    return lista->ultimo;
    
    //cabeca == node
    //cauda == node
    
}

void insere_inicio(head *lista, node *novo)
{  
    if(vazia(lista)) lista->ultimo = novo;
    else lista->prox->ant = novo; //<<<<<<<<<<<<<<<<<<<<<<<<
    lista->num_itens++; 

    novo->ant = NULL;         //<<<<<<<<<<<<<<<<<<<<<<<<
    novo->prox = lista->prox;    
    lista->prox = novo;
}

void insere_fim(head *lista, node *novo)
{
    if(vazia(lista)) return insere_inicio(lista, novo);
    
    novo->ant = lista->ultimo; //<<<<<<<<<<<<<<<<<
    novo->prox = NULL;
    
    //cabeca != node
    lista->ultimo->prox = novo;
    lista->ultimo = novo;
    lista->num_itens++;
}

void insere_depois(head *lista, node *ref, node *novo)
{
    if(lista->ultimo == ref) return insere_fim(lista, novo);
    
    novo->ant = ref;        //<<<<<<<<<<<<<<<<<<<<<<<<<<
    novo->prox = ref->prox;
    ref->prox->ant = novo;  //<<<<<<<<<<<<<<<<<<<<<<<<<<
    ref->prox = novo;
    
    lista->num_itens++;
}

void insere_antes(head *lista, node *ref, node *novo)
{
    if(lista->prox == ref) return insere_inicio(lista, novo);
     
    return insere_depois(lista, ref->ant, novo);
}

void remove_no(head *lista, node *lixo)
{
    
    if(lixo->ant) lixo->ant->prox = lixo->prox; //se nao for o primeiro elemento
    else lista->prox = lixo->prox;
    
    if(lixo->prox) lixo->prox->ant = lixo->ant; //se nao for o ultimo elemento
    else lista->ultimo = lixo->ant; //cabeca != node
    
    //cabeca != node
    lista->num_itens--;
    
}



///////////////////////////////////////////////////
///////////////////////////////////////////////////

void imprime(head *lista)
{
    printf("%d itens\n", lista->num_itens);
    
    node *a = lista->prox;
    while(a!=NULL) {
        printf("%3d", a->info);
        a = a->prox;
    }
    
    if(lista->ultimo) printf("\nÃºltimo item: %d", lista->ultimo->info);
    printf("\n\n");
}

void imprime_reverso(head *lista)
{
    printf("Imprime reverso\n");
    printf("%d itens\n", lista->num_itens);
    
    node *a = busca_fim(lista);
    while(a!=NULL) {
        printf("%3d", a->info);
        a = a->ant;
    }
    
    if(lista->ultimo) printf("\nÃºltimo item: %d", lista->ultimo->info);
    printf("\n\n");
}


void troca_nos(head *lista, node *no1, node *no2)
{
    //printf("troca: %d %d\n", no1->info, no2->info);
    node *no2_prox = busca_proximo(no2);
  
    remove_no(lista, no2);  
    insere_antes(lista, no1, no2);
    remove_no(lista, no1);  

    if(no2_prox) insere_antes(lista, no2_prox, no1);
    else insere_fim(lista, no1);
    
}

void inverte_lista_v1(head *lista){
    //insere depois do primeiro ultimo 
    node *p = busca_inicio(lista);
    node *q = busca_fim(lista);
    int tam = tamanho_lista(lista);
    for(int i=0; i<tam-1; i++){
        remove_no(lista, p);
        insere_depois(lista, q, p);
        p = busca_inicio(lista);
    }
}

void inverte_lista_v2(head *lista){
    //trocar o primeiro com o ultimo
    //trocar o segundo com o penultimo
    //ate o meio

    node *p = busca_inicio(lista);
    node *q = busca_fim(lista);
    int tam = tamanho_lista(lista)/2;

    while(tam>0){
        tam--;
        troca_nos(lista, p, q);
        node *a = p;
        p = busca_proximo(q);
        q = busca_anterior(a);
        
    }
}

void inverte_lista_v3(head **lista){
    //criar nova lista invertida
    head *nova_lista = criar_lista();

    int tam = tamanho_lista(*lista);

    node *a = busca_fim(*lista);
    
    while(a!=NULL){
        remove_no(*lista, a);
        insere_fim(nova_lista, a);
        a = busca_fim(*lista);
    }
    free(*lista);
    *lista = nova_lista;
}




///////////////////////////////////////////////////
///////////////////////////////////////////////////
int main(){
    head *le = criar_lista();

    //cria e insere item no fim da lista
    for(int i=0; i<10; i++){
        node *novo = criar_no(i);
        insere_fim(le, novo);
    }
    imprime(le);
    imprime_reverso(le);

    //cria e insere item na posiÃ§Ã£o 4 da lista
    node *novo = criar_no(-9);
    node *aux = busca_inicio(le);
    for(int i=1; i<4; i++) 
        aux = busca_proximo(aux);
    if(aux) 
        insere_depois(le, aux, novo);
    imprime(le);

    //retira um nÃ³ da lista
    remove_no(le, novo);
    imprime(le);
    free(novo); //libera memÃ³ria


    //busca um nÃ³ com um conteÃºdo especÃ­fico e
    //cria e insere item antes do nÃ³ procurado
    aux = busca_inicio(le);
    node *ant = NULL;
    while(aux!=NULL && aux->info!=5) { //procura nÃ³ com o conteÃºdo 5
        ant = aux;
        aux = busca_proximo(aux);
    }

    novo = criar_no(-9); //nÃ³ que serÃ¡ inserido
    if(aux!=NULL && aux->info==5){ //caso tenha achado o nÃ³ com conteÃºdo 5
        insere_depois(le, ant, novo);
    }
    printf("%d\n", novo->prox->ant->info);
    imprime(le);



    //node *a = busca_inicio(le);
    //remove_no(le, a);
    //free(a);
    //imprime(le);

    inverte_lista_v2(le); 
    imprime(le);

    return 0;
}