#include <stdio.h>

int main(void){
    int l,d; //comprimento da estrada e distância entre pedágios
    int k,p; //custo por kilometro e custo do pedágio

    scanf("%d %d", &l, &d);
    //printf("%d %d\n", l, d);
    scanf("%d %d", &k, &p);

    int custoTotal, custoPedagio, custoGasolina;
    custoPedagio = (l/d)*p;
    custoGasolina = l*k;
    custoTotal = custoPedagio+custoGasolina;
    printf("%d\n", custoTotal);
}