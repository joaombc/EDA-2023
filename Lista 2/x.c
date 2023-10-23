#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct par {
    int primeiro, segundo;
} par;

char string[101];
par sem_x(int i, int j, char* tmp) {
    if (string[i] == '\n' || string[i] == '\0') {
        tmp[j] = '\0';
        par pr;
        pr.primeiro = i;
        pr.segundo = j;
        return pr;
    }

    if (string[i] == 'x') return sem_x(i + 1, j, tmp);
    else {
        tmp[j] = string[i];
        return sem_x(i + 1, j + 1, tmp);
    }
}

void complete_with_x(int i, int n, char* tmp) {
    if (n == i) {
        tmp[i] = '\0';
        return;
    }

    tmp[i] = 'x';
    return complete_with_x(i + 1, n, tmp);
}

int main() {
    fgets(string, sizeof(string), stdin);

    char* tmp = malloc(101 * sizeof(char));
    par end = sem_x(0, 0, tmp);
    complete_with_x(end.segundo, end.primeiro, tmp);

    printf("%s\n", tmp);
}
