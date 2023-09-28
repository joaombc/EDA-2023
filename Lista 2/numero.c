#include <stdio.h>

int main() {
    int n;

    while (1) {
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        int result;
        if (n <= 100) {
            result = 91;
        } else {
            result = n - 10;
        }

        printf("f91(%d) = %d\n", n, result);
    }

    return 0;
}