#include <stdio.h>

int notaMaxima = 100;
int notaMinima = 0;

int main() {
    int n,/*guarda o numero de alunos*/
     nota,/*guarda cada nota lida*/
    notaMaxima = 0,
    notaMinima = 100;

     /*inicializando*/
     printf("\n\tIndica a menor e a maior nota obtida pela turma\n");
     printf("\nDigite o numero de alunos: ");
     scanf("%d", n);

     for (int i = 0; i < n; i++) {
        scanf("%d ", &nota);
        if (nota > notaMaxima) {
            notaMaxima = nota;
        }
        if (nota < notaMinima) {
            notaMinima = nota;
        }
     }
     printf("\nA nota maxima eh %d\n", notaMaxima);
     printf("\nA nota minima eh %d\n", notaMinima);
     return 0;
}
