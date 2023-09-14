#include <stdio.h>

int main(void){
    int a,b,c; // dimensões caixa
    int x,y,z; // dimensões navio

    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &x, &y, &z);

    int qtd_containers;

    if(a > x || a > y || a > z ||b > x || b > y || b > z ||c > x || c > y || c > z ){
        qtd_containers = 0;
    }else{
    qtd_containers = (x*y*z)/(a*b*c);
    }
    
    printf("%d\n",qtd_containers);
}