/*
    Dados um numero inteiro n, n > 0, e uma sequencia com n numeros inteiros,
    verificar se a sequencia é uma progressão aritmetica
*/

#include <stdio.h>

int main() {
    int n, /* numero de inteiros */
        num_one = 0, /* termo 1 */
        num_two = 0, /* termo 2*/
        razao,
        eh_PA = 0;

    scanf("%d ", &n);
    scanf("%d ", &num_one);
    scanf("%d ", &num_two);
    razao= num_two - num_one;

    for (int i = 2; i < n && eh_PA == 0 && n > 1; i++) {
        num_one = num_two;
        scanf("%d ", &num_two);

        if (num_two - num_one != razao) {
            eh_PA = 1;
        }
    }

    if (eh_PA == 0) {
        printf("A sequencia eh uma PA\n");
    }
    else {
        printf("A sequencia nao eh uma PA\n");
    }
    return 0;
}
