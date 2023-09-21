#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int f, f1, f2;
    f2 = 0;
    f1 = 1;
    f = n;

    for(int i = 2; i<n; i++){
        f = f1+f2;
        f2 = f1;
        f1 = f;
    }
    printf("%d\n",f);// 0 1 1 2 3 5 8 13 21
}