/*
Navegação trivial para cima e baixo:
    ▶ Simples operação aritmética
    ▶ Sendo um nó na posição k
        ⋆ pai: ⌊k/2⌋
        ⋆ flhos: 2k e 2k + 1
Tamanho N em um vetor pq[]
    ▶ pq[N+1]: pq[1..N]
    ▶ E se utilizar o 0?
        ⋆ pai: ⌊k−1/2⌋
        ⋆ flhos: 2k + 1 e 2k + 2
*/

//FILAS DE PRIORIDADE - INSERÇÃO - HEAP
/*
[]
inserir 8              
[8]
                            8
inserir 9
[8,9] 
                            8
                          /
                        9       restaura

                            9
                          /
                        8       restaura
[9,8]

insere 7
[9,8,7]
                            9
                          /  \
                        8     7 

inserir 6,3,5,3
[9,8,7,6,3,5,3]
                            9
                          /  \
                        8     7
                      /  \   /  \
                    6    3  5    3

inserir 4,1
[9,8,7,6,3,5,3,4,1]
                            9
                          /  \
                        8     7
                      /  \   /  \
                    6    3  5    3
                  /  \
                 4   1

inserir 10
[9,8,7,6,3,5,3,4,1,10]
                            9
                          /  \
                        8     7
                      /  \   /  \
                    6    3  5    3
                  / \   /
                 4  1  10
                 temos que achar uma nova posição para o 10, pq ele é maior que seu pai
                 logo tem que ser promovido.
restaurar 10
                            9
                          /  \
                        8     7
                      /  \   /  \
                    6    10  5    3
                  / \   /
                 4  1  3
                [9,8,7,6,3,5,10,4,1,3]

restaurar 10
                            9
                          /  \
                        10     7
                      /  \   /  \
                    6    8  5    3
                  / \   /
                 4  1  3
                [9,10,7,6,3,5,8,4,1,3]

restaurar 10
                           10
                          /  \
                        9     7
                      /  \   /  \
                    6    8  5    3
                  / \   /
                 4  1  3
                [10,9,7,6,8,5,3,4,1,3]

*/

// complexidade: 1+log N comparações
//               O(log N)
void fixUp(int k){ 
    // troque com o pai se for maior
    while (k>1 && less(pq[k/2], pq[k])){
        exch(pq[k], pq[k/2]);
        k = k/2; //verifica o avô
    }
}

void PQinsert(Item v){
    pq[++N] = v;
    fixUp(N);
}

/*
    REMOÇÃO
        ▶ Remover qual elemento??
        ▶ Substituir a raiz por uma folha
        ▶ Restauração/conserto: descendo na heap


remoção 10
[*10*,9,7,6,8,5,3,4,1,*3*]
                           10
                          /  \
                        9     7
                      /  \   /  \
                    6    8  5    3
                  / \   /
                 4  1  3

                            3
                          /  \
                        9     7
                      /  \   /  \
                    6    8  5    3
                  / \   /
                 4  1  10

[*3*,9,7,6,8,5,3,4,1,*10*]
restaurar 3
                            9
                          /  \
                        3     7
                      /  \   /  \
                    6    8  5    3
                  / \   /
                 4  1  10
                 
[9,*3*,7,6,8,5,3,4,1,*10*]
restaurar 3
                            9
                          /  \
                        8     7
                      /  \   /  \
                    6    3  5    3
                  / \   /
                 4  1  10
            [9,8,7,6,*3*,5,3,4,1,*10*]    
*/

// Complexidade: 2 log N comparações
void fixDown(int k, int N){
    int j;

    // tem filho?
    while (2*k <= N){
        j = 2*k;

        // qual o maior filho
        if(j < N && less (pq[j] , pq[j+1])){
            j ++;
        }

        // pai maior que o maior filho?
        if (!less(pq[k],pq[j])) {
            break;
        }
        
        //senão, afunde
        exch(pq[k], pq[j]);
        k = j;
    }
}

Item PQdelmax(){
    exch(pq[1], pq[N]); // troque topo -> ultimo
    fixDown(1, N-1);  // reposicione
    return pq[N--];
}

//FILAS DE PRIORIDADE - ALTERAR PRIORIDADE - HEAP

// se temos o indice na fila de prioridades é trivial

void PQchange(int k, int valor){
    v[k] = valor;

    if(v[k] < valor){
        fixUp(k);
    }
    else{
        fixDown(k, N);
    }
}

// Lista de indices

typedef struct {
    char nome[20];
    int chave;
} Item;

static Item *pq;
static Item *qp;
static int N;

Item *data;

// k indice do elemento na lista
// data[k]

void PQinsert(int k){
    qp[k] = ++N; // data[k] na ultima posição da fila
    pq[N] = k; // inserir na ultima posição
    fixUp(N); // consertar a heap
                // pq[N/2].chave < pq[N].chave
}

void PQchange(int i){
    // atualizar data[i] na fila
    // data[i] está na posição qp[i]

    fixUp(qp[i]);
    fixDown(qp[i], N);
}

void exch(int a, int b){
    // atualizar lista de indices
    // data[a] trocou de lugar na fila com data[b]
    int k = qp[a];
    qp[a] = qp[b];
    qp[b] = k;

    // atualizar fila de prioridades
    // data[a] está na posição qp[a] da fila
    pq[qp[a]] = a;

    // data[b] está na posição qp[b] da fila
    pq[qp[b]] = b;
}


/* Implementacao com array */
/* ************************* */
/* Varias filas */
/* ************************* */
typedef int Item ;
typedef struct {
    Item *qp ;
    Item *pq ;
    int N ;
} PQueue ;

PQueue *PQinit (int);
int PQempty (PQueue*);
void PQinsert (PQueue* , Item);
Item PQdelmax (PQueue*);
void PQchange (PQueue* , int);

void fixUp (PQueue* , int);
void fixDown (PQueue* , int);