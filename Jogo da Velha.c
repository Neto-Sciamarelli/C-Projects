#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void imprimir(char matriz[3][3]) {
	printf("   1 2 3\n");
	printf("   v v v\n");
	printf("1> %c|%c|%c\n", matriz[0][0], matriz[0][1], matriz[0][2]);
	printf("   -----\n");
	printf("2> %c|%c|%c\n", matriz[1][0], matriz[1][1], matriz[1][2]);
	printf("   -----\n");
	printf("3> %c|%c|%c\n", matriz[2][0], matriz[2][1], matriz[2][2]);
}

bool jogada_valida(char matriz[3][3], char jogador, int i, int j) {
	if(i-1 < 0 || i-1 > 2) {
		return false;
	}else if(j-1 < 0 || j-1 > 2) {
		return false;
	}
	
	if(matriz[i-1][j-1] == '.') {
		matriz[i-1][j-1] = jogador;
	}else {
		return false;
	}
	
	return true;
}

int analisar_jogo(char matriz[3][3]) {
	int i, j, contX = 0, contO = 0, contP = 0;
	
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(matriz[i][j] == 'X') {
				contX++;
			}
			if(matriz[i][j] == 'O') {
				contO++;
			}
		}
		
		if(contX == 3) {
			return 1;
		}else if(contO == 3) {
			return 2;
		} 
		contX = 0;
		contO = 0;
	}
	
	for(j = 0; j < 3; j++) {
		for(i = 0; i < 3; i++) {
			if(matriz[i][j] == 'X') {
				contX++;
			}
			if(matriz[i][j] == 'O') {
				contO++;
			}
		}
		
		if(contX == 3) {
			return 1;
		}else if(contO == 3) {
			return 2;
		}
		contX = 0;
		contO = 0;
	}
	
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(i == j) {
				if(matriz[i][j] == 'X') {
					contX++;
				}else if(matriz[i][j] == 'O') {
					contO++;
				}
			}
		}
	}
	if(contX == 3) {
			return 1;
	}else if(contO == 3) {
		return 2;
	}
	contX = 0;
	contO = 0;
	
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(i+j == 3-1) {
				if(matriz[i][j] == 'X') {
					contX++;
				}else if(matriz[i][j] == 'O') {
					contO++;
				}
			}
		}
	}
	if(contX == 3) {
		return 1;
	}else if(contO == 3) {
		return 2;
	}
	contX = 0;
	contO = 0;
	
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(matriz[i][j] == '.') {
				return 4;
			}
		}
	}
	
	return 3;
}

int main() {
	char matriz[3][3] = {{'.','.','.'}, {'.','.','.'}, {'.','.','.'}};
	int k, z, i, j, tentativas = 0;
	
	printf("JOGO DA VELHA\n");
	printf("-------------------------------------------\n");
	printf("ESCOLHA A POSICAO DE ACORDO COM O TABULEIRO\n");
	printf("-------------------------------------------\n");
	imprimir(matriz);
	
	while(tentativas < 9) {
		printf("\nEscolha o i da posicao: ");
		scanf("%d", &i);
		
		printf("Escolha o j da posicao: ");
		scanf("%d", &j);
		
		if(tentativas%2 == 0) {
			if(jogada_valida(matriz, 'X', i, j) == true) {
				jogada_valida(matriz, 'X', i, j);
				tentativas++;
			}else {
				printf("Jogada invalida!!\n");
			}
		}else {
			if(jogada_valida(matriz, 'O', i, j) == true) {
				jogada_valida(matriz, 'O', i, j);
				tentativas++;
			}else {
				printf("Jogada invalida!!\n");
			}
		}
		
		imprimir(matriz);
		z = analisar_jogo(matriz);
		
		if(z == 1) {
			printf("O jogador X ganhou!");
			break;
		}else if(z == 2) {
			printf("O jogador O ganhou!");
			break;
		}else if(z == 3) {
			printf("O jogo empatou!");
			break;
		}
	}	
	
	if(z == 4) {
		printf("O jogo deu empate!");
	}
	
}
