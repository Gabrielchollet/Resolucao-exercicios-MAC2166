/*
    Dado um natural n > 0, verificar se n possui dois digitos consecutivos iguais
    exemplos: 1230 ,32527, 1001 nao possuem dígitos consecutivos iguais,
    mas 4001 e 11 possuem.
*/
#include <stdio.h>

int main() {
    int n,      /*numero a ser analisado*/
        dig_one,/**/
        dig_two,/**/
        i,      /*contador do numero de algarismos*/
        copy,   /*guarda uma copia de n*/
        *dig;    /*array dos i digitos de n*/

    scanf("%d ", &n);

    /*conta o numero de algarismos n*/
    /*e os guarda em um array*/
    n = copy;
    while (copy > 0) {
        copy /= 10;
        i++;
    }
    dig = malloc (i * sizeof (int));

    for (int j = 0; j < i; j++) {
        n % 10 = dig[j];
        n /= 10;
    }

    for (int k = 0; k < i; k++) {

    }

    free (dig);
    return 0;
}
