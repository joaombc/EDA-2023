#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int min(int i, int j) {
    if (i < j) return i;
    else return j;
}

void solve() {
    int* D = malloc(61 * sizeof(int));
    int* E = malloc(61 * sizeof(int));

    int m;
    char l;
    while (scanf("%d %c", &m, &l) != EOF) {
        if (l == 'D') D[m]++;
        else E[m]++;
    }

    int ans = 0;
    for (int i = 1; i < 61; i++) ans += min(D[i], E[i]);
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    //scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}