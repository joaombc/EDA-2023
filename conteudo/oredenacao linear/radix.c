/*
Comparar a estrutura das chaves
Decompondo a chave em subestruturas que a compõe:
    ▶ Números: unidades, dezenas, centenas...
    ▶ Palavras: letras
A cada iteração/recursão,
    ▶ Comparar somente parte da chave
    ▶ Ordenando parcialmente
Exemplo:
    ▶ ao procurar/posicionar uma palavra em um dicionário
    ▶ cada letra que forma a palavra
    ▶ contribui para localizar a página exata da palavra
    ▶ cada letra restringe as possibilidades de posições
*/

/*
EXEMPLO

        170 045 075 090 802 024 002 066

        ele vai olhar para a menosr unidade de agarismos e vai ordenalos

        170 090 802 002 024 045 075 066

        manteve a ordem em que vieram.
        agora olha para as dezenas e ordena

        802 002 024 045 066 170 075 090

        agora para a centena

        002 024 045 066 075 090 170 802


        foi de:
        170 045 075 090 802 024 002 066
        para:
        002 024 045 066 075 090 170 802

    
Exemplo com inteiros: partes de 1 byte
    ▶ até 255 → 0, 1, 2, 3, ..., 255
    ▶ 257 = 00000001 00000001 → 256 + 1
    ▶ 258 = 00000001 00000010 → 256 + 2
    ▶ 65792 = 00000001 00000001 00000000 → 65536 + 256 + 0

*/

/*
Radix:
    ▶ ordenar pela a raiz(radix) da representação dos dados
    ▶ extraindo o i-ésimo digito da chave
Obs.: caso a chave seja pequena não compensa a extração dos bits: use o
counting sort
*/

#define bitsbyte 8
#define bytesword 4

// 00000001 << 8 = 00000001 00000000 = 2^8 = 256
#define R (1 << bitsbyte)

// extraindo o D-é simo dí gito de N
#define digit (N ,D) (((N) >> ((D) * bitsbyte )) & (R- 1))

// ((N) >> ((D) ∗ bitsbyte)): remove os primeiros D bytes
// &(R − 1): pegando os últimos bitbytes (máscara)

/*
65792 = 00000001 00000001 00000000

// pegando o digito 1
00000001 00000001 00000000 >> 1*8 =
00000000 00000001 00000001

// aplicando a má scara
  00000000 00000001 00000001
& 00000000 00000000 11111111
---- ----- ----- ------ ----- ----
  00000000 00000000 00000001

*/

// LSD

/*
A partir dígito menos significativo (least significant digit - LSD): direita para
esquerda
    ▶ Ordena estavelmente chaves de comprimento fixo
        ⋆ Tamanho da palavra (word) que representa o dado
        ⋆ int: 4 * 8 bits = 32 bits = 4 bytes
        ⋆ strings de tamanho W
Complexidade ≈ 7 ∗ W ∗ N + 3 ∗ W ∗ R acessos:
    ▶ N chaves
    ▶ chaves de tamanho W
    ▶ cujo alfabeto são de tamanho R
R, em geral, é muito menor que N, portanto a complexidade é proporcional a
W ∗ N
*/


void radix_sortLSD (int *v , int l , int r) {
int i , w;
int aux [r-l +1] , count [R +1];

    //w -> deslocamento de bytes
    for (w =0; w < bytesword ; w ++) {
        // for (i =0; i <=R; i++) count [i] = 0;
        memset ( count , 0, sizeof (int) *( R +1) );

        // frequencias
        for (i= l; i <= r; i ++) {
            count [ digit (v[ i], w ) +1 ]++;
        }

        // posições
        for (i =1; i <= R; i ++) {
            count [i] += count [i- 1];
        }

        // distruibuição
        for (i= l; i <= r; i ++) {
            aux [ count [ digit (v[i ], w ) ] ] = v[i ];
            count [ digit (v[i ], w ) ]++;
        }

        // copiando : a partir de aux [0]
        for (i= l; i <= r; i ++) {
            v[i] = aux [i-l];
        }
    }
}


//MSD

/*
A partir dígito mais signigicativo (most significant digit - MSD): esquerda
para direita
    ▶ Ordenação de propósito geral: chaves com tamanhos variáveis
        ⋆ Conjunto de várias palavras
        ⋆ string: N * 8 bits = N * 1 byte, N variável
    ▶ Usa-se primeiro o counting sort (key-indexed counting)
    ▶ Depois, recursivamente, ordena-se os sub-vetores de cada caractere
Complexidade ≈ 7 ∗ W ∗ N + 3 ∗ W ∗ R acessos:
*/

typedef char Item ;
# define maxstring 101
# define bitsbyte 8
# define R (1 << bitsbyte ) // 00000001 < <8 = 2^8 = 256

int charAt ( char s [] , int d) {
    if (d < strlen ( s))
        return s [d ]; //d-é simo caractere
    else
        return - 1; // count [-1 + 1] = count [0]
    // count [0] = qtde . de palavras menores que d
}

// Strings : ordena para o d-é simo caractere
void radixMSD ( char a [][ maxstring ] , int l , int r , int d) {
    if(r <= l ) return ;

    char aux [r-l +1][ maxstring ];

    int count [R +1];
    memset ( count , 0, sizeof (int) *( R +1) );
    // for ( int i =0; i <=R; i++) count [i] = 0;
    // frequencia dos d-é simos caracteres
    for ( int i = l ; i <= r ; i ++)
        count [ charAt (a[i ], d) + 1]++;

    // tabela de í ndices : calculando as posi ções
    for ( int i = 1; i <= R; i ++)
        count [i] += count [i- 1];

    // redistribui as chaves : ordena em aux
    for ( int i = l ; i <= r ; i ++)
        strcpy ( aux [ count [ charAt (a [i], d) ]++] , a [i ]) ;

    // copia para o original
    for ( int i = l ; i <= r ; i ++)
        strcpy (a [i], aux [i - l ]) ;

    // ordenar por subconjunto : count [0] = já ordenadas
    for ( int i = 1; i <= R ; i ++) {
        // count [i-1] posi ção da primeira chave com o caractere i
        // count [i]-1 posi ção da ú ltima chave com o caractere i
        radixMSD (a , l + count [i- 1] , l + count [ i]-1, d +1) ;
    }
}
// Inteiros : ordena o w-é simo byte
void radix_sortMSD (int *v , int l , int r , int w) {
    if(r <= l || w < 0) return ;
    int i , aux [r-l +1] , count [ R +1];
    memset ( count , 0, sizeof (int) *( R +1) );

    for (i= l; i <= r; i ++)
        count [ digit (v[i], w) +1]++;

    for (i =1; i <= R; i ++)
        count [ i] += count [i- 1];

    for (i= l; i <= r; i ++)
        aux [ count [ digit (v [i], w) ]++] = v[i ];

    for (i= l; i <= r; i ++) 
        v[i] = aux [i-l ];

    // ordenando os que come çam por zero
    radix_sortMSD (v , l , l + count [0] -1, w- 1) ;
    for ( i = 1; i <= R; i ++)
        radix_sortMSD (v , l + count [i- 1] , l + count [i ]-1, w- 1) ;
}