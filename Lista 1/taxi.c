#include <stdio.h>

int main() {
    double pa, pg, qa, qg;
    char resultado;

    scanf("%lf %lf %lf %lf", &pa, &pg, &qa, &qg);

    if (pa < 0.01 || pa > 10.00 ||
        pg < 0.01 || pg > 10.00 ||
        qa < 0.01 || qa > 20.00 ||
        qg < 0.01 || qg > 20.00) {
        return 1;
    }

    double custoAlcool = pa / qa;
    double custoGasolina = pg / qg;

    if (custoAlcool < custoGasolina) {
        resultado = 'A';
    } else {
        resultado = 'G';
    }

    printf("%c\n", resultado);

    return 0;
}