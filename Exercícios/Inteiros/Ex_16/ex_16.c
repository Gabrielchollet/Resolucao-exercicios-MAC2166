/*
    Dado um numero natural na base binaria, transforma-lo para a base decimal.
    Ex.: Dado 10010
    A saida deve ser 18, pos 1*2^4 + 0*2^3 + 0*2^2 + 1*2^1 + 0*2^0 = 18
*/

#include <stdio.h>

int main() {
    printf("\tConversor Binario-Decimal\n");

    int bin, /* numero na base 2 */
        copy, pot,
         dec = 0; /* numero na base decimal */

    scanf("%d ", &bin);

    copy = bin;

    for(int i = 0; copy > 0; i++) {
        pot = 1;
        for (int j = 0; j < i; j++) {
            pot *= 2;
        }
        dec += (copy % 10) * pot;
        copy /= 10;
    }

    printf("O binario %d eh %d na base 10\n", bin, dec);

    return;
}
