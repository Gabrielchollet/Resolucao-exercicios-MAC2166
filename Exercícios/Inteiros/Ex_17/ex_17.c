#include <stdio.h>

int main() {
    printf("\tConversor Decimal-Binario\n");

    int dec,        /* numero dado (na base decimal) */
        copy,       /* auxiliar */
        dig,        /* guardara cada um dos digitos binarios */
        potdec = 1, /* potencia de 10 */
        bin = 0;    /* numero dado convertido para base 2 */

    scanf("%d ", &dec);

    copy = dec;

    while(copy > 0) {
        dig = copy % 2;
        copy /= 2;
        bin += dig*potdec;
        potdec *= 10;
    }
    printf("O numero %d eh %d na base 2\n", dec, bin);
    return;
}
