#include <stdio.h>

int main(void){
    int i;

    scanf("%d", &i);

    int v[i];
    int posicao;
    posicao = 0;

    for(int j = 0; j<i; j++){
        v[i] = scanf("%d", &v[j]);

        if (v[j] < v[posicao]) {
            posicao = j;
        }
        
    }
    printf("%d\n", posicao);

}