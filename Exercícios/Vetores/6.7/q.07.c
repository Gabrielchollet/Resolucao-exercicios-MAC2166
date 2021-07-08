#include <stdio.h>
#define max 10
void troca (float *a, float *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void sort(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i+1])
        {
            troca(&a[i], &a[i+1]);
        }
    }
}

int main()
{
    int n, freq[max], cont = 0;
    float num[max], var;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f ", num + i);
    }
    sort(num, n);
    var = num[0];
    for (int j = 1; j < n; j++)
    {
        if (var == num[j])
        {
            freq[cont]++;
        }
        else
        {
            printf("%f ocorre %d vezes\n", var, freq[cont]);
            var = num[j];
            cont++;
        }
    }

    return 0;
}
