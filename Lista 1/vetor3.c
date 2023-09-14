#include <stdio.h>

int main(void){
    int n;

    scanf("%d", &n);

    if(n<5 || n>10000){
        return 1;
    }

    int v[n];
    
    for(int i = 0; i<n; i++){
        scanf("%d", &v[i]);
        if(v[i]<-1000000 || v[i]>1000000){
            return 1;
        }
        
    }

    for(int i = 0; i < n; i++){
        if(v[i]%2 == 0){
            printf("%d ", v[i]);
        }

    }

    printf("\n");
    for(int i = 0; i < n; i++){

        if(v[i]%2 != 0){
            printf("%d ", v[i]);
        }

    }
    printf("\n");


}