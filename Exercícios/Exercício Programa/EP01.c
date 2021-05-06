/*Frequencia de um inteiro*/
#include <stdio.h>

int main() {
    int x,      /*guarda o primeiro inteiro a ser contado*/
        seq,    /*guarda os numeros da sequencia*/
        i = 0;      /*contador de frequencia*/

    scanf("%d ", &x);
    do {
        scanf("%d ", &seq);
        if (x == seq) {
            i++;
        }
    } while (seq != 0);
    printf("\n%d\n", i);
    return 0;
}
