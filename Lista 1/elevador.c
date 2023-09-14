#include <stdio.h>

int main() {
    int N, C;
    int ocupacao = 0;

    scanf("%d %d", &N, &C);

    if (N < 1 || N > 1000 || C < 1 || C > 1000) {
        return 1; 
    }

    for (int i = 0; i < N; i++) {
        int S, E;
        scanf("%d %d", &S, &E);

        if (S < 0 || S > 1000 || E < 0 || E > 1000) {
            return 1; 
        }

        ocupacao = ocupacao - S + E;

        if (ocupacao > C) {
            printf("S\n");
            return 0;
        }
    }

    printf("N\n");

    return 0;
}