#include <stdio.h>
#include <stdio.h>
#include <time.h>

int main() {
    int num, palpite, aux, tentativas;
    srand(time(NULL));

    num = 1 + rand()%100;
    aux = 0;
    tentativas = 0;

    while (aux == 0) {
        printf("Digite seu palpite (de 1 a 100): ");
        scanf("%d", &palpite);

        if(palpite == num) {
            printf("Parabens vc acertou! O numero realmente era %d!\n", num);
            aux = 1;
            tentativas++;
        }else {
            if(palpite > num) {
                printf("Vc chutou muito alto!\n");
                tentativas++;
            }else {
                printf("Vc chutou muito baixo!\n");
                tentativas++;
            }
        }
    }

    printf("Vc acertou depois de %d tentativas!", tentativas);

    return 0;

    
}