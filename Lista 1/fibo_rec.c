#include <stdio.h>

int fibo(int n){
    if(n==0){
        return 0;
    }
    else if(n==1 || n==2){
        return 1;
    }else{
        return fibo(n-1) + fibo(n-2);
    }
}

int main(void){
    int m;
    scanf("%d", &m);
    int a = fibo(m);
    printf("%d\n", a);// 0 1 1 2 3 5 8 13 21
}