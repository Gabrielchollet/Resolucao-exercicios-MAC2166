/*
    Dado um natural k, imprimir as k+1 primeiras linhas
    do triangulo de Pascal
    Ex.: para k=5, as 6 primeiras linhas sao:
    1
    1  1
    1  2  1
    1  3  3  1
    1  4  6  4  1
    1  5  10 10 5  1
*/

#include <stdio.h>

int fat(int a);

int main() {
    printf("\tTriangulo de Pascal\n");
    int n, k, comb;

    scanf("%d ", &k);

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%4d ", fat(i)/(fat(j) * fat(i-j)));
        }
        printf("\n");
    }

    return 0;

}

int fat(int a) {
    int fatorial = 1;

    for (int i = a; i > 0; i--) {
        fatorial *= i;
    }
    return fatorial;
}
