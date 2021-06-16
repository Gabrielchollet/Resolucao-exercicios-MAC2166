#include <stdio.h>

int main()
{
    int seq[6], n, number;

    for (int i = 0; i < 6; i++)
    {
        seq[i] = 0;
    }

    printf("Entre com o numero de lancamentos n > 0: \n");
    scanf("%d", &n);

    printf("Digite os numeros obtidos: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &number);
        switch (number)
        {
            case 1 :
            seq[0]++;
            break;

            case 2 :
            seq[1]++;
            break;

            case 3 :
            seq[2]++;
            break;

            case 4 :
            seq[3]++;
            break;

            case 5 :
            seq[4]++;
            break;

            case 6 :
            seq[5]++;
            break;
        }
    }

    printf("O numero 1 aparece %d vezes\n", seq[0]);
    printf("O numero 2 aparece %d vezes\n", seq[1]);
    printf("O numero 3 aparece %d vezes\n", seq[2]);
    printf("O numero 4 aparece %d vezes\n", seq[3]);
    printf("O numero 5 aparece %d vezes\n", seq[4]);
    printf("O numero 6 aparece %d vezes\n", seq[5]);
    return 0;
}
