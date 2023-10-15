#include <stdio.h>
#include <string.h>

void imprimirAoContrario(char *str, int index) {
    if (index < 0) {
        return;
    }
    
    printf("%c", str[index]);
    
    imprimirAoContrario(str, index - 1);  
}

int main() {
    char str[501];
    scanf("%s", str);

    int length = strlen(str);
    imprimirAoContrario(str, length - 1);

    printf("\n");

    return 0;
}