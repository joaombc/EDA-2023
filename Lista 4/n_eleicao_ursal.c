/*
A cada 4 anos o pacato país de Nlogônia passa por um processo importante. Os cidadãos escolhem quais serão os seus representantes nas maiores esferas governamentais do país e do mundo!

Para agilizar o processo de eleição, o país resolveu implantar um sofisticado sistema de votação chamado ‘U.R.S.A.L’ (Urna Realmente Segura Amparada Legalmente). Neste maravilhoso sistema os compatriotas podem escolher os seus candidatos preferidos apenas digitando o número e por fim pressionando a tecla “confirma”.

Para justificar o enorme valor gasto pela ‘U.R.S.A.L’ o Serviço de Eleição do País (SEdP) prometeu que o resultado sairia pouco depois dos términos das votações. O problema é que são tantos votos, mas tantos votos, que o sistema de contagem não consegue realizar a conta rapidamente.

A fim de cumprir o tempo previsto, o SEdP contatou você para implementar o programa que calcula o resultado da eleição.

Os eleitores podem escolher o seu candidato ( escolhendo um número correto), podem anular ou deixar o voto em branco (que é registrado com um código negativo).

Os eleitores votarão para 4 cargos distintos:

O presidente possui apenas 2 dígitos, ex: 97
O senador possui 3 dígitos e cada eleitor escolherá 2, ex: 973
O dep.Fed possui 4 dígitos, ex: 9734
O dep.Est possui 5 dígitos, ex: 97345
Critérios de vitória:

A vitória sempre será por maioria simples, pode não parecer mas, os cidadãos de Nlogônia tentam ser práticos.

A única exceção está para o presidente, que deve obter a maioria dos votos (51%) para garantir a vitória.

A maioria simples é computada somente para os votos válidos, ou seja, brancos e nulos não entram no totais de votos.

Um partido é identificado pelos 2 primeiros dígitos do código de um candidato.

A quantidade de candidatos por partido para cada cargo é no máximo o maior número de combinações dos números, desde que os dois primeiro dígitos não mudem.

Para a eleição serão eleitos:

1 presidente;
S senadores;
F dep.Fed e;
E dep.Est.
Entrada
A entrada é composta por um único caso de teste contendo diversas linhas.

A primeira linha de um caso de teste possui 3 números inteiros, sendo eles 
1
≤
�
,
�
,
�
≤
2
31
, representando, respectivamente, a quantidade de Senadores, dep.Fed e dep.Est que devem ser eleitos.

As próximas linhas, do caso de teste, serão compostas por um único número, representando, o candidato escolhido por algum eleitor, ou um voto inválido (representado por um número negativo).

Saída
A saída para o caso de teste será composta por diversas linhas. A primeira linha da saída deve conter dois números, o primeiro com a contagem de votos válidos totais (independente do cargo) e o segundo com a contagem de votos inválidos.

A segunda linha deverá conter o código do presidente eleito ou a frase Segundo Turno.

As próximas 
3
 linhas, possuem a lista dos candidatos eleitos para, respectivamente, Senador, dep.Fed e dep.Est. A listagem dos eleitos devem ser separadas por espaço e ordenadas pela quantidade de votos (do maior para o menor). Havendo empate, tem preferência o candidato de maior número.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;
typedef struct pair {
    ll code, votes;
} pair;

void merge(pair* arr, int p, int q, int r) {
    pair* z = (pair*)malloc((r - p) * sizeof(pair));

    int i = p, j = q, k = 0;
    while (i < q && j < r) z[k++] = arr[i].votes <= arr[j].votes ? arr[i++] : arr[j++];

    while (i < q) z[k++] = arr[i++];
    while (j < r) z[k++] = arr[j++];

    for (i = p; i < r; i++)  arr[i] = z[i - p];
    free(z);
}

void merge_sort(pair* arr, int p, int r) {
    if (p >= r - 1) return;

    int q = p + (r - p) / 2;
    merge_sort(arr, p, q);
    merge_sort(arr, q, r);
    merge(arr, p, q, r);
}

void solve() {
    ll s, f, e, m, valid = 0, invalid = 0;
    scanf("%lld %lld %lld", &s, &f, &e);

    pair* hash = (pair*)malloc(99991 * sizeof(pair));
    for (ll i = 0; i < 99991; i++) hash[i].code = i + 10;
    while (scanf("%lld", &m) != EOF) {
        if (m >= 10) {
            hash[m - 10].votes++;
            valid++;
        }
        else invalid++;
    }

    merge_sort(hash, 0, 90);
    merge_sort(hash, 90, 990);
    merge_sort(hash, 990, 9990);
    merge_sort(hash, 9990, 99990);

    ll votes = 0;
    for (ll i = 89; i >= 0 && s; i--) votes += hash[i].votes;

    printf("%lld %lld\n", valid, invalid);

    if ((float)hash[89].votes / (float)votes >= 0.51) printf("%lld\n", hash[89].code);
    else  printf("Segundo turno\n");

    for (ll i = 989; i >= 90 && s; i--, s--) printf("%lld ", hash[i].code);
    printf("\n");
    for (ll i = 9989; i >= 990 && f; i--, f--) printf("%lld ", hash[i].code);
    printf("\n");
    for (ll i = 99989; i >= 9990 && e; i--, e--) printf("%lld ", hash[i].code);
    printf("\n");
}

int main() {
    int t = 1;
    //scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}
