#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int mapa1[N][N];
    int mapa2[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mapa1[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mapa2[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int chuva_total = mapa1[i][j] + mapa2[i][j];
            printf("%d", chuva_total);
            
            if (j < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}