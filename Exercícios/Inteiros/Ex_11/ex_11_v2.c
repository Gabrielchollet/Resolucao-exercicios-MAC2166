#include <stdio.h>

int main() {
    int n,
        eprimo = 1,
        div;

    scanf("%d ", &n);

    if (n <= 1) {
        eprimo == 0;
    }
    else {
        eprimo == 1;
    }

    for (div = 2; div < n/2 && eprimo == 1; div++) {
        if (n % div == 0) {
            eprimo == 0;
        }
    }

    if (eprimo == 1) {
        ´printf("O numero %d eh primo\n", n);
    }
    else {
        printf("O numero %d nao eh primo\n", n);
    }
}
