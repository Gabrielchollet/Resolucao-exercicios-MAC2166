/*
    Sabe-se que um numero da forma n^3 eh igual a soma de n impares consecutivos
    Ex.: 1^3 = 1, 2^3 = 3 + 5, 3^3 = 7 + 9 + 11,...
    Dado m > 0, determine os impares consecutivos cuja soma eh igual a n^3 para
    n assimnido valores de 1 a m.
*/
#include <stdio.h>

int main() {
    printf("\n\tCubos e soma de impares consecutivos\n");

    int n, first_odd;
    scanf("%d ", &n);
    printf("\n%d^3 = ", n);

    /*
        n^3 pode ser escrito da seguinte forma:
        n^3 = n*(i + n - 1), em que i é o primeiro impar da soma,
        assim: i = n^2 - n + 1
    */
    first_odd = n * n - n + 1;
    printf("%d ", first_odd);
    for (int i = 1; i < n; i++) {
        printf("+ %d ", first_odd + 2 * i);
    }

    return 0;
}
