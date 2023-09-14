#include <stdio.h>

int main(void){

    int numero, rodadas;

    numero = 1;

    while(1){
        scanf("%d", &rodadas);
        if(rodadas == 0){
            break;
        }
        if (rodadas < 1 || rodadas > 1000) {
            return 1;
        }

        int aldo, beto, i;
        aldo = 0;
        beto = 0;

        for(i = 0; i < rodadas; i++){
            int pontosA, pontosB;
            scanf("%d %d", &pontosA, &pontosB);

            aldo += pontosA;
            beto += pontosB;
        }
        if (aldo > beto){
            printf("Teste %d\nA\n\n", numero);
            }
        else{
            printf("Teste %d\nB\n\n", numero);
        }
        numero++;
    }
    return 0;

    // scanf("%d",&rodadas);

    // while(rodadas != 0){
    //     scanf("%d %d", &a, &b);
    //     rodadas--;
    // }
}
