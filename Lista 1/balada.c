#include <stdio.h>

int main(void){
    int batida;

    scanf("%d", &batida);

    int i;

    for(i = 0; i <  batida; i++){
        if(i % 2 == 0){
            printf("THUMS THUMS THUMS\n");
        }
        else{
            printf("THUMS THUMS THUMS THUMS THUMS THUMS\n");
        }
    }
}