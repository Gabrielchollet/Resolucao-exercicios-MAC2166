/*
  Dados inteiros positivos m, n e p, e matrizes reais A_{m x n} e B_{n x p},
  imprimir a matriz produto AB_{m x p}
  Ex.: entrada 2 3 2

    1 2 3       -1  1
    4 5 6  &&    0 -2 a saida eh 2 0
                 1  1            2 0
*/

#include <stdio.h>
#define max 10

int AB[max][max];

int main()
{
    int m, n, p, A[max][max], B[max][max];
    scanf("%d %d %d", &m, &n, &p);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d ", A + j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            scanf("%d ", B + j);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < n; k++)
            {
                AB[i][j] += A[i][k] * B[k][i];
            }
        }
    }
    for (int a = 0; a < m; a++)
    {
        for (int b = 0; b < p; b++)
        {
            printf("%7d ", AB[a][b]);
        }
        printf("\n");
    }
    return 0;
}
