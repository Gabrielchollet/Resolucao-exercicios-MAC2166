/* Jogo do Bixo*/
#include <stdio.h>

void PrimeiraParte( int n, int k, int N, int m, int a, int c, int r_0 );

int main() {
    int n, k, N, m, a, c, r_0;
    scanf("%d %d %d %d %d %d %d ", &n, &k, &N, &m, &a, &c, &r_0);
    PrimeiraParte(n, k, N, m, a, c, r_0);
}

void PrimeiraParte( int n, int k, int N, int m, int a, int c, int r_0 ) {
    printf("Recorrencia r <-- ( r x 5 + 3 ) mod 8 a partir da semente 7.\n");
    printf("As 5 sequencias de 3 sorteios (com repeticao) em [ 1 .. 8 ] e seus diametros:\n");
    return;
}
