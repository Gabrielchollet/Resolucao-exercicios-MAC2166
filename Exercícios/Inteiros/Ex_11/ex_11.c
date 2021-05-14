#include <stdio.h>

int main() {
    int n,         /* Candidato a primo */
        div,       /* Candidato a divisor */
        cont = 0; /* Conta o numero de divisores positivos de n */

    printf("\n\tTeste de primalidade\n");
    printf("\nDigite um inteiro: ");
    scanf("%d", &n);
    printf ("Candidato a primo = %d\n", n);

    for (div = 1; div <= n; div++) {
        if (n % div == 0) {
            cont++;
        }
    }

  printf("O inteiro %d ", n);
  if (cont == 2)
    { /* este par de chaves eh superfluo, mas ha' que goste ;-) */
      printf("e' primo\n");
    }
  else
    {
      printf("nao eh primo\n");
    }
  return 0;
}
