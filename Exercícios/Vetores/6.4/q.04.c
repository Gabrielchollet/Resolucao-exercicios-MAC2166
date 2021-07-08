#include <stdio.h>
#define max 10

int main()
{
    int x[max], y[max], /* vetores */
        n,    /* numero de elementos dos vetores */
        prod_esc = 0;

    scanf("%d", &n);
    printf("Imprima os elementos de x: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", x + i);
    }
    printf("\n");

    printf("Imprima os elementos de y: ");
    for (int j = 0; j < n; j++)
    {
        scanf("%d ", y + j);
    }
    printf("\n");

    for (int k = 0; k < n; k++)
    {
        prod_esc += x[k] * y[k];
    }
    printf("x . y = %d\n", prod_esc);

    return 0;
}
