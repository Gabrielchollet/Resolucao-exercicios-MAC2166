#include <stdio.h>

int main() {
    int x,/*base*/
        n,/*expoente inteiro não-negativo*/
    i = 0;/*contador*/

    printf("\n\tCalculo de Potencias\n");
    printf("\nDigite a base (inteiro): ");
    scanf("%d", &x);
    printf("\nDigite o expoente (inteiro nao-negativo): ");
    scanf("%d", &n);

    int potencia = 1;
    while (i < n) {
        potencia *= x;
        i++;
    }
    printf("\nO valor da potencia eh: %d\n", potencia);
    return 0;
}
