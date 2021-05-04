/*Fatorial de inteiros não-negativos*/
#include <stdio.h>

int main() {
    int n,          /*inteiro que sofrerá a operação*/
        fatorial = 1;

    scanf("%d ", &n);

    for (int i = n; i > 0; i--) {
        fatorial *= i;
    }
    printf("%d\n", fatorial);
    return 0;
}
