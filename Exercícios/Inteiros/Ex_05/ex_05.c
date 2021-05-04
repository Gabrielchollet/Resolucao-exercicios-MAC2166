#include <stdio.h>
/*
 Uma loja de discos anota diariamente durante o mês de março a quantidade de discos vendidos.
 Determinar em que dia desse mês ocorreu a maior venda e qual foi a quantidade de discos vendida nesse dia.
*/
int numDias = 30;
int main() {
    int vendaDiaria[numDias];

    for (int i = 0; i < numDias; i++) {
        scanf("%d ", &vendaDiaria[i]);
    }
    int diaMaximo = 0, numMaximo = vendaDiaria[0];
    for (int j = 0; j < numDias; j++){
        if (numMaximo < vendaDiaria[j]) {
            numMaximo = vendaDiaria[j];
            diaMaximo = j + 1;
        }
    }
    printf("A maior venda foi de %d discos no dia %d\n", numMaximo, diaMaximo);
    return 0;
}

