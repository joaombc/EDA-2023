// ALGORITIMO

void shell_sort( int v[], int l, int r){
    int h = 1;
    while(h < (r-l +1)/3){
        h = 3*h+1;
    }
    while(h>=1){
        for (int i = l + h; i <= r; i++){
            for( int j = i; j>=l+h && v[j]< v[j-h; j-=h]){
                swap(v[j], v[j-h])
            }
        }
        h = h/3;
    }
}

void shell_sort_recursive(int v[], int l, int r, int h) {
    if (h < 1) {
        return;
    }

    for (int i = l + h; i <= r; i++) {
        for (int j = i; j >= l + h && v[j] < v[j - h]; j -= h) {
            swap(&v[j], &v[j - h]);
        }
    }

    shell_sort_recursive(v, l, r, h / 3);
}

void shell_sort(int v[], int l, int r) {
    int h = 1;
    while (h < (r - l + 1) / 3) {
        h = 3 * h + 1;
    }

    shell_sort_recursive(v, l, r, h);
}


/*
    COMPLEXIDADE:
            pior caso:
                Pior caso com pior sequencia de intervalos h: O(N²)
                Melhor caso com pior sequencia de intervalos h: O(nlog² n)
            melhor caso: O(N log N)
            caso medio: NÃO existe um resultado matematio para o caso medio
    ADAPTIVO
    NÃO ESTÁVEL
    IN PLACE

*/