#include <stdio.h>

int f91(int n){
	if (n >= 101) {
        return n - 10;
    } else {
        return f91(f91(n + 11));
    }
}


int main(void){
	int n;
	while(1){
		scanf("%d", &n);
		if(n <= 0 || n >= 1000000 ){
			return 1;
		}
		int resultado;

		resultado = f91(n);
		printf("f91(%d) = %d\n", n, resultado);
	}
}