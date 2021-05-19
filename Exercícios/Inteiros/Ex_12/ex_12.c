#include <stdio.h>
/*
    Dados dois numeros inteiros positivos, determinar o maximo divisor comum entre eles
    usando o algoritmo de Euclides
*/
int main() {
    int a, b, r;
    scanf("%d %d ", &a, &b);
    printf("MDC(%d,%d): ", a, b);
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    printf(" %d\n",  a);
    return;
}
