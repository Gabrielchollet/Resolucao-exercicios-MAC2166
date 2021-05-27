#include <stdio.h>

int main() {
    float r, x, rant, erro, eps;
    printf("Entre com x >= 0: ");
    scanf("%f", &x);

    printf("Entre com 0 < eps < 1: ");
    scanf("%f", &eps);

    r = x, erro = eps, rant = r;
    while (erro >= eps && x > 0) {
        r = (rant + x/rant)/2;

        erro = r - rant;

        if (erro < 0) {
            erro = -erro;
        }

        rant = r;
    }

    printf("Raiz de %f = %f\n", x, r);
    return 0;
}
