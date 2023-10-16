#include <stdio.h>

int main() {
    int v[1000];
    int limite, num;
    int soma = 0;
    int ultrapassou = 0;

    int i = 0;
    while (1) {
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        v[i] = num;
        i++;
    }

    scanf("%d", &limite);


    for (int j = 0; j < i; j++) {
        soma += v[j];
        if (soma > limite) {
            ultrapassou = j;
            soma = 0;
        }
    }

    for (int j = ultrapassou; j >= 0; j--) {
        printf("%d\n", v[j]);
    }

    return 0;
}
