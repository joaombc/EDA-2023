/*
Seleciona o meor item e faz swap com o menor i
repete isso para n iterações
*/

/*
Vamos verificar se v[j]< v[menor]

            l              r
indice      0  1  2  3  4  5
v           3  2  4  6  1  5
ij          i  j

            l              r
indice      0  1  2  3  4  5
v           3  2  4  6  1  5
ij          i           j
                SWAP            ele continua percorrendo ate o fim porem ele já pegou o indice 4 como o elemnto menor.

            l              r
indice      0  1  2  3  4  5
v           1  2  4  6  3  5
ij             i  j

            l              r
indice      0  1  2  3  4  5
v           1  2  4  6  3  5
ij             i              j

            l              r
indice      0  1  2  3  4  5
v           1  2  4  6  3  5
ij                i  j

            l              r
indice      0  1  2  3  4  5
v           1  2  4  6  3  5
ij                i     j

            l              r
indice      0  1  2  3  4  5
v           1  2  3  6  4  5
ij                i     j

            l              r
indice      0  1  2  3  4  5
v           1  2  3  6  4  5
ij                   i  j

            l              r
indice      0  1  2  3  4  5
v           1  2  3  4  6  5
ij                   i  j

            l              r
indice      0  1  2  3  4  5
v           1  2  3  4  6  5
ij                      i  j

            l              r
indice      0  1  2  3  4  5
v           1  2  3  4  5  6
ij                      i  j
*/


// ALGORITIMO

void selection_sort(int v[], int l, int r){
    int menor;
    for (int i = l; i < r; i++){
        menor = i;
        for (int j = i+1; j<=r; j++){
            if(v[j]<v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            swap(v[i],v[menor]);
        }
    }
}

/*
        COMPLEXIDADE: O(N²)
        NÃO ADAPTATIVO
        NÃO ESTAVEL
                4 3 4' 1 ---> 1 3 4' 4
        IN-PLACE
*/