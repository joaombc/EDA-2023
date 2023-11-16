#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000007

typedef long long ll;

typedef struct queue {
    ll data, ix;
    struct queue* next;
} queue;

queue* make_queue() {
    queue* qs = (queue*)malloc(sizeof(queue));
    qs->next = NULL;
    return qs;
}

bool empty(queue* f) {
    return f == NULL || f->next == NULL;
}

queue* push(queue* f, ll data, ll ix) {
    queue* node = (queue*)make_queue();
    node->next = f->next;
    f->next = node;
    f->data = data;
    f->ix = ix;
    return node;
}

queue* front(queue* f) {
    return f->next;
}

void pop(queue* f) {
    f->next = f->next->next;
}

ll visited[MAX];
void solve() {
    ll f, s, g, u, d;
    scanf("%lld %lld %lld %lld %lld", &f, &s, &g, &u, &d);

    queue* start = make_queue();
    queue* head = make_queue();
    start->next = head;
    queue* node = head;

    node = push(node, s, 0);
    visited[s]++;
    while (!empty(start)) {
        queue* curr = front(start);
        pop(start);

        if (curr->data == g) {
            printf("%lld\n", curr->ix);
            return;
        }

        if (u != 0 && curr->data + u <= f && !visited[curr->data + u]) {
            node = push(node, curr->data + u, curr->ix + 1);
            visited[curr->data + u]++;
        }
        if (d != 0 && curr->data - d >= 1 && !visited[curr->data - d]) {
            node = push(node, curr->data - d, curr->ix + 1);
            visited[curr->data - d]++;
        }
    }

    printf("use the stairs\n");
}

int main() {
    solve();

    return 0;
}