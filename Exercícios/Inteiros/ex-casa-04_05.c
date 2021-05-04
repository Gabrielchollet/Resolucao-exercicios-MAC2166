/*
Dados um inteiro n e um inteiro d, 0 <= d <= 9, faça um programa que,
imprime quantas vezes o dígito d apareçe na representação decimal de n
ex: se n e d são 3456454 4
    devemos imprimir a resposta 3
*/

#include <stdio.h>

int main() {
    int n, d,
        numAlg = 0; /*guarda o numero de algarismos de n*/

    printf("\n\tNumero de vezes que um digito se repete em um numero decimal\n");

    scanf("%d %d", &n, &d);

    /*laço para determinar numAlg*/
    while (n >= d) {
        if ((n - d) % 10 == 0) {
            numAlg++;
            n /= 10;
        }
        else {
            n /= 10;
        }
    }
    printf("%d ", numAlg);
    return 0;
}
