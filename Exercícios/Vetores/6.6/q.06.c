/*
    Dados uma palavra e uma frase, determinar o numero de vezes que a
    palavra ocorre na frase
*/

#include <stdio.h>
#define max 100

int main()
{
    char word[max], phrase[max];
    int aparece = 0;
    printf("Entre com uma palavra: ");
    scanf("%[^\n]", word);
    printf("\nEntre com uma frase: ");
    scanf(" %[^\n]", phrase);

    for (int i = 0, j = 0; phrase[i] != '\0'; i++)
    {
        if (word[j] == phrase[i])
        {
            j++;
            if (word[j] == '\0')
            {
                aparece++;
                j = 0;
                i--;
            }
        }
        else
        {
            j = 0;
        }
    }
    printf("\nA palavra %s aparece %d vezes\n", word, aparece);
    return 0;
}
