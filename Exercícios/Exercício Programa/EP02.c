/* Jogo do Bixo*/

#include <stdio.h>

void PrimeiraParte( int n, int k, int N, int m, int a, int c, int r_0 );
void SegundaParte( int n, int d );
void Cospe( int i, int j, int k, int s_i, int s_j, int s_k );

int main() {
    int tarefa, n, k, N, m, a, c, r_0, d;
    printf("Digite a tarefa desejada: 1 para primeira; 2 para segunda\n");
    scanf("%d", &tarefa);

    if (tarefa == 1) {
        printf("Digite parametros n, k, N, m, a, c, r_0:\n");
        scanf("%d %d %d %d %d %d %d", &n, &k, &N, &m, &a, &c, &r_0);
        PrimeiraParte( n, k, N, m, a, c, r_0 );
    }
    else if (tarefa == 2) {
        printf("Digite parametros n, d:\n");
        scanf("%d %d", &n, &d);
        SegundaParte( n, d );
    }

    return 0;
}

void PrimeiraParte( int n, int k, int N, int m, int a, int c, int r_0 ) {
    printf("Recorrencia   r <-- ( r x %d + %d ) mod %d   a partir da semente %d.\n", a, c, m, r_0);
    printf("As %d sequencias de %d sorteios (com repeticao) em [ 1 .. %d ] e seus diametros:\n", N, k, n);

    int rn = r_0, /* termo n da recorrencia linear */
        rn_1,     /* termo n + 1 da recorrencia linear */
        f_r,      /* valor da funcao mapeadora */
        diam,     /* diametro dos sorteados */
        fmin,
        fmax;

    for (int i = 0; i < N; i++) {
            fmin = n; /* maior dos k numeros sorteados */
            fmax = 1; /* menor dos k numeros sorteados */
            for (int j = 0; j < k; j++) {
                rn_1 = (a * rn + c) % m;
                f_r = rn_1*n/m + 1;

                /* Verificar se um dado numero simulado pela funcao mapeadora
                   extrapola os limites inicialmente declarados para redefini-los até o fim da iteracao
                */
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
            printf("   -> %5d\n", diam);
    }
}

void SegundaParte( int n, int d ) {
    int ind_a, /* Indice de Sa */
        ind_b, /* Indice de Sb */
        ind_i, /* Indice de Si */
          s_a, /* Menor numero sorteado com o menor indice */
          s_b, /* Maior numero sorteado com o menor indice */
          s_i, /* Sa <= Si <= Sb | i != a && i != b */
            m, /* Menor inteiro pertencente ao intervalo [1..n - d + 1] */
         num_seq = 0; /* Contador do numero de sequencias */

    printf("Listagem das sequencias de S( %d , 3 , %d ) (com repeticao):\n", n, d);

    for (ind_a = 1; ind_a <= 3; ind_a++) {
        for (ind_b = 1; ind_b <= 3; ind_b++) {
            if (ind_a != ind_b) {
                /* Escolha de m na ordem crescente */
                for (m = 1; m <= n - d + 1; m++) {
                    s_a = m;
                    s_b = m + d - 1;
                    for (ind_i = 1; ind_i <= 3; ind_i++) {
                        /* Os condicionais abaixo definem os intervalos de valores de s_i para cada (a,b) possivel */
                        if (ind_i > ind_a && ind_i > ind_b) {
                            for (s_i = m; s_i <= m + d - 1; s_i++) {
                                Cospe(ind_a, ind_b, ind_i, s_a, s_b, s_i);
                                num_seq++;
                            }
                        }
                        if (ind_i > ind_a && ind_i < ind_b) {
                            for (s_i = m; s_i <= m + d - 2; s_i++) {
                                Cospe(ind_a, ind_b, ind_i, s_a, s_b, s_i);
                                num_seq++;
                            }
                        }
                        if (ind_i < ind_a && ind_i > ind_b) {
                            for (s_i = m + 1; s_i <= m + d - 1; s_i++) {
                                Cospe(ind_a, ind_b, ind_i, s_a, s_b, s_i);
                                num_seq++;
                            }
                        }
                        if (ind_i < ind_a && ind_i < ind_b) {
                            for (s_i = m + 1; s_i <= m + d - 2; s_i++) {
                                Cospe(ind_a, ind_b, ind_i, s_a, s_b, s_i);
                                num_seq++;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Total de %d sequencias\n", num_seq);
    printf("Limites: %d e %d\n", 6*(d - 2)*(n - d + 1), 9*d*n);
}

/* Imprime os tres elementos segundo ordem crescente dos ındices*/
void Cospe( int a, int b, int i, int s_a, int s_b, int s_i ) {
    if (a < b) {
        if (b < i) {
            printf("%d %d %d\n", s_a, s_b, s_i);
        }
        else if (a < i) {
            printf("%d %d %d\n", s_a, s_i, s_b);
        }
        else {
            printf("%d %d %d\n", s_i, s_a, s_b);
        }
    }
    else if (a < i) {
        printf("%d %d %d\n", s_b, s_a, s_i);
    }
    else if (b < i) {
        printf("%d %d %d\n", s_b, s_i, s_a);
    }
    else {
        printf("%d %d %d\n", s_i, s_b, s_a);
    }
}

