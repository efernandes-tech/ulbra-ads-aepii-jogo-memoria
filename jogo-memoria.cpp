#include <stdio.h>
#include <conio.c>

main() {
	char nome[20];
	int matriz[4][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{1,2,3,4,5},
		{6,7,8,9,10}
	};
	int i, j;
	int ganhou = 0;
	int linha = -1, coluna = -1;

	clrscr();

	gotoxy(4,2);
	printf("Jogo da Memoria");

	gotoxy(4,4);
	printf("Digite o seu nome: ");
	scanf(" %s", nome);

	clrscr();

	gotoxy(4,2);
	printf("Jogo da Memoria");

	do {
		for(i = 0; i < 4; i++) {
			for(j = 0; j < 5; j++) {
				if (linha == i && coluna == j) {
					gotoxy(4+(j*5), 4+(i*2));
					printf("-----");
					gotoxy(4+(j*5), 5+(i*2));
					printf("|  %i  ", matriz[i][j]);
					gotoxy(4+(j*5), 6+(i*2));
					printf("-----");
				} else {
					gotoxy(4+(j*5), 4+(i*2));
					printf("-----");
					gotoxy(4+(j*5), 5+(i*2));
					printf("|    ");
					gotoxy(4+(j*5), 6+(i*2));
					printf("-----");
				}
			}
			gotoxy(4+(j*5), 4+(i*2));
			printf("-");
			gotoxy(4+(j*5), 5+(i*2));
			printf("|");
			gotoxy(4+(j*5), 6+(i*2));
			printf("-");
		}

		gotoxy(4,20);
		printf("Digite uma linha: ");
		scanf("%i", &linha);

		gotoxy(4,22);
		printf("Digite uma coluna: ");
		scanf("%i", &coluna);

	} while (!ganhou);

	getch();
}
