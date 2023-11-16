#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

int solve(int p, int r) {
    int m, n, j;

    queue* start = make_queue();
    queue* head = make_queue();
    start->next = head;
    queue* curr = head;
    for (int i = 0; i < p; i++) {
        scanf(" %d", &m);
        curr = push(curr, m);
    }

    for (int i = 0; i < r; i++) {
        int tmp = 0;
        scanf("%d %d", &n, &j);
        for (int k = 0; k < n; k++) {
            scanf(" %d", &m);
            if (m != j) {
                curr = start;
                for (int l = 0; l < k - tmp; l++) curr = curr->next;
                curr->next = curr->next->next;
                tmp++;
            }
        }
    }

    return front(start)->data;
}

int main() {
    int p, r, t = 1;

    while (true) {
        scanf("%d %d", &p, &r);
        if (p == 0 && r == 0) break;

        printf("Teste %d\n", t++);
        printf("%d\n", solve(p, r));
    }

    return 0;
}