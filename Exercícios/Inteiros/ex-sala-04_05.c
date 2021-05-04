#include <stdio.h>
/*dados um inteiro n >= 1 e uma sequencia de n inteiros,*/
/*determinar quantos numeros da sequencia são pares e quantos são impares*/

int main() {
    int n,  /*numero de elementos da sequencia*/
      num,  /*guarda os numeros da sequencia*/
impar = 0,  /*contador ímpar*/
  par = 0;  /*contador par*/

    scanf("%d ", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d ", &num);
        if (num%2 == 0) {
            par++;
        }
        else {
            impar++;
        }
    }
    printf("\n%d %d\n", par, impar);
    return 0;
}
