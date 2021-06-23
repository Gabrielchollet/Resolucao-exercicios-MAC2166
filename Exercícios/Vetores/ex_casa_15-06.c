/*
    Dados n >= 0, o grau do polinomio
    p(x) = p_0 + p_1*x^1 + ... + p_n*x^n,
    dados seus respectivos coeficientes bem como um ponto x_0,
    calcular p(x_0), a aplicacao de p(x) no ponto x_0.

    Ex.: para n = 2, p(x) = 1 - 2x + x^2 e x_0 = 1, temos que p(1) = 0
*/

#include <stdio.h>
#define max 10

int elevado(int x, int n);

int main()
{
    int grau, coef[max], x_0, soma = 0;
    scanf("%d", &grau);

    printf("Insira o valor dos coeficientes do polinomio:\n");
    for (int i = 0; i <= grau + 1; i++)
    {
        scanf("%d ", &coef[i]);
    }

    printf("Valor do ponto x_0: ");
    scanf("%d", &x_0);

    for (int j = 0; j <= grau; j++)
    {
        soma += coef[j] * elevado(x_0, j);
    }

    printf("P(%d) = %d\n", x_0, soma);

    return 0;
}

int elevado(int x, int n)
{
    int potencia = 1;
    for (int i = 0; i < n; i++) {
        potencia *= x;
    }
    return potencia;
}
