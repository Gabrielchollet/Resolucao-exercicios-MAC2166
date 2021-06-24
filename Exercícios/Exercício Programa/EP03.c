/*
    Vamos desenvolver uma estrutura de dados capaz de armazenar numeros muito grandes,
    superando a limitacao do tipo utilizado em C. Neste EP, deve-se ser capaz de de
    lidar com numeros inteiros grandes, sobre os quais efetuaremos a operacao de soma

*/

#include <stdio.h>
#define TAM_MAX 2021

/* Função que recebe um inteiro n e o armazena em num,
retornando a quantidade de dígitos: */
int criaNumerao(int n, int num[]);


/* Função que recebe um numerão com tamNum dígitos e o imprime: */
void imprimeNumerao(int num[], int tamNum);

/* Soma ’a’ e ’b’ e guarda o resultado (a+b) em ’a’
’b’ não é modificado
retorna a quantidade de dígitos do resultado */
int soma(int a[], int tamA, int b[], int tamB);

/* Vetores que guardaram os algarismos do numerao 'a' e do numerao 'b' */
int num_a[TAM_MAX], num_b[TAM_MAX];

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
        imprimeNumerao(num_a, tamNum_soma);
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

void imprimeNumerao(int num[], int tamNum)
{
    /* Para numeroes positivos */
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
    /* Otimizacao: pensar numa forma de não usar if's para determinar o tipo de soma entre 'a' e 'b' */
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
    /* Para os casos de a >= 0 e b < 0 */
    if (a[0] == 1 && b[0] == -1)
    {
        for (int j = 1; j <= tamA || j <= tamB; j++)
        {
            if (a[j] < b[j])
            {
                a[j + 1]--;
                a[j] += b[0]*b[j] + 10;
            }
            else
            {
                a[j] += b[0]*b[j];
            }
            numDigitos++;
        }
        return numDigitos;
    }
    /* Para a < 0 e b >= 0 */
    if (a[0] == -1 && b[0] == 1)
    {
        for (int k = 1; k <= tamA || k <= tamB; k++)
        {
            if (a[k] > b[k])
            {
                b[k + 1]--;
                a[k] = a[0]*a[k] + b[0]*b[k] + 10;
            }
            else
            {
                a[k] = a[0]*a[k] + b[0]*b[k];
            }
            numDigitos++;
        }
    }
    return numDigitos;
}
