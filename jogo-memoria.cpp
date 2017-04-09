#include <stdio.h>
#include <conio.c>

exibe_cartas(int cartas[4][5], int reveladas[4][5], int palpite_linha[2], char palpite_coluna[2]) {
	int i, j, cont, aux;
	char colunas[5] = {'a','b','c','d','e'};
	// exibir linha
	for(i = 0; i < 4; i++) {
		gotoxy(4, 6+(i*2));
		printf("  %i  ",i+1);
	}
	// exibir coluna
	for(j = 0; j < 5; j++) {
		gotoxy(10+(j*5), 4);
		printf("  %c  ",colunas[j]);
	}
	// exibir a matriz
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 5; j++) {
			aux = 1;
			cont = 0;
			while(cont < 2) {
				if (palpite_linha[cont] == i && palpite_coluna[cont] == colunas[j]) {
					gotoxy(9+(j*5), 5+(i*2));
					printf("-----");
					gotoxy(9+(j*5), 6+(i*2));
					printf("|> %i ", cartas[i][j]);
					gotoxy(9+(j*5), 7+(i*2));
					printf("-----");
					aux = 0;
				}
				cont++;
			}
			if (aux) {
				if (reveladas[i][j] == 1) {
					gotoxy(9+(j*5), 5+(i*2));
					printf("-----");
					gotoxy(9+(j*5), 6+(i*2));
					printf("|  %i ", cartas[i][j]);
					gotoxy(9+(j*5), 7+(i*2));
					printf("-----");
				} else {
					gotoxy(9+(j*5), 5+(i*2));
					printf("-----");
					gotoxy(9+(j*5), 6+(i*2));
					printf("|    ");
					gotoxy(9+(j*5), 7+(i*2));
					printf("-----");
				}
			}
		}
		gotoxy(9+(j*5), 5+(i*2));
		printf("-");
		gotoxy(9+(j*5), 6+(i*2));
		printf("|");
		gotoxy(9+(j*5), 7+(i*2));
		printf("-");
	}
}

main() {
	char nome[20];

	int cartas[4][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{1,2,3,4,5},
		{6,7,8,9,10}
	};
	int reveladas[4][5] = {
		{0,0,0,0,0},
		{0,0,0,0,1},
		{0,0,0,0,0},
		{0,0,0,0,1}
	};

	clrscr();

	gotoxy(4,2);
	printf("Jogo da Memoria");

	gotoxy(4,4);
	printf("Digite o seu nome: ");
	scanf(" %s", nome);

	clrscr();

	gotoxy(4,2);
	printf("Jogo da Memoria");
	
  
	// coletar os dois palpites.
	int palpite_linha[2];
	char palpite_coluna[2];
	exibe_cartas(cartas, reveladas, palpite_linha, palpite_coluna);
	int cont = 0;
	while(cont < 2) {	
		gotoxy(4,18+(cont*4));
		printf("Digite uma linha: ");
		scanf(" %i",&palpite_linha[cont]);

		gotoxy(4,20+(cont*4));
		printf("Digite uma coluna: ");
		scanf(" %c",&palpite_coluna[cont]);
		
		exibe_cartas(cartas, reveladas, palpite_linha, palpite_coluna);

		cont++;
	}

	getch();
}
