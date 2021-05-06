#include <stdio.h>
#define TRUE 0
#define FALSE 1
/*Diz quantos alunos ficaram abaixo da media da turma*/
int main() {
    int *nota;
    int n, total = 0, media, reprovados = 0;

    /*registra as notas em um array dinamico*/
    scanf("%d ", &n);
    notas = malloc (n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d ", &nota[i]);
        total += nota[i];
    }
    media = total / n;
    /*verifica se a nota do aluno i foi menor que a media*/
    for ( int j = 0; j < n; j++) {
        if (nota[j] < media) {
            reprovados++;
        }
    }
    printf("A media é igual a %d", )
    printf("O numero de alunos reprovados é: %d\n", reprovados);
    free (nota)
    return 0;
}
