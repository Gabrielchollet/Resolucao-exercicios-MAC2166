/*
    Dado um inteiro positivo n, determine a sua decomposicao em
    fatores primos calculando tambem a multipliciddade de cada fator.
    Exemplo: para a entrada 120
        a saída desejada eh 120 = 2^3 * 3^1 * 5^1
*/
#include <stdio.h>

int main() {
    int num,
        copy,
        exp = 0,
        number = 1;

    scanf("%d ", &num);

    copy = num;

    printf("%d = ", num);

    for (int i = 2; number < num; i++) {
        for (; num % i == 0 && number < num; exp++) {
            copy /= i;
            number *= i;
        }
        if (i != 2) {
            printf(" *");
        }
        if (num % i == 0) {
            printf(" %d^%d", i, exp);
        }
    }
    printf("\n");
    return 0;
}
