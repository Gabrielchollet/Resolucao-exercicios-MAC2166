/*
    Dados um inteiro positivo n e uma sequencia de n numeros,
    imprimi-la na ordem inversa a de leitura
*/
#include <stdio.h>
#define max 100

int main()
{
    int seq[max], n;
    printf("Numero de elementos da sequencia: ");
    scanf("%d", &n);
    printf("Sequencia: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &seq[i]);
    }
    printf("Ordem inversa da sequencia: ");
    for (int j = n - 1; j >= 0 ; j--)
    {
        printf("%d ", seq[j]);
    }
    return 0;
}
