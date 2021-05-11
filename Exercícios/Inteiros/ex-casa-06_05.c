/*
    Dado um natural n > 0, verificar se n possui dois digitos consecutivos iguais
    exemplos: 1230 ,32527, 101 nao possuem dígitos consecutivos iguais,
    mas 4001 e 11 possuem.
*/
#include <stdio.h>

int main() {
    int n,      /*numero a ser analisado*/
        dig_one,/**/
        dig_two,/**/
        copy,   /*guarda uma copia de n*/
        dois_dig = 0;

    scanf("%d ", &n);

    copy = n;
    while (n > 0) {
        dig_one = copy % 10;
        copy /= 10;
        dig_two = copy % 10;
        copy /= 10;
        if (dig_one == dig_two) {
            dois_dig++;
        }
    }

    if (dois_dig != 0) {
        printf("%d tem dois digitos iguais\n", n);
    }
    else {
        printf("%d nao tem dois digitos iguais\n", n);
    }
    return 0;
}
