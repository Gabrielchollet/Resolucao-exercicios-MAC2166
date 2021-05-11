/*
    Dado dois numeros inteiros positivos i e j,
    imprimir  em ordem crescente os n primeiros naturais
    que sao multiplos de i ou de j e ou de ambos
    Exemplo: Para n = 6, i = 2 e j = 3 a saida devera ser: 0, 2, 3, 4, 6, 8.
*/
#include <stdio.h>

int main() {
    int n, /* numero de multiplos de i ou de j a serem impressos*/
        i, j,
        m = 0, /*candidato a multiplo */
        k = 0; /*  */

    scanf("%d %d %d ", &n, &i, &j);

    for (; k < n; m++) {
        if (m % i == 0 || m % j == 0) {
            printf("%d ", m);
            k++;
        }
    }
    return 0;
}

