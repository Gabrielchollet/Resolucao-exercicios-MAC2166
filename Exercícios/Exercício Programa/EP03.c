/*
    Vamos desenvolver uma estrutura de dados capaz de armazenar numeros muito grandes,
    superando a limitacao do tipo utilizado em C. Neste EP, deve-se ser capaz de de
    lidar com numeros inteiros grandes, sobre os quais efetuaremos a operacao de soma

*/

#include <stdio.h>
#define TAM_MAX 10

/* Fun��o que recebe um inteiro n e o armazena em num,
retornando a quantidade de d�gitos: */
int criaNumerao(int n, int num[]);


/* Fun��o que recebe um numer�o com tamNum d�gitos e o imprime: */
void imprimeNumerao(int a, int b, int num[], int tamNum);

/* Soma �a� e �b� e guarda o resultado (a+b) em �a�
�b� n�o � modificado
retorna a quantidade de d�gitos do resultado */
int soma(int a[], int tamA, int b[], int tamB);

/* Vetores que guardaram os algarismos do numerao 'a' e do numerao 'b' */
int num_a[TAM_MAX], num_b[TAM_MAX];

int sinal(int a[], int tamA, int b[], int tamB);

int main()
{
    int escolha, a, b, tamNum_a, tamNum_b, tamNum_soma;
    printf("Digite 0 (soma) ou 1 (soma naturais): ");
    scanf("%d", &escolha);
    if (escolha == 0)
    {
        /* Ler 'a' e 'b' */
        printf("Digite o primeiro numero: ");
        scanf("%d", &a);
        printf("Digite o segundo numero: ");
        scanf("%d", &b);
        /* Criar numerao A e numerao B*/
        tamNum_a = criaNumerao(a, num_a);
        tamNum_b = criaNumerao(b, num_b);
        /*TODO: soma*/
        tamNum_soma = soma(num_a, tamNum_a, num_b, tamNum_b);
        /*TODO: imprime o numerao A*/
        imprimeNumerao(a, b, num_a, tamNum_soma);
    }
    else
    {
        printf("Entre com valor de n para soma dos n primeiros naturais:");
        scanf("%d", &a);
    }
    return 0;
}

int criaNumerao(int n, int num[])
{
    int numDigitos = 0;
    if (n > 0)
    {
        num[0] = 1;
        for (; n > 0; numDigitos++)
        {
            num[numDigitos + 1] = n % 10;
            n /= 10;
        }
    }
    else
    {
        num[0] = -1;
        n *= -1;
        for (; n > 0; numDigitos++)
        {
            num[numDigitos + 1] = n % 10;
            n /= 10;
        }
    }
    return numDigitos;
}

void imprimeNumerao(int a, int b, int num[], int tamNum)
{
    /* Para numeroes positivos */
    if (a * -1 <= b)
    {
        num_a[0] = 1;
    }
    else if (b * -1 >= a)
    {
        num_a[0] = -1;
    }
    if (num[0] == 1)
    {
        for (int i = tamNum; i > 0; i--)
        {
            printf("%d", num[i]);
        }
    }
    else
    {
        printf("-");
        for (int i = tamNum; i > 0; i--)
        {
            printf("%d", num[i]);
        }
    }
    printf("\n");
    return;
}

int soma(int a[], int tamA, int b[], int tamB)
{
    int numDigitos = 0;
    /*TODO: soma 'a' e 'b' */
    /* Otimizacao: pensar numa forma de n�o usar if's para determinar o tipo de soma entre 'a' e 'b' */
    /* Para os casos de a >= 0 e b >= 0, e a < 0 e b < 0 */
    if ((a[0] == 1 && b[0] == 1) || (a[0] == -1 && b[0] == -1))
    {
        for (int i = 1; i <= tamA || i <= tamB; i++)
        {
            a[i] += b[i];
            if (a[i] >= 10)
            {
                a[i + 1] += a[i] / 10;
                a[i] %= 10;

                if (i >= tamA)
                {
                    numDigitos++;
                }
            }
            numDigitos++;
        }
        return numDigitos;
    }
    /* Para os casos de a >= 0 e b < 0
    for (int j = 1; j <= tamA || j <= tamB; j++)
    {
        a[0] = sinal(a, tamNum_a, b, tamNum_b);
    }*/
    /* Para a < 0 e b >= 0 */

    return numDigitos;
}
