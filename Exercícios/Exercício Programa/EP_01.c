/*Frenquência de um inteiro*/
#include <stdio.h>

int main() {
    int x,               /*inteiro contado*/
        seq,               /*guarda os numeros da sequencia*/
        frequencia = 0;  /*contador de frequência*/

    scanf("%d ", &x);
    /*laço de repetição que lerá os inteiros da sequencia*/
    while (seq != 0) {
        scanf("%d ", &seq);
        if (seq == x) {
            frequencia++;
        }
    }
    printf("%d\n", frequencia);
    return 0;
}
