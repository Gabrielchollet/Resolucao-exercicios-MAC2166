/*

*/

#include <stdio.h>
#define max 10

void swap(int *a, int *b);
void sort(int a[], int n);

int a[max][max];

int main()
{
    int n;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d ", a + j);
        }
    }
    sort(a, n);
    for (int k = 0; k < n; k++)
    {
        for (int z = 0; z < n; z++)
        {
            if (a[k][z] != z)
            {
                printf("A matriz nao eh latina\n");
                return 0;
            }
        }
    }
    printf("A matriz eh latina\n");
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}
