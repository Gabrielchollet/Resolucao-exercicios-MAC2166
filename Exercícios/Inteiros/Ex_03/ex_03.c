#include <stdio.h>

int main() {
    int n,    /*guarda o numero dado*/
        i = 0;/*contador*/
    printf("\n\tImprime os n primeiros numeros impares\n");

    print("\nDigite o valor de n: ");
    scanf("%d", &n);

    /*inicializando*/
    printf("\nPara n = %d: ", n);
    while (i < n) {
        int impar = 1 + 2 * i;
        printf("%d ", impar);
        i++;
    }
    return 0;
}

