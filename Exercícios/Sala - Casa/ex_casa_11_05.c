/*
    Dado um inteiro positivo n, determine a sua decomposicao em
    fatores primos calculando tambem a multipliciddade de cada fator.
    Exemplo: para a entrada 120
        a saída desejada eh 120 = 2^3 * 3^1 * 5^1
*/
#include <stdio.h>

int verifica_primo(int number);

int main() {
    int n,   /* numero a ser decomposto */
        div, /* candidato a fator */
        exp, /* contador do expoente */
        copy;

    printf("Digite um inteiro: ");
    scanf("%d ", &n);

    copy = n;

    for (div = 2; div < n; div++) {
        if (verifica_primo(div) == 0) {
            while (copy % div == 0){
                exp++;
                copy /= div;
            }
        }
        printf("%d^%d\n", div, exp);
    }

    return 0;
}

int verifica_primo(int number) {
    int cont;
    for (int i = 1, cont = 0; i < number; i++) {
        if (number % i == 0) {
            cont++;
        }
    }
    if (cont == 2) {
        return 0;
    }
    else {
        return 1;
    }
}
