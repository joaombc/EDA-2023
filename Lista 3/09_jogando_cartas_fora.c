#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void solve() {
    int n;
    scanf("%d", &n);

    node* head = malloc(sizeof(node)), * last;
    head->next = NULL;
    for (int i = n; i > 0; i--) {
        node* new = malloc(sizeof(node));
        if (i == n) last = new;

        new->data = i;
        new->next = head->next;
        head->next = new;
    }

    printf("Cartas descartadas:");
    while (head->next != NULL) {
        node* first = head->next;
        printf(" %d", first->data);

        node* second = head->next->next;
        head->next = second->next;
        last->next = second;
        second->next = NULL;
        last = second;

        if (head->next != NULL) printf(",");

        free(first);
    }
    printf("\n");
    printf("Carta restante: %d\n", last->data);
}

int main() {
    solve();

    return 0;
}