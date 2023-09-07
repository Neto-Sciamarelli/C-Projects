#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define linha 100
#define tamanho 1000

int busca_binaria(char matriz[][linha], int n, char palavra[]) {
	int i, inicio, fim, meio;
	inicio = 0;
	fim = n-1;

	while (inicio <= fim) {
		meio = (inicio + fim)/2;
		
		int comparacao =  strcmp(matriz[meio],  palavra);
		if (comparacao == 0) {
			return meio;
		}
		else if (comparacao < 0) {
			inicio = meio+1;
		}
		else {
			fim = meio-1;
		}
	}
	
	return -1;
}

void ord(char matriz[][linha], int linhas) {
    int i, j;
    char temp[linha];

    for (i = 0; i < linhas - 1; i++) {
        for (j = 0; j < linhas - i; j++) {
            if (strcmp(matriz[j], matriz[j + 1]) > 0) {
                strcpy(temp, matriz[j]);
                strcpy(matriz[j], matriz[j + 1]);
                strcpy(matriz[j + 1], temp);
            }
        }
    }
}

void dic(FILE*arquivo, char matriz[][linha]) {
	char palavra[linha];
	int i, contadorPalavras;
	contadorPalavras = 0;
	while (fscanf(arquivo, "%s", palavra) != EOF) {
    	strlwr(palavra);
        if(busca_binaria(matriz, contadorPalavras, palavra) == -1) {
        	strcpy(matriz[contadorPalavras], palavra);
        	ord(matriz, contadorPalavras);
        	contadorPalavras++;
		}

        if (contadorPalavras == linha) {
            printf("Limite máximo de palavras atingido.\n");
            break;
        }
    }

    fclose(arquivo);
    
    for (i = 0; i < contadorPalavras; i++) {
        printf("%s\n", matriz[i]);
    }
    
    printf("TOTAL DE PALAVRAS:  %d", contadorPalavras);
}

int main() {
    char matrizPalavras[tamanho][linha];

    FILE *arquivo;
    arquivo = fopen("texto.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("DICIONARIO DO SAMUEL:\n");
    dic(arquivo, matrizPalavras);
    
    return 0;
}
