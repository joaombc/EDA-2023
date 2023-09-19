#include <stdio.h>

int main(void){
    char str[1001];
    scanf("%s", str);

    int tamanho =0;

    for(int i = 0; str[i] != '\0'; i++){
        tamanho++;
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    printf("\n");

}