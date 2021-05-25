/* Jogo do Bixo*/
#include <stdio.h>

void PrimeiraParte( int n, int k, int N, int m, int a, int c, int r_0 );

int main() {
    int n, k, N, m, a, c, r_0;
    scanf("%d %d %d %d %d %d %d ", &n, &k, &N, &m, &a, &c, &r_0);
    PrimeiraParte( n, k, N, m, a, c, r_0 );
    return 0;
}

void PrimeiraParte( int n, int k, int N, int m, int a, int c, int r_0 ) {
    printf("Recorrencia r <-- ( r x %d + %d ) mod %d a partir da semente %d.\n", a, c, m, r_0);
    printf("As %d sequencias de %d sorteios (com repeticao) em [ 1 .. %d ] e seus diametros:\n", N, k, n);

    int rn = r_0, /* termo n da recorrencia linear */
        rn_1,     /* termo n + 1 da recorrencia linear */
        f_r,      /* valor da funcao mapeadora */
        diam,     /* diametro dos sorteados */
        fmin,
        fmax;

    for (int i = 0; i < N; i++) {
            fmin = n;
            fmax = 1;
            for (int j = 0; j < k; j++) {
                rn_1 = (a * rn + c) % m;
                f_r = rn_1*n/m + 1;

                if(f_r > fmax) {
                    fmax = f_r;
                }
                if(f_r < fmin) {
                    fmin = f_r;
                }
                diam = 1 + fmax - fmin;

                rn = rn_1;

                printf("%5d", f_r);
            }
            printf("  -> %5d\n", diam);
    }
}
