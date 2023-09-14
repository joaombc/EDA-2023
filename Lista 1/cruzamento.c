#include <stdio.h>

int main(void){
    int x0, y0; //posição inicial
    int x1, y1; // posição final
    int n_cruzamentos, xmov, ymov;

    scanf("%d %d %d %d", &x0, &y0 ,&x1, &y1);

    xmov = x1 - x0;
    ymov = y1 - y0;

    if(xmov<0){
        xmov = xmov *(-1);
    }
    if(ymov<0){
        ymov = ymov *(-1);
    }

    n_cruzamentos = xmov + ymov;
    printf("%d\n", n_cruzamentos);
}