#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int len(int n, char* string) {
    if (string[n] == '\0') return n - 1;
    return len(n + 1, string);
}

void solve(int n, char* string) {
    if (n < 0) return;
    printf("%c", string[n]);
    solve(n - 1, string);
}

int main() {
    char* string = malloc(501);
    scanf("%s", string);
    solve(len(0, string), string);
    printf("\n");
    return 0;
}