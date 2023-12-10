/*
Imprimir os 100 menores numeros de um conjunto de 10⁶ numeros
*/

#define less(A,B) (vetor[A]>vetor[B])

int PQespiamin(){
    return vetor[pq[1]];
}

int main(void){
    PQinit(101);
    for(int i = 0; i<100; i++){
        int k;
        scanf("%d", &x);
        PQinsert(x);
    }

    while(scanf("%d",&x) == 1){
        PQinsert(x);
        PQdelmax();
    }
}


/*
Churrascaria da avenida
*/

// PQ baseada em indices
// fila cresente

void resolve(int n, int k, int *v){
    PQinit(k+1); // k+1 amigos
    for(int i = 0, i < k; i++){
        PQinsert(i);
    }
    printf("%d", PQespiamin());
    v[0] = 0; // pior nota
    PQchange(0);
    PQdelmin();
    int maisvelho = 1;
    int nexti = k;
    while (nexti < n){
        PQinsert(nexti);
        nexti ++;
        printf("%d", PQespiamin());
        v[maisvelho] = 0;
        PQchange(maisvelho);
        PQdelmin();
        maisvelho++;
    }

}

int main(void){
    int v[100005];
    int n, k;
    while(scanf("%d %d", &n, &k) == 2 && n!=0 && k!=0){
        for(int i = 0; i<n; i++){
            scanf("%d",&v[i]);
        }
        resolve(n,k,v);
    }
}