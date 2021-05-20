/*
    Dados dois numeros inteiro positivos n1 e n2, determine o MDC entre eles a partir
    de sua decomposição em fatores primos:
    Ex.: para entrada 120 84
           a saida eh 12
*/

int main() {
    int a, b, resultado, adec, m;

    scanf("%d %d ", &a, &b);

    printf("MDC(%d,%d): %d = ", a, b, mdc(a,b));

    adec = mdc(a,b);

    for (int i = 2; i <= adec; i++) {
        for (m = 0; adec % i == 0; m++) {
            adec = adec / i;
        }
        if (m != 0) {
            printf("%d^%d +", i, m);
        }
    }
    return 0;
}

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        mdc(b, a % b);
    }
}
