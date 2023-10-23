#include <stdio.h>
#include <stdlib.h>

/*
SequÃªncia de conteiners
        InserÃ§Ã£o tempo constante
        Ideal para aplicaÃ§Ãµes com grandes conjuntos de dados e, poucas ou sem remoÃ§Ãµes, ou implementaÃ§Ãµes de FIFO (filas)
        Custo de remoÃ§Ã£o: O(n)
        Formas de implementaÃ§Ã£o
            Aponta para o prÃ³ximo elemento
            InserÃ§Ã£o/RemoÃ§Ã£o apÃ³s um elemento em tempo constante
            Sem cabeÃ§a, com cabeÃ§a, com cauda, com cabeÃ§a e cauda
            CabeÃ§a do mesmo tipo dos elementos do corpo
            CabeÃ§a com elementos diferentes do corpo
            
        CaracterÃ­sticas
            melhor performance na inserÃ§Ã£o, remoÃ§Ã£o/extraÃ§Ã£o e movimentaÃ§Ã£o dos elementos
            requer menos espaÃ§o e manipulaÃ§Ã£o de ponteiro do que a duplamente
            algoritmos com vÃ¡rias movimentaÃ§Ãµes como algoritmos de ordenaÃ§Ã£o
            desvantagem: 
                sem acesso direto a uma posiÃ§Ã£o
                aumento da carga nas remoÃ§Ãµes de elementos arbitrÃ¡rios
            uso de campos adicionais: 
                    aumenta o uso da memÃ³ria e um pouco da carga de inserÃ§Ãµes e remoÃ§Ãµes
                    porÃ©m aumenta a eficiÃªncia das operaÃ§Ãµes em fim de lista
                        diminui o custo da funÃ§Ã£o busca_fim

*/
/*
 * Tipos de dados dos elementos da lista
 *  Item: tipo do conteÃºdo dos nÃ³s
 *  node: tipo de cada nÃ³
 *  head: tipo da cabeÃ§a da lista
 */
typedef int Item;


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


//PROTÃ“TIPO DAS OPERAÃ‡Ã•ES BÃSICAS
head * criar_lista();
node *criar_no(Item);
int vazia(head *);
int tamanho_lista(head *);

void insere_inicio(head *, node *);
void insere_depois(head *, node *, node *);
void insere_fim(head *, node *); //com cabeÃ§a e apontador para o Ãºltimo

node *busca_inicio(head *);
node *busca_proximo(node *);
node *busca_fim(head *);//com cabeÃ§a e apontador para o Ãºltimo

void remove_no(head *, node *);
void remove_inicio(head *);

//OPERAÃ‡Ã•ES ADICIONAIS
//buscar nÃ³ antes de outro nÃ³
//buscar nÃ³ antes de um dado/item
//inserir um nÃ³ ou um item antes de um nÃ³
//inserir um nÃ³ ou um item antes ou depois de uma posiÃ§Ã£o
//remover um item ou nÃ³ depois de um nÃ³ ou de uma posiÃ§Ã£o


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

void insere_inicio(head *lista, node *novo)
{  
    //cabeca != node
    if(vazia(lista)) lista->ultimo = novo;
    lista->num_itens++;  
    
    novo->prox = lista->prox;    
    lista->prox = novo;
}

void insere_fim(head *lista, node *novo)
{
    if(vazia(lista)) return insere_inicio(lista, novo);
        
    novo->prox = NULL;
        
    //cabeca != node
    lista->ultimo->prox = novo;
    lista->ultimo = novo;
    lista->num_itens++;
    
    //cabeca == node
    //node *aux = busca_fim(lista);
    //insere_depois(lista, aux, novo);
}

void insere_depois(head *lista, node *ref, node *novo)
{
    if(lista->ultimo == ref) return insere_fim(lista, novo);
      
    novo->prox = ref->prox;
    ref->prox = novo;
      
    //cabeca != node
    lista->num_itens++;
}

node *busca_inicio(head *lista)
{
  return lista->prox;
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
    //cauda apontando para o Ãºltimo elemento
    
}

void remove_no(head *lista, node *lixo)
{
    node *aux = busca_inicio(lista);
    while(aux!=NULL && aux->prox!=lixo) 
        aux = busca_proximo(aux);

    if(aux){
        aux->prox = lixo->prox;
        if(lixo == lista->ultimo) lista->ultimo = aux->prox;
        lista->num_itens--;
    }
    
}

void remove_inicio(head *lista)
{
    if(!vazia(lista)){
        node *lixo = lista->prox;
        lista->prox = lista->prox->prox;

        if(lixo == lista->ultimo) lista->ultimo = NULL;
        lista->num_itens--;
    }
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////




///////////////////////////////////////////////////
///////////////////////////////////////////////////
void imprime(head *lista){
    printf("%d itens\n", lista->num_itens);
    
    node *a = lista->prox;
    while(a!=NULL) {
        printf("%3d", a->info);
        a = a->prox;
    }
    
    if(lista->ultimo) printf("\nÃºltimo item: %d", lista->ultimo->info);
    printf("\n\n");
}

/*void criar_lista(head **le)
{
    *le = malloc(sizeof(head));
    (*le)->num_itens = 0;
    (*le)->prox = NULL;
    (*le)->ultimo = NULL;
}*/


///////////////////////////////////////////////////
///////////////////////////////////////////////////
int main(){
  head *le = criar_lista();
  //head *le;
  //criar_lista(&le);
  
  return 0;
}