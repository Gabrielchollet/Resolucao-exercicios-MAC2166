/*
    Dizemos que um unteiro positivo n eh perfeito se for igual a soma
    de seus divisores positivos diferentes de n
    Ex.: 6 eh perfeito, pois 1 + 2 + 3 = 6
*/
#include <stdio.h>

int eh_perfeito(int number);

int main() {
    printf("\n\tVerificar se um dado inteiro positivo eh perfeito\n");

    int num;

    scanf("%d ", &num);

    /*Se num = 2^(n-1)*(2^n -1), num é um numero perfeito*/
    if (eh_perfeito(num) == 0) {
            printf("%d = 1 ", num);

            for (int i = 2; i < num; i++) {
                if (num % i == 0) {
                    printf("+ %d ", i);
                }
            }
    }
    else {
            printf("O numero %d nao eh perfeito\n", num);
    }

    return 0;
}

int eh_perfeito(int number) {
    for (int i = 1; i < number; i++) {
        if (number == 2^(i - 1)*(2^i - 1)) {
            return 0;
        }
        else {
            return 1;
        }
    }
}
