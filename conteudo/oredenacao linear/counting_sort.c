/*
Ordenar contando as chaves em um vetor auxiliar:
    ▶ Cada índice é uma chave: limita quantidade de chaves
    ▶ Determina a posição da uma chave, contando quantas chaves menores existem
    ▶ Histograma dos números: distribuição das frequências
    ▶ Cada chave é reposicionada na posição definitiva
*/

/*
v [2 3 3 4 1 3 4 3 1 2 2 1 2 4 3 4 4 2 3 4]
    ▶ Frequências:
        ⋆ 0: 0 vezes
        ⋆ 1: 3 vezes
        ⋆ 2: 5 vezes
        ⋆ 3: 6 vezes
        ⋆ 4: 6 vezes
    ▶ Ordenando:
        ⋆ zero 0's, três 1's, cinco 2's, seis 3's, seis 4's
v [1 1 1 2 2 2 2 2 3 3 3 3 3 3 4 4 4 4 4 4]
*/

/*
Etapa 1: contar as frequências
    ▶ Para o intervalo de chaves: 0 até R − 1
    ▶ Utiliza-se: count[R+1]
    ▶ Cada chave i em 0 até R − 1 = count[i]
    ▶ Cada count[i] = frequência da chave i − 1 (imediatamente < i)
*/

// memset (count , 0 , sizeof ( int )*(R +1) )
for (i =0; i <= R; i ++){
    count [i] = 0;
}
for (i= l; i <= r; i ++){
    count [v[i ]+1]++;
}

/*
Etapa 2: Calculando as posições/índices através das frequências
    ▶ Se count[i] contém a quantidade de chaves imediatamente menores que i,
    ▶ Então, se, count[i] = count[i] + count[i-1] + ... + count[0],
    ▶ count[i] vai conter a quantidade de todas as chaves menores que i,
    ▶ count[i] vai conter a quantidade de posições que devem ser "puladas" para a
    inserção das chaves menores que i,
    ▶ Portanto, count[i] contém a distância de 0 até a chave i (posição de i)
*/

for (i =1; i <= R; i ++){
    count[i] += count[i- 1];
}

/*
Etapa 3: distribuindo as chaves
    ▶ count[R+1]: tabela de índices
    ▶ aux[r-l+1]: auxiliar para copiar as chaves na ordem,
        ⋆ count[ v[i] ]: posição ordenada da chave v[i]
        ⋆ aux[count[v[i]]] = v[i]: v[i] em sua posição ordenada em aux[ ]
        ⋆ count[ v[i] ]++: próxima v[i] em sua posição ordenada em aux[ ]
*/

for ( i = l; i <= r; i ++) {
    aux[count[v[i]]] = v[i];
    count[v[i]]++;
}

//CODIGO COMPLETO

#define MAX 10000
#define R 5

int aux [ MAX ];

void countingsort ( int *v , int l , int r) {
    int i , count [R +1];

    // zerando
    for (i = 0; i <= R; i ++) {
        count [i] = 0;
    }

    // frequencias
    for (i = l; i <= r; i ++) {
        count [v[i ] + 1]++;
    }

    // posições
    for (i = 1; i <= R; i ++) {
        count [i] += count [ i- 1];
    }

    // distribuição
    for (i = l; i <= r; i ++) {
        aux [ count [v[ i ]]] = v[ i ];
        count [ v[i ]]++;
    }

    //cópia : a partir de aux [0]
    for (i = l; i <= r; i ++) {
        v [i] = aux [ i-l ];
    }
}

/*
ESTAVEIS
O(N + K)
    N = qtd de numeros que temos na array
    K = range of numbers that we could have
NÃO INPLACE
NÃO ADAPTATIVO
*/


/*
v[2,0,3,2,1,0,3,0,4,2]
count[           ]
aux[                    ]
*/
    int i, count[R+1];
    for (i = 0; i <= R; i++)
        count[i] = 0;
    // vamos colocar zero em todas as posições 
    // dos vetor count
/*

v[2,0,3,2,1,0,3,0,4,2]
count[0,0,0,0,0,0]
aux[                    ]
*/
    for (i = l; i <= r; i++)
        count[v[i] + 1]++;
    //vamos percorrer o vetor v, 
    // e salvar a qtd de recorrência desse 
    // número na posição count[v[i]+1]
    // passa para o pŕoximo numero no vetor v

/*
v[*2*,0,3,2,1,0,3,0,4,2]
count[0,0,0,*1*,0,0]
aux[                    ]

v[2,*0*,3,2,1,0,3,0,4,2]
count[0,*1*,0,1,0,0]
aux[                    ]

v[2,0,*3*,2,1,0,3,0,4,2]
count[0,1,0,1,*1*,0]
aux[                    ]

v[2,0,3,*2*,1,0,3,0,4,2]
count[0,1,0,2,1,0]
aux[                    ]

v[2,0,3,2,*1*,0,3,0,4,2]
count[0,1,*1*,2,1,0]
aux[                    ]

v[2,0,3,2,1,*0*,3,0,4,2]
count[0,*2*,1,2,1,0]
aux[                    ]

v[2,0,3,2,1,0,*3*,0,4,2]
count[0,2,1,2,*2*,0]
aux[                    ]

v[2,0,3,2,1,0,3,*0*,4,2]
count[0,*3*,1,2,2,0]
aux[                    ]

v[2,0,3,2,1,0,3,0,*4*,2]
count[0,3,1,2,2,*1*]
aux[                    ]

v[2,0,3,2,1,0,3,0,4,*2*]
count[0,3,1,*3*,2,1]
aux[                    ]

*/

    for (i = 1; i <= R; i++)
        count[i] += count[i-1];
    //no vetor count vamos somar a posição i 
    //com i-1 para sabermos quantos numeros 
    // menores temos antes

/*

v[2,0,3,2,1,0,3,0,4,2]
count[0,3,1,3,2,1]
aux[                    ]

v[2,0,3,2,1,0,3,0,4,2]
count[0,3,4,3,2,1]
aux[                    ]

v[2,0,3,2,1,0,3,0,4,2]
count[0,3,4,7,2,1]
aux[                    ]

v[2,0,3,2,1,0,3,0,4,2]
count[0,3,4,7,9,1]
aux[                    ]

v[2,0,3,2,1,0,3,0,4,2]
count[0,3,4,7,9,10]
aux[                    ]
*/

    for (i = l; i <= r; i++) {
        aux[count[v[i]]] = v[i];
        count[v[i]]++;
    }

    // ve qual numero esta no vetor v, 
    // acessa sua posição no count, 
    // vê qual é sua posição final no aux 
    // e move uma posição

/*

v[*2*,0,3,2,1,0,3,0,4,2]
count[0,3,*4*,7,9,10]
aux[ , , , ,2, , , , , ]

v[*2*,0,3,2,1,0,3,0,4,2]
count[0,3,*5*,7,9,10]
aux[ , , , ,2, , , , , ]

v[2,*0*,3,2,1,0,3,0,4,2]
count[*0*,3,5,7,9,10]
aux[0, , , ,2, , , , , ]

v[2,*0*,3,2,1,0,3,0,4,2]
count[*1*,3,5,7,9,10]
aux[0, , , ,2, , , , , ]

v[2,0,*3*,2,1,0,3,0,4,2]
count[1,3,5,*7*,9,10]
aux[0, , , ,2, , ,3, , ]

v[2,0,*3*,2,1,0,3,0,4,2]
count[1,3,5,*8*,9,10]
aux[0, , , ,2, , ,3, , ]

v[2,0,3,*2*,1,0,3,0,4,2]
count[1,3,*5*,8,9,10]
aux[0, , , ,2,2, ,3, , ]

v[2,0,3,*2*,1,0,3,0,4,2]
count[1,3,*6*,8,9,10]
aux[0, , , ,2,2, ,3, , ]

v[2,0,3,2,*1*,0,3,0,4,2]
count[1,*3*,6,8,9,10]
aux[0, , ,1,2,2, ,3, , ]

v[2,0,3,2,*1*,0,3,0,4,2]
count[1,*3*,6,8,9,10]
aux[0, , ,1,2,2, ,3, , ]

v[2,0,3,2,*1*,0,3,0,4,2]
count[1,*4*,6,8,9,10]
aux[0, , ,1,2,2, ,3, , ]

v[2,0,3,2,1,*0*,3,0,4,2]
count[*1*,4,6,8,9,10]
aux[0,0, ,1,2,2, ,3, , ]

v[2,0,3,2,1,*0*,3,0,4,2]
count[*2*,4,6,8,9,10]
aux[0,0, ,1,2,2, ,3, , ]

v[2,0,3,2,1,0,*3*,0,4,2]
count[2,4,6,8,*9*,10]
aux[0,0, ,1,2,2, ,3,3, ]

v[2,0,3,2,1,0,*3*,0,4,2]
count[2,4,6,8,*10*,10]
aux[0,0, ,1,2,2, ,3,3, ]

v[2,0,3,2,1,0,3,*0*,4,2]
count[*2*,4,6,8,10,10]
aux[0,0,0,1,2,2, ,3,3, ]

v[2,0,3,2,1,0,3,*0*,4,2]
count[*3*,4,6,8,10,10]
aux[0,0,0,1,2,2, ,3,3, ]

v[2,0,3,2,1,0,3,0,*4*,2]
count[3,4,6,8,10,*10*]
aux[0,0,0,1,2,2, ,3,3,4]

v[2,0,3,2,1,0,3,0,*4*,2]
count[3,4,6,8,10,*11*]
aux[0,0,0,1,2,2, ,3,3,4]

v[2,0,3,2,1,0,3,0,4,*2*]
count[3,4,6,*8*,10,11]
aux[0,0,0,1,2,2,2,3,3,4]

v[2,0,3,2,1,0,3,0,4,*2*]
count[3,4,6,*9*,10,11]
aux[0,0,0,1,2,2,2,3,3,4]
*/

    for (i = l; i <= r; i++)
        v[i] = aux[i-l];

    // copia o aux para o v[]

/*
v[0,0,0,1,2,2,2,3,3,4]
count[3,4,6,9,10,11]
aux[0,0,0,1,2,2,2,3,3,4]
*/
