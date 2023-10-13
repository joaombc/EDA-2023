#include <stdio.h>
#include <string.h>

int contarParesRecursivo(char *str, int length, int index) {
    if (index >= length - 2) {
        return 0;
    }
    
    int count = (str[index] == str[index + 2]) ? 1 : 0;
    
    return count + contarParesRecursivo(str, length, index + 1);
}

int contarPares(char *str) {
    int length = strlen(str);
    return contarParesRecursivo(str, length, 0);
}

int main() {
    char str[201];
    scanf("%s", str);

    int result = contarPares(str);

    printf("%d\n", result);

    return 0;
}