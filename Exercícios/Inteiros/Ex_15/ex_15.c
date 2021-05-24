/*
    Dizemos que um numero i eh congruente modulo m a j se i % m = j % m
    Ex.: 35 eh congruente modulo4 a 39, pois 35 % 4 = 3 = 39 % 4
    Dados inteiros positivos n, j e m, imprimir os n primeiros naturais
    congruentes a j modulo m.
*/

#include <stdio.h>

int main() {
    int n, j, m;

    scanf("%d %d %d ", &n, &j, &m);

    int resto = j % m;

    for(int i = 0; i < n; i++) {
        printf("%d\n", m*i + resto);
    }
    return;
}
