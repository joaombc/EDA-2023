#include <stdio.h>

int soma = 0;
void resultado(char* numero, int i) {

    if (numero[i] == '\0'){
        return;
    }
    soma += numero[i] - '0';
    return resultado(numero, i + 1);
}

int main() {
    char* numero = malloc(101);
    scanf("%s", numero);

    resultado(numero, 0);
    printf("%d\n", soma);
    return 0;
}
