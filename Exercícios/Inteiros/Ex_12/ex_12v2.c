#include <stdio.h>
/*
    Dados dois numeros inteiros positivos, determinar o maximo divisor comum entre eles
    usando o algoritmo de Euclides
    Desta vez usando recursão
*/
int mdc(int a, int b);

int main() {
    int a, b, resultado;
    scanf("%d %d ", &a, &b);
    printf("MDC(%d,%d): %d", a, b, mdc(a,b));
}

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        mdc(b, a % b);
    }
}

