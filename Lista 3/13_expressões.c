#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

char string[100007];
char solve() {
    scanf("%s", string);

    stack* sk = make_stack();
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        if (string[i] == '[' || string[i] == '{' || string[i] == '(') push(sk, string[i]);
        else {
            if (!empty(sk)) {
                int y = top(sk);
                pop(sk);

                if (y != string[i] - 1 && y != string[i] - 2) return 'N';
            } else return 'N';
        }
    }

    if (!empty(sk)) return 'N';
    else return 'S';
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        printf("%c\n", solve());
    }

    return 0;
}