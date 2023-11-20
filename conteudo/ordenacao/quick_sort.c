/*
Quick sort é um algoritimo de ordenação elementar

Metodo de dividir e conquistar
particiona em subvetores
ordena cada subvetor independentemente

Merge x Quick
    ▶ merge:
        ⋆ Divide
        ⋆ Ordena separadamente
        ⋆ Combina reordenando
        ⋆ Conquista um vetor mais ordenado
    ▶ quick:
        ⋆ Separa os elementos baseados em 1 elemento
        ⋆ Conquista um elemento ordenado e dois sub-vetores pseudo-ordenados
        ⋆ Divide e repete para os sub-vetores

*/

void quick_sort(int *v, int l, int r){
    if (r <=l){
        return;
    }

    int p = separa(v,l,r);
    quick_sort(v, l, p-1);
    quick_sort(v, p+1, r);
}

int separa(int *v, int l, int r){
    int i = l-1;
    int j = r;
    int pivo = v[r];

    // procurar maior e menor enquanto i e j n se encotram
    while(i<j){
        // procurar o maior enquanto v[i] for menor que o pivot
        while(v[i++]< pivo);
        // procurar o menor enquanto o o v[j] for >= pivot
        while (v [--j] >= pivot && j > l );

        // se i < j swap entre eles
        if (i<j){
            swap(v[i],v[j]);
        }
    }

    // se i>=j torcar o pivo com o ultimo maior
    swap(v[i], v[r]);
    
    // retornar a nova posição do pivo
    return 1;
}

/*
▶ Os apontadores i e j não podem ultrapassar os limites pois serão usados nos
swaps
▶ Opções:       //linha 39 no codigo
    ⋆ anda depois verifca
        while(v[++i] < pivot);
        while(pivot < v[--j] && j>l);
        Se começa andando, tem que inicializar antes da posição ser verifcada
        i = l-1;
        j = r;
    ⋆ verifca depois anda
        while(v[i] < pivot) i++;
        while(pivot < v[j] && j>l) j--;
        Se anda depois, tem que inicializar na posição ser verifcada
        i = l;
        j = r-1;
▶ Nunca ultrapassa r, pois sempre chega no pivot
*/

/*
    INPLACE
    NÃO ESTÁVEL
    NÃO ADAPTATIVO
    COMPLEXIDADE:   
        MELHOR CASO E CASO MÉDIO
        O(N logN)  linearítimico
        PIOR CASO
        O(N²)


*/

// MEDIANA DE 3

/*

Mediana de três
    ▶ Pivô: usar a mediana de uma pequena amostra de itens
    ▶ Melhora o partiocionamento
    ▶ Pivô mais à direita
        ⋆ Menor para left
        ⋆ Mediana para right

    a mediana de 3 é utiliada pois diminui as chances de ter o
    pior caso.
    
*/

void quicksort(Item *v, int l, int r){
    int j;
    if(r<=l){
        return;
    }
    // codigo bruno ribas 
    cmpexch(v[(l+r)/2],v[r]);
    cmpexch(v[l],v[[(l+r)/2]]);
    cmpexch(v[r],v[[(l+r)/2]]);

    j = separa(v,l,r);
    quicksort(v,l,j-1);
    quicksort(v,j+1,r);
}


/*ESSA QEUSTÃO CAIU ANO PASSADO AN PROVA*/

quick_sort(v, 0, 4) // : 5 2 4 1 3
    p = separa(v, 0, 4)
        // 5 2 4 1 [3]
        // 1 2 4 5 [3]
        // 1 2 [3] 5 4
    // 1 2 [3] 5 4
    quick_sort(v, 0, 1) // : 1 2 3 5 4
        p = separa(v, 0, 1)
            //1 2
        quick_sort(v, 0, 0) // : 1
        quick_sort(v, 2, 1)
        // 1 2
    // 1 2 3 5 4
    quick_sort(v, 3, 4) // : 1 2 3 5 4
        p = separa(v, 3, 4)
            // 5 4
            // 4 5
        quick_sort(v, 3, 2)
        quick_sort(v, 4, 4) // : 5
        // 4 5
    // 1 2 3 4 5



/*
ordenação com mediana de 3
*/

v = [9 8 7 6 5 4]

quicksort(v,0,5)

/*
vai comparar 9,7 e 4, para saber qual é a mediana, que no caso é 7.
7 é colocado na última posição, 4 na primeira e 9 na segunda
*/

v = [4 8 9 6 5 7]
    j = separa(v,0,5)
v = [4 6 9 8 5 7]
v = [4 6 5 8 9 7]
v = [4 6 5 7 9 8]
// todos a direita de 7 são maiores que ele, e todos a esquerda são menores
// j = 3

    //vamos focar na parte à esquerda da nossa mediana.
    quicksort(v,0,2) // l = 0, r = 2, m = 1

v = [[4 6 5] 7 9 8]
v = [[4 5 6] 7 9 8]
v = [[4 6 5] 7 9 8]

        j = separa(v,0,2)

v = [[4 5 6] 7 9 8]
//j = 1

            quicksort(v,0,0)
            quicksort(v,2,2)
    //vamos focar na parte à direita da nossa mediana.
    quicksort(v,4,5)

v = [4 5 6 7 [9 8]]
        j = separa(v,4,5)

v = [4 5 6 7 [8 9]]
        j = 4
        quicksort(v,3,4)
        quicksort(v,5,5)
v = [4 5 6 7 8 9]
