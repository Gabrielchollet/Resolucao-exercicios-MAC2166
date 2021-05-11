#include <stdio.h>

/*Dado um n calcular o maior inteiro cujo o quadrado eh <= n*/

int main() {
    int n, x;

    scanf("%d ", &n);
    for (int i = 0; i*i <= n; i++) {
        if (n >= (i*i + 2*i + 1)) {
            x = i*i + 2*i + 1;
        }
    }

    printf("%d\n", x);
}

