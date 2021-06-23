/*
    calcular sem repeticao os raios das circunferencias centradas no
    ponto (x,y) que passam por pelo menos um dos n pontos dados
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max 100

int main()
{
    double x_0, y_0, dist[max], pontoX, pontoY;
    int n;
    printf("Insira as coordenadas do centro da circunferencia e o numero  n de pontos: ");
    scanf("%lf %lf %d", &x_0, &y_0, &n);
    printf("\n");

    /* Le os n pontos e calcula a distancia entre esses e o ponto (x,y)*/
    printf("Insira as coordenadas dos n pontos: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf ", &pontoX, &pontoY);
        dist[i] = pow((pow(x_0 - pontoX, 2) + pow(y_0 - pontoY, 2)), 0.5);
    }

    /* Zera os valores  de dist que já foram apresentados antes */
    int dist_iguais = 0;
    for (int j = 0; j < n; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if (dist[k] == dist[j])
            {
                dist[k] = 0;
                dist_iguais++;
            }
        }
    }

    /* Imprime apenas os raios distintos */
    printf("Raios: ");
    for(int m = 0; m < n; m++)
    {
        if (dist[m] != 0)
        {
            printf("%.2f ", dist[m]);
        }
    }
    printf("\n");
    return 0;
}

