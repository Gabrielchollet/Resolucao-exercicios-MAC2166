#include <stdio.h>
#define TRUE 0
#define FALSE 1
/*Diz se uma sequencia numerica eh ordenada*/
int main() {
    int first_num, second_num, i = 0, cresc = 0;
    scanf("%d ", &first_num);

    while (cresc) {
        scanf("%d ", second_num);
        if (first_num > second_num) {
            cresc = 1;
        }
        else {
            scanf("%d ", &first_num);
        }
    }
    if (cresc = 0) {
        printf("A sequencia eh crescente\n");
    }
    else {
        printf("A sequencia NAO eh crescente\n");
    }
    return 0;
}
