/*Frenqu�ncia de um inteiro*/
#include <stdio.h>

int main() {
    int x,               /*inteiro contado*/
        seq,               /*guarda os numeros da sequencia*/
        frequencia = 0;  /*contador de frequ�ncia*/

    scanf("%d ", &x);
    /*la�o de repeti��o que ler� os inteiros da sequencia*/
    while (seq != 0) {
        scanf("%d ", &seq);
        if (seq == x) {
            frequencia++;
        }
    }
    printf("%d\n", frequencia);
    return 0;
}
