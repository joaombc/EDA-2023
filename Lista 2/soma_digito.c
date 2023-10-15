#include <stdio.h>

int somaDigitos(int n) {
    if (n == 0) {
        return 0; 
    } else {
        return n % 10 + somaDigitos(n / 10);
    }
}

int main() {
    unsigned int n; 
    scanf("%u", &n);

    int resultado = somaDigitos(n);

    printf("%d\n", resultado);

    return 0;
}