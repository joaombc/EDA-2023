#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct celula {
    int dado;
    struct celula* prox, * prev;
} celula;

void imprime(celula* le) {
    while (le->prev != NULL) {
        printf("%d\n", le->dado);
        le = le->prev;
    }
}

int main() {
    celula* head = malloc(sizeof(celula));
    head->prox = NULL;
    celula* last = head;

    while (true) {
        celula* node = malloc(sizeof(celula));
        node->prox = NULL;
        scanf(" %d", &node->dado);

        if (!node->dado) break;
        last->prox = node;
        last = node;
    }

    int number, sum = 0;
    scanf("%d", &number);

    celula* top = malloc(sizeof(celula));
    top->prox = NULL;
    top->prev = NULL;
    celula* prev = top;
    while (head->prox != NULL) {
        sum += head->prox->dado;
        if (sum > number) {
            celula* node = malloc(sizeof(celula));
            node->prox = NULL;

            node->dado = head->prox->dado;
            prev->prox = node;
            node->prev = prev;
            prev = node;

            sum = 0;
        }
        head = head->prox;
    }
    imprime(prev);

    return 0;
}
