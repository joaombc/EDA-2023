#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

char* solve(int t) {
    int* cars = malloc(t * sizeof(int)), init = 1;
    for (int i = 0; i < t; i++) scanf(" %d", &cars[i]);

    stack* sk = make_stack();
    for (int i = 0; i < t; i++) {
        if (cars[i] == init) init++;
        else {
            while (!empty(sk) && top(sk) == init) {
                pop(sk);
                init++;
            }

            if (!empty(sk) && top(sk) < cars[i]) return "no";
            push(sk, cars[i]);
        }
    }
    return "yes";
}

int main() {
    int t;

    while (true) {
        scanf("%d", &t);
        if (t == 0) break;

        printf("%s\n", solve(t));
    }

    return 0;
}