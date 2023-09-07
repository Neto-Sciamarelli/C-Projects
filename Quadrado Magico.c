#include <stdio.h>
#include <stdlib.h>
#define linha 50
#define coluna 50

int quadrado(int matriz[][coluna], int l, int c) {
	int i, j, soma, soma2, soma3;
	soma = 0;
	soma2 = 0;
	soma3 = 0;
	
	if(l != c) {
		return 0;
	} 
	
	for(i = 0; i < 1; i++) {
		for(j = 0; j < c; j++) {
			soma += matriz[i][j];
		}
	}
	
	for(i = 1; i < l-1; i++) {
		for(j = 0; j < c; j++) {
			soma2 += matriz[i][j];
		}
		if(soma != soma2) {
			return 0;
		}else {
			soma2 = 0;
		}
	}
	
	for(j = 0; j < c; j++) {
		for(i = 0; i < l; i++) {
			soma2 += matriz[i][j];
		}
		if(soma != soma2) {
			return 0;
		}else {
			soma2 = 0;
		}
	}
	
	for(i = 0; i < l; i++) {
		for(j = 0; j < c; j++) {
			if(i == j) {
				soma2 += matriz[i][j];
			}
			if((i+j) == l-1) {
				soma3 += matriz[i][j];
			}
		}
	}
	
	if(soma != soma2 || soma != soma3) {
		return 0;
	}
	
	return 1;
}

int main() {
	int l, c, z, matriz[linha][coluna], i, j;
	srand(time(NULL));
	
	printf("Digite o numero de linhas: ");
	scanf("%d", &l);
	
	printf("Digite o numero de colunas: ");
	scanf("%d", &c);
	
	for(i = 0; i < l; i++) {
		for(j = 0; j < c; j++) {
			matriz[i][j] = rand()%10 + 1;
			printf(" %d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	z = quadrado(matriz, l, c);
	
	if(z == 1) {
		printf("A matriz eh um quadrado magico!");
	}else {
		printf("A matriz nao eh um quadrado magico!");
	}
	
	return 0;
}





















