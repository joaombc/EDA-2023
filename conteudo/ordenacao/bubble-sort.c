/*
    VAMOS VERIFICAR SE V[J] > V[J+1]
    se for maior fazemos o swap entre os lugares dos dois
    assim, o maior elemento vai flutuano para o final da lista

            l              r
indice      0    1    2    3    4    5
v           3    2    4    6    1    5
ij          j    j+1

            l              r
indice      0    1    2    3    4    5
v           2    3    4    6    1    5
ij          j    j+1

            l              r
indice      0    1    2    3    4    5
v           2    3    4    6    1    5
ij               j    j+1

            l              r
indice      0    1    2    3    4    5
v           2    3    4    6    1    5
ij                    j    j+1


            l              r
indice      0    1    2    3    4    5
v           2    3    4    6    1    5
ij                         j    j+1

            l              r
indice      0    1    2    3    4    5
v           2    3    4    1    6    5
ij                         j    j+1

            l              r
indice      0    1    2    3    4    5
v           2    3    4    1    6    5
ij                              j    j+1

            l              r
indice      0    1    2    3    4    5
v           2    3    4    1    5    6
ij                              j    j+1

            l              r
indice      0    1    2    3    4    5
v           2    3    4    1    5    6
ij          j    j+1

            l              r
indice      0    1    2    3    4    5
v           2    3    4    1    5    6
ij                    j    j+1

            l              r
indice      0    1    2    3    4    5
v           2    3    1    4    5    6
ij                    j    j+1
                        ...
            l              r
indice      0    1    2    3    4    5
v           2    3    1    4    5    6
ij          j    j+1

            l              r
indice      0    1    2    3    4    5
v           2    3    1    4    5    6
ij               j    j+1

            l              r
indice      0    1    2    3    4    5
v           2    1    3    4    5    6
ij               j    j+1
                        ...

            l              r
indice      0    1    2    3    4    5
v           2    1    3    4    5    6
ij          j    j+1

            l              r
indice      0    1    2    3    4    5
v           1    2    3    4    5    6
ij          j    j+1
                        ...
            l              r
indice      0    1    2    3    4    5
v           1    2    3    4    5    6
ij                              j    j+1

*/

//Algoritimo

void bubble_sort(int v[], int l, int r){
    for(; r>l; r--){
        for(int j= l; j<r; j++){
            if (v[j]>v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
}

/*
        COMPLEXIDADE O(N²)
        ADAPTATIVO
        ESTAVEL
        IN PLACE
*/

// Algoritimo otimizado
// verifica se ele já está orenado

void bubble_sort(int v[], int l, int r){
    int swap = 1
    for(; r>l && swap; r--){
        for(int j= l; j<r; j++){
            if (v[j]>v[j+1]){
                exch(v[j], v[j+1]);
                swap = 1;
            }
        }
    }
}
