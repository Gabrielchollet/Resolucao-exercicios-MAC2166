/*Soma dos pares de uma sequ�ncia de n inteiros*/
#include <stdio.h>

int main() {
    int n, /*guarda o n�mero de inteiros*/
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
