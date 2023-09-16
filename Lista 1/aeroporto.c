#include <stdio.h>

int main() {
    int A, V;
    int teste = 1;

    while (1) {
        scanf("%d %d", &A, &V);

        if (A == 0 && V == 0)
            break;

        if (A < 1 || A > 100 || V < 0 || V > 10000) {
            return 1;
        }

        int aeroportos[A + 1];
        int max_trafego = 0;

        for (int i = 1; i <= A; i++) {
            aeroportos[i] = 0;
        }

        for (int i = 0; i < V; i++) {
            int X, Y;
            scanf("%d %d", &X, &Y);

            if (X < 1 || X > A || Y < 1 || Y > A || X == Y) {
                return 1;
            }

            aeroportos[X]++;
            aeroportos[Y]++;

            if (aeroportos[X] > max_trafego) {
                max_trafego = aeroportos[X];
            }

            if (aeroportos[Y] > max_trafego) {
                max_trafego = aeroportos[Y];
            }
        }

        printf("Teste %d\n", teste);

        for (int i = 1; i <= A; i++) {
            if (aeroportos[i] == max_trafego) {
                printf("%d ", i);
            }
        }

        printf("\n\n");
        teste++;
    }

    return 0;
}