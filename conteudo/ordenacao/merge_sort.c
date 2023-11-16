/*
MERGE SORT JÁ É UM ALGORITIMO DE ORDENAÇÃO EFICIENTE
*/

/*
DIVIDIR E CONQUISTAR
        divide em partes pequenas
        ordenas essas partes
        combina essas partes ordenadas
        ate formar uma unica sequencia ordenada
*/

// ABORDAGEM TOP-DOWN
/*
    A cada chamada, divide a entrada em sub-vetores para serem ordenados
        merge_sort(int *v, int l , int r)
    Quando chegar em um tamanho unitário, está ordenado em 1
    Volta fazendo o merge do ordenado
        merge(int *v, int l , int meio, int r)
        utiliza um vetor auxiliar
*/


/*
    Dividir m = (l+r)/2

            l            m              r
indices     0  1  2   3  4  5  6  7  8  9
vetor      [7  2  9  10  4  3  1  8  6  5] 


            l            m                r
indices     0  1  2   3  4   5  6  7  8  9
vetor      [7  2  9  10  4] [3  1  8  6  5] 

            l     m      r
indices     0  1  2   3  4   5  6  7  8  9
vetor      [7  2  9  10  4] [3  1  8  6  5] 

            l     m        r
indices     0  1  2    3  4   5  6  7  8  9
vetor      [7  2  9] [10  4] [3  1  8  6  5] 

            l  m  r
indices     0  1  2    3  4   5  6  7  8  9
vetor      [7  2  9] [10  4] [3  1  8  6  5] 

            l  m    r
indices     0  1   2    3  4   5  6  7  8  9
vetor      [7  2] [9] [10  4] [3  1  8  6  5]

           l=m r
indices     0  1   2    3  4   5  6  7  8  9
vetor      [7  2] [9] [10  4] [3  1  8  6  5]

           l=m r
vetor      [7] [2] [9] [10  4] [3  1  8  6  5]
indices     0   1   2    3  4   5  6  7  8  9

k          [     ]
vetor      [7] [2] [9] [10  4] [3  1  8  6  5]
indices     0   1   2    3  4   5  6  7  8  9

k          [2   7]
vetor      [7] [2] [9] [10  4] [3  1  8  6  5]
indices     0   1   2    3  4   5  6  7  8  9

k          [2   7   9]
vetor      [7] [2] [9] [10  4] [3  1  8  6  5]
indices     0   1   2    3  4   5  6  7  8  9

k          [2   7   9] [      ]
vetor      [7] [2] [9] [10] [4] [3  1  8  6  5]
indices     0   1   2    3  4   5  6  7  8  9

k          [2   7   9] [4   10]
vetor      [7] [2] [9] [10] [4] [3  1  8  6  5]
indices     0   1   2    3  4   5  6  7  8  9

k          [2   4   7   9   10]
vetor      [7] [2] [9] [10] [4] [3  1  8  6  5]
indices     0   1   2    3  4   5  6  7  8  9

                        ...
            MESMA COISA PARA O OUTRO LADO
                        ...

k          [1  2  3  4  5  6  7  8  9  10]

*/


void merge_sort(int *v, int l, int r){
    if(l >= r) return;
    int m = (r+l)/2;

    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge(v, l, m, r);
}

merge(int *v, int l, int m, int r){
    tam = r-l+1;

    // alocar espaço auxiliar
    int *aux = malloc(sizeof(int)*tam);

    // auxiliares

    // inicio do subvetor esq
    int i = l;
    // inicio subvetor dir
    int j = m+1;
    // inicio subvetor auxiliar
    int k = 0;

    // percorrer subvetores
    while(i<= m && j<=r){
        // testar subvetores
        if (v[i] <= v[j]){
            // ordenar no vetor auxiliar
            aux[k++] = v[i++]
        }
        else{
            // ordenar no vetor auxiliar
            aux[k++] = v[j++]
        }
    }

    // verifica se tem elementos no vetor esq
    while(i<=m){
        aux[k++] = v[i++];
    }
     // verifica se tem elementos no vetor dir
    while(j<=r){
        aux[k++] = v[j++];
    }

    // indice do aux
    k = 0;

    // indice v
    for(i = l; i<= r; i++){
        // cpoiar o aux[k] para v[i]
        v[i] = aux[k++];
    }

    // libera memoria
    free(aux);
}

/*
    COMPLEXIDADE: O(N logN) linearítimica
    NÃO INPLACE
    NÃO ADAPTATIVO
    ESTAVEL
*/


// TAMBEM TEM COMO FAZER O MERGE BOTTOM UP
/*
Abordagem Bottom-Up
    ▶ merge 1 por 1
        ⋆ sub-vetores de tamanho 1
        ⋆ resultando em um sub-vetor de tamanho 2
    ▶ merge 2 por 2:
        ⋆ sub-vetores de tamanho 2
        ⋆ resultando em um sub-vetor de tamanho 4
    ▶ e assim por diante
Consiste em uma sequencia de passos pelo vetor inteiro, fazendo sz por sz uniões
Começando por 1 por 1 e dobrando em cada passo
Complexidade: mesma da abordagem top-down
*/


void mergeBU_sort{
    int tam = (r-l+1);

    for(int sz = 1; sz< tam; sz = 2*sz){
        for(int lo = l; lo<tam-sz; lo+=2*sz){
            int hi = lo+2*sz-1;
            if (hi > tam -1){
                hi = tam - 1;
            }
            merge(v, lo, lo+sz-1, hi);
        }
    }
}


/*QUESTÃO QUE CAIU ANO PASSADO*/

merge_sort(v, 0, 5)
meio = (5+0)/2 // = 2
merge_sort(v,0,meio=2)  // : esquerda

    m = (2+0)/2 // = 1
    merge_sort(v,0,1) // : esquerda

        m = (1+0)/2 // = 0
        merge_sort(v, 0, 0) // : esquerda
        merge_sort(v, 1, 1) // : direita
        merge(v, 0, 0, 1)
        // [6 5] 3 1 2 4 : 5 6

    merge_sort(v, 2, 2) // direita
    merge(v, 0, 1, 2)
    // 5 6 3 1 2 4 : 3
    // 5 6 3 1 2 4 : 3 5
    // 5 6 3 1 2 4 : 3 5 6

merge_sort(v, meio+1=3, 5) // : direita
    merge_sort(v, 3, 4) // : esquerda
    m = (4+3)/2 = 3
        m = (5+3)/2 = 4
        merge_sort(v, 3, 3) // : esquerda
        merge_sort(v, 4, 4) // : direita
        merge(v, 3, 3, 4)
        // 5 6 1 2 4 : 1 2
    merge_sort(v, 5, 5) // : direita
    merge(v, 3, 4, 5)
    // 3 5 6 1 2 4 : 1
    // 3 5 6 1 2 4 : 1 2
    // 3 5 6 1 2 4 : 1 2 4

merge(v, 0, 2, 5)
// 3 5 6 1 2 4 : 1
// 3 5 6 1 2 4 : 1 2
// 3 5 6 1 2 4 : 1 2 3
// 3 5 6 1 2 4 : 1 2 3 4
// 3 5 6 1 2 4 : 1 2 3 4 5
// 3 5 6 1 2 4 : 1 2 3 4 5
// 3 5 6 1 2 4 : 1 2 3 4 5 6
