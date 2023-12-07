void heap_sort ( Item *v , int l , int r ) {
    pq = v + l - 1; // fila de prioridades constru ídaem v
                    // uma posi ção anterior a v[l]
                    // se l=0 -> pq [1] = v [0]
    N = r - l +1;

    // construção da heap - 2 * N
    for(int k = N /2; k >=1; k - - ){
        fixDown (k , N ) ;
    }

    // reorganiza a heap a cada remoção - 2*N*logN
    while (N >1){
        exch ( pq [1] , pq [ N ]) ;
        fixDown (1 , - - N ) ;
    }
}

/*
Complexidade: cerca de 2 ∗ N ∗ log N + 2 ∗ N comparações
    2 ∗ N na construção da heap
    2 ∗ N ∗ log N no conserto da heap (segunda fase)
    O(n ∗ log n)
IN PLACE
ESTAVEL

*/


/*
[2,8,5,3,9,1]
                            2
                          /  \
                        8     5
                      /  \   /
                    3    9  1

        // 1 create maxheap -> achar maior numero
        // 2 remove o maior numero -> swap com o numero no fianl da array
        // 3 coloca ele no final

[9,8,5,3,2,1]
                            9
                          /  \
                        8     5
                      /  \   /
                    3    2  1

[1,8,5,3,2,9] -> o nove ficou ordenado
                            1
                          /  \
                        8     5
                      /  \   /
                    3    2  9

[1,8,5,3,2,9] 
                            1
                          /  \
                        8     5
                      /  \   /
                    3    2  9

        fazemos fixdown no 1

[8,3,5,1,2,9] 
                            8
                          /  \
                        3     5
                      /  \   /
                    1    2  9

[8,3,5,1,2,9] 
                            8
                          /  \
                        3     5
                      /  \   /
                    1    2  9
        swap da raiz com a parte não ordenada do nosso vetor

[2,3,5,1,8,9] 
                            2
                          /  \
                        3     5
                      /  \   /
                    1    8  9

[2,3,5,1,8,9]  -> 8 ordenado, e fixdown no 2

                            5
                          /  \
                        3     2
                      /  \   /
                    1    8  9

[1,3,2,5,8,9] 
                            1
                          /  \
                        3     2
                      /  \   /
                    5    8  9

[3,1,2,5,8,9] 
                            3
                          /  \
                        1     2
                      /  \   /
                    5    8  9
                    max heap

[2,1,3,5,8,9] 
                            2
                          /  \
                        1     3
                      /  \   /
                    5    8  9


[1,2,3,5,8,9] 
                            1
                          /  \
                        2     3
                      /  \   /
                    5    8  9
*/