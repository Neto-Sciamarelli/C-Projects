#include <stdio.h>
#include <stdio.h>
#include <time.h>

int main() {
    int num, palpite, tentativas;
    srand(time(NULL));

    num = 1 + rand()%100;
    tentativas = 5;

    while (tentativas > 0) {
        printf("Digite seu palpite (de 1 a 100): ");
        scanf("%d", &palpite);

        if(palpite == num) {
            printf("Parabens vc acertou! O numero realmente era %d!\n", num);
            break;
        }else {
            if(palpite > num) {
                printf("Vc chutou muito alto!\n");
            }else {
                printf("Vc chutou muito baixo!\n");
            }
        }

        tentativas--;
    }

    if(tentativas <= 0) {
        printf("Vc excedeu suas tentativas!\n");
    }

    return 0;

    
}