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
void imprimeNumerao(int a, int b, int num[], int tamNum);

/* Soma ’a’ e ’b’ e guarda o resultado (a+b) em ’a’
’b’ não é modificado
retorna a quantidade de dígitos do resultado */
int soma(int a[], int tamA, int b[], int tamB);

/* Vetores que guardaram os algarismos do numerao 'a' e do numerao 'b' */
int num_a[TAM_MAX], num_b[TAM_MAX];

/* Soma a soma dos n primeiros inteiros naturais */
int soma_de_n(int n, int num_tot[], int num_i[]);

int main()
{
    int escolha, a, b, tamNum_a, tamNum_b, tamNum_soma;
    printf("Digite 0 (soma) ou 1 (soma naturais): ");
    scanf("%d", &escolha);
    printf("\n");
    if (escolha == 0)
    {
        /* Ler 'a' e 'b' */
        printf("Digite o primeiro numero: ");
        scanf("%d", &a);
        printf("\n");
        printf("Digite o segundo numero: ");
        scanf("%d", &b);
        printf("\n");
        /* Criar numerao A e numerao B */
        tamNum_a = criaNumerao(a, num_a);
        tamNum_b = criaNumerao(b, num_b);
        /* Soma */
        tamNum_soma = soma(num_a, tamNum_a, num_b, tamNum_b);
        /* Imprime o numerao A */
        printf("Soma: ");
        imprimeNumerao(a, b, num_a, tamNum_soma);
        printf("\n");
    }
    else
    {
        printf("Entre com valor de n para soma dos n primeiros naturais: ");
        scanf("%d", &a);
        printf("\n");
        /* Soma dos n naturais */
        tamNum_soma = soma_de_n(a, num_a, num_b);
        printf("Soma dos %d primeiros naturais = ", a);
        imprimeNumerao(a, 0, num_a, tamNum_soma);
        printf("\n");
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
    /* Verificar o sinal do resultado das somas */
    int soma_esq = 0;

    if (a >= 0 && b < 0 && (a < (-1 * b)))
    {
        num[0] = -1;
    }
    else if (a < 0 && b >= 0 && ((-1 * a) < b))
    {
        num[0] = 1;
    }
    else if (a == (-1 * b))
    {
        printf("0\n");
        return;
    }

    /* IMprimir o numero obtido */
    if (num[0] == 1)
    {
        for (int i = tamNum; i > 0; i--)
        {
            soma_esq += num[i];
            if (soma_esq != 0)
            {
                printf("%d", num[i]);
            }
        }
    }
    else
    {
        printf("-");
        for (int i = tamNum; i > 0; i--)
        {
            soma_esq += num[i];
            if (soma_esq != 0)
            {
                printf("%d", num[i]);
            }
        }
    }
    printf("\n");
    return;
}

int soma(int a[], int tamA, int b[], int tamB)
{
    int numDigitos = 0;
    /* Somar 'a' e 'b' */
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
    if ((a[0] == 1 && b[0] == -1) || (a[0] == -1 && b[0] == 1))
    {
        for (int j = 1; j <= tamA || j <= tamB; j++)
        {
            if (tamA > tamB || (tamA == tamB && a[tamA] > b[tamB]))
            {
                a[j] += (-1)*b[j];
                if (a[j] < 0)
                {
                    a[j] += 10;
                    a[j + 1]--;
                    if (j == tamA && a[j + 1] == 1)
                    {
                        numDigitos--;
                    }
                }
                numDigitos++;
            }
            else if (tamA == tamB && (a[tamA] < b[tamB]))
            {
                a[j] = b[j] - a[j];
                if (a[j] < 0)
                {
                    b[j + 1]--;
                    a[j] += 10;
                }
                numDigitos++;
            }
        }
        return numDigitos;
    }
    /* Para a < 0 e b >= 0
    if (a[0] == -1 && b[0] == 1)
    {
        for (int k = 0; k <= tamA || k <= tamB; k++)
        {

        }
    }*/

    return numDigitos;
}

int soma_de_n(int n, int num_tot[], int num_i[])
{
    /*
        S = 1 + 2 + 3 + ... + n = 1/2 * ((1+2) + (2+3) + ... (n-1 + n)) + (n+1)
    */
    int numDigitos = 0, tam_i, tam_tot;
    tam_tot = criaNumerao(1, num_tot);
    for (int i = 2; i <= n; i++)
    {
        tam_i = criaNumerao(i, num_i);
        numDigitos = soma(num_tot, tam_tot, num_i, tam_i);
        tam_tot = numDigitos;

        /*
        tamNum_a = criaNumerao(i, num_a);
        tamNum_b = criaNumerao(i + 1, num_b);
        numDigitos = soma(num_a, tamNum_a, num_b, tamNum_b);
        */
    }
    return numDigitos;
}
