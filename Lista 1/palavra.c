#include <stdio.h>

int main(void){
    char str[1001];
    scanf("%s", str);

    int tamanho = 0;

    for( int i = 0; str[i]!='\0'; i++){
        tamanho++;
    }

    printf("%d\n", tamanho);

}