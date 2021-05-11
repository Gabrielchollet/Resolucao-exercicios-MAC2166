#include <stdio.h>

int main() {
    int num,/* Guarda  o numero cuja primalidade eh testada*/
        div;/* Contador do numero de divisores */

    scanf("%d ", &num);
    for (int i = 0; i < num; i++) {
        if (num % (i + 1) == 0 ) {
            div++;
            printf("%d ", i + 1);
        }
    }

    if (div > 2) {
        printf("%d nao eh primo e possui %d divisores\n", num, div);
    }
    else {
        printf("%d eh primo\n", num);
    }
    return 0;
}
