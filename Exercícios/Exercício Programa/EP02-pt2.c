/* Jogo do Bixo parte 02*/
#include <stdio.h>

void SegundaParte( int n, int d );
void Cospe( int i, int j, int k, int s_i, int s_j, int s_k );

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    SegundaParte( n, d );
    return 0;
}

void SegundaParte( int n, int d ) {
    int ind_a, ind_b, ind_i, s_a, s_b, s_i, m, num_seq = 0;

    for (ind_a = 1; ind_a <= 3; ind_a++) {
        for (ind_b = 1; ind_b <= 3; ind_b++) {
            if (ind_a != ind_b) {
                for (m = 1; m <= n - d + 1; m++) {
                    s_a = m;
                    s_b = m + d - 1;
                    for (ind_i = 1; ind_i <= 3; ind_i++) {
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
                    }
                }
            }
        }
    }
    printf("Total de %d sequencias\n", num_seq);
    printf("Limites: %d e %d\n", 6*(d - 2)*(n - d + 1), 9*d*n);
}

void Cospe( int i, int j, int k, int s_i, int s_j, int s_k ) {
    if ( i < j ) {
        if ( j < k ) {
            printf( "%d %d %d\n", s_i, s_j, s_k );
        }
        else {
            printf( "%d %d %d\n", s_i, s_k, s_j );
        }
    }
    else if (i < k) {
        if ( j < k ) {
            printf( "%d %d %d\n", s_j, s_i, s_k );
        }
        else {
            printf( "%d %d %d\n", s_k, s_i, s_j );
        }
    }
    else {
        if ( j < k ) {
            printf( "%d %d %d\n", s_j, s_k, s_i );
        }
        else {
            printf( "%d %d %d\n", s_k, s_j, s_i );
        }
    }
}
