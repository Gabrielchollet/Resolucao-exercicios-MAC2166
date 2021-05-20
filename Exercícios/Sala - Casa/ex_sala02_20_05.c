/*
    Dados naturais n e k tais que 0 <= k <= n, calcule o numero
    de combinacoes de n, k a k.
    Ex.: para comb de 6, 4 a 4:
    6!/(4!*(6-4)!) = 15
*/

#include <stdio.h>

int calc_fatorial(int a);

int main() {
    printf("\n\tCombinacao de n, k a k\n");
    int n, k, comb;

    scanf("%d %d ", &n, &k);

    printf("%d!/(%d!*%d!) = ", n, k, n - k);

    comb = calc_fatorial(n)/(calc_fatorial(k) * calc_fatorial(n-k));

    printf("%d\n", comb);
    return 0;
}

int calc_fatorial(int a) {
    int fatorial = 1;

    for (int i = a; i > 0; i--) {
        fatorial *= i;
    }
    return fatorial;
}
