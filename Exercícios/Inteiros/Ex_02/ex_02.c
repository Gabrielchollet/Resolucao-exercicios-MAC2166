#include <stdio.h>

int main() {
    int n,/*guarda o numero de numeros da soma*/
     soma;/*soma de Gauss: (n * (n + 1)/ 2)*/

    printf("\n\tCalculo da soma dos n primeiros inteiros positivos\n");

    printf("\nDigite o valor de n: ");
    scanf("%d", &n);

    soma = (n * (n + 1)) / 2;
    printf("A soma dos %d primeiros inteiros positivos eh %d\n", n, soma);
    return 0;
}
