#include <stdio.h>
/*dados um inteiro n >= 1 e uma sequencia de n inteiros,*/
/*determinar quantos numeros da sequencia s�o pares e quantos s�o impares*/

int main() {
    int n,  /*numero de elementos da sequencia*/
      num,  /*guarda os numeros da sequencia*/
impar = 0,  /*contador �mpar*/
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
