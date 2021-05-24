/*
    Sequencia de Fibonacci
    Crie um programa que dado n calcula Fn
*/

#include <stdio.h>

int fibo(int x);

int main() {
    int n;

    printf("\tFibonnaci\n");

    scanf("%d ", &n);
    printf("Fn eh igual a %d\n", fibo(n));
    return;
}

int fibo(int x) {
    int f;
    if (x == 1 || x == 2){
        return 1;
    }
    else {
    return fibo(x - 1) + fibo(x - 2);
    }
}
