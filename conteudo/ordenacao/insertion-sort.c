/*
insere cada elemento em sua posicão correta
em relação aos seus antecessores
*/

/*
        COMPARA COM O ANTECESSOR V[J] < V[J-1]

            l                        r
indice      0    1    2    3    4    5
v           4    2    3    6    1    5
i                i
j          j-1   j

            l                        r
indice      0    1    2    3    4    5
v           2    4    3    6    1    5
i                i
j          j-1   j

            l                        r
indice      0    1    2    3    4    5
v           2    4    3    6    1    5
i                     i
j               j-1   j

            l                        r
indice      0    1    2    3    4    5
v           2    3    4    6    1    5
i                     i
j               j-1   j

            l                        r
indice      0    1    2    3    4    5
v           2    3    4    6    1    5
i                     i
j          j-1   j

            l                        r
indice      0    1    2    3    4    5
v           2    3    4    6    1    5
i                          i
j                    j-1   j

            l                        r
indice      0    1    2    3    4    5
v           2    3    4    6    1    5
i                               i
j                         j-1   j

            l                        r
indice      0    1    2    3    4    5
v           2    3    4    1    6    5
i                               i
j                         j-1   j

            l                        r
indice      0    1    2    3    4    5
v           2    3    4    1    6    5
i                               i
j                    j-1   j

            l                        r
indice      0    1    2    3    4    5
v           2    3    1    4    6    5
i                               i
j                    j-1   j

            l                        r
indice      0    1    2    3    4    5
v           2    3    1    4    6    5
i                               i
j               j-1   j

            l                        r
indice      0    1    2    3    4    5
v           2    1    3    4    6    5
i                               i
j               j-1   j

            l                        r
indice      0    1    2    3    4    5
v           2    1    3    4    6    5
i                               i
j          j-1   j

            l                        r
indice      0    1    2    3    4    5
v           1    2    3    4    6    5
i                               i
j          j-1   j

            l                        r
indice      0    1    2    3    4    5
v           1    2    3    4    6    5
i                                    i
j                              j-1   j

            l                        r
indice      0    1    2    3    4    5
v           1    2    3    4    5    6
i                                    i
j                              j-1   j

            l                        r
indice      0    1    2    3    4    5
v           1    2    3    4    5    6
i                                    i
j                         j-1   j

como 5 > 4 ele para.

*/

// ALGORITIMO

void insertion_sort(int v[], int l, int r){
    // percorrer a partir do segundo elemento
    for( int i = l+1, i<=r; i++){
        // procurar antecessores menores que v[j]
        for( int j = i; j > l && v[j]< v[j-1]; j--){
            // Inserir na posição
            swap(v[j], v[j-1]);
        }
    }
}

/*
        COMPLEXIDADE: 0(N²)
                melhor caso O(N)
        ADAPTATIVO
        ESTAVEL
            2 3 2' 1 ----> 1 2 2' 3
        IN PLACE
*/