#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, palpite, aux;
    srand(time(NULL));

    num = 1 + rand()%100;
    aux = 0;

    while(aux == 0) {
       printf("Digite seu palpite (de 1 a 100): ");
      scanf("%d", &palpite);

      if (palpite >= 1 && palpite <= 100) {
        aux = 1;
      }
    }

    if(palpite == num) {
        printf("PARABENS!!! VC ACERTOU!\n");
    }else {
        if(palpite < num) {
            printf("VC CHUTOU MUITO BAIXO! O VALOR CORRETO EH %d!\n",num);
        }else {
            printf("VC CHUTOU MUITO ALTO! O VALOR EH %d!\n", num);
        }
    }

    return 0;
}