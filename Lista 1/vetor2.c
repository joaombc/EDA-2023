#include <stdio.h>

int main(void){
    int n, numero;

    scanf("%d", &n);

    if(n<5 || n>10000){
        return 1;
    }

    int v[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
        if(v[i]<-1000000 || v[i]>1000000){
            return 1;
        }
    }

    scanf("%d", &numero);

    int pertence;
    pertence = 0;

    for(int j = 0; j < n; j++){
        // printf("%d\n",v[j]);
        if(v[j] == numero){
            pertence = 1;
            break;
        }
    }

    if(pertence){
        printf("pertence\n");
    }
    else{
        printf("nao pertence");
    }

}