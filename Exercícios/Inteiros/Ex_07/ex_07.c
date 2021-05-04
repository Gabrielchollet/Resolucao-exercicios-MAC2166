/*Soma dos pares de uma sequência de n inteiros*/
#include <stdio.h>

int main() {
    int n, /*guarda o número de inteiros*/
     soma;

    scanf("%d ", &n);

    for (int i = 0; i < n; i++) {
        if ((i + 1)%2 == 0) {
            soma += i + 1;
        }
    }
    printf("\n%d\n", soma);
    return 0;
}
