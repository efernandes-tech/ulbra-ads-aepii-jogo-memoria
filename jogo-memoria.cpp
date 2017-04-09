#include <stdio.h>
#include <conio.c>

main() {
	char nome[20];
	int cartas[4][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{1,2,3,4,5},
		{6,7,8,9,10}
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
	
	int i, j;
	char colunas[5] = {'A','B','C','D','E'};
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
			gotoxy(9+(j*5), 5+(i*2));
			printf("-----");
			gotoxy(9+(j*5), 6+(i*2));
			printf("|    ");
			gotoxy(9+(j*5), 7+(i*2));
			printf("-----");
		}
		gotoxy(9+(j*5), 5+(i*2));
		printf("-");
		gotoxy(9+(j*5), 6+(i*2));
		printf("|");
		gotoxy(9+(j*5), 7+(i*2));
		printf("-");
	}
  
	// coletar os dois palpites.
	int palpite_linha[2];
	char palpite_coluna[2];
	int cont = 0;
	while(cont < 2) {		
		gotoxy(4,18+(cont*4));
		printf("Digite uma linha: ");
		scanf(" %i",&palpite_linha[cont]);

		gotoxy(4,20+(cont*4));
		printf("Digite uma coluna: ");
		scanf(" %c",&palpite_coluna[cont]);

		cont++;
	}
	
	gotoxy(1,1);
	printf("%i %i %c %c",palpite_linha[0],palpite_linha[1],palpite_coluna[0],palpite_coluna[1]);

	getch();
}
