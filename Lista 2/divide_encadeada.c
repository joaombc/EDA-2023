void divide_lista(celula *l, celula *l1, celula *l2) {
    celula *atual = l->prox;
    celula *atual_l1 = l1;
    celula *atual_l2 = l2;

    while (atual != NULL) {
        celula *proximo = atual->prox;

        if (atual->dado % 2 == 0) {
            // Número par, move para l2
            atual_l2->prox = atual;
            atual_l2 = atual_l2->prox;
        } else {
            // Número ímpar, move para l1
            atual_l1->prox = atual;
            atual_l1 = atual_l1->prox;
        }

        atual->prox = NULL;  // Desconecta o nó da lista original

        atual = proximo;
    }
}
