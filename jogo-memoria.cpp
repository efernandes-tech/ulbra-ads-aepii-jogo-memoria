#include <stdio.h>
#include <conio.c>
#include <time.h>

exibe_cartas(int cartas[4][5], int reveladas[4][5], int palpite_linha[2], int palpite_coluna[2]) {
	int i, j, cont, aux;
	char colunas[5] = {'a','b','c','d','e'};
	// exibir linha.
	for(i = 0; i < 4; i++) {
		gotoxy(4, 6+(i*2));
		printf("  %i  ",i+1);
	}
	// exibir coluna.
	for(j = 0; j < 5; j++) {
		gotoxy(10+(j*5), 4);
		printf("  %c  ",colunas[j]);
	}
	// exibir a matriz.
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 5; j++) {
			aux = 1;
			cont = 0;
			while(cont < 2) {
				if (palpite_linha[cont] == i && palpite_coluna[cont] == j) {
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
	
	int i, j;
	
	/*
		Percorre todos os valores da matriz
		e troca por uma posicao aleatoria.
	*/
	int segundos = 0, linha = 0, coluna = 0, aux = 0;
	// Gera um timestamp.
	segundos = time(0);
	// Semear com os segundos para evitar que o numero aleatorio seja sempre o mesmo.
	srand(segundos);
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 5; j++) {
			// Gera um numero de 0 a 4.
			linha = rand() % 4;
			// Gera um numero de 0 a 5.
			coluna = rand() % 5;
			// Realiza a troca dos numeros.
			aux = cartas[i][j];
			cartas[i][j] = cartas[linha][coluna];
			cartas[linha][coluna] = aux;
		}
	}
	
	/*int reveladas[4][5] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
	};*/
	int reveladas[4][5] = {
		{1,1,1,1,1},
		{1,1,1,1,1},
		{1,1,1,1,1},
		{1,1,1,1,1}
	};
	
	int ganhou = 0;

	float pontuacao = 0;

	clrscr();

	gotoxy(4,2);
	printf("Jogo da Memoria");

	gotoxy(4,4);
	printf("Digite o seu nome: ");
	scanf(" %s", nome);

	do {
		clrscr();
	
		gotoxy(4,2);
		printf("Jogo da Memoria");
		
		gotoxy(32, 2);
		printf("%.1f", pontuacao);

		// coletar os dois palpites.
		int palpite_linha[2] = {-1,-1};
		int palpite_coluna[2] = {-1,-1};
		int linha;
		char coluna;
		exibe_cartas(cartas, reveladas, palpite_linha, palpite_coluna);
		int cont = 0;
		while(cont < 2) {	
			gotoxy(4,18+(cont*4));
			printf("Digite uma linha: ");
			scanf(" %i",&linha);
			
			// validar linha.
			palpite_linha[cont] = linha-1;
	
			gotoxy(4,20+(cont*4));
			printf("Digite uma coluna: ");
			scanf(" %c",&coluna);
			
			// validar coluna.
			switch(coluna) {
				case 'a':
					palpite_coluna[cont] = 0;
					break;
				case 'b':
					palpite_coluna[cont] = 1;
					break;
				case 'c':
					palpite_coluna[cont] = 2;
					break;
				case 'd':
					palpite_coluna[cont] = 3;
					break;
				case 'e':
					palpite_coluna[cont] = 4;
					break;
			}
			
			exibe_cartas(cartas, reveladas, palpite_linha, palpite_coluna);
	
			cont++;
		}
		
		// testar os dois palpites
		if (cartas[palpite_linha[0]][palpite_coluna[0]] == cartas[palpite_linha[1]][palpite_coluna[1]]) {
			gotoxy(4,15);
			printf("Vc acertou!");
			reveladas[palpite_linha[0]][palpite_coluna[0]] = 1;
			reveladas[palpite_linha[1]][palpite_coluna[1]] = 1;
			
			pontuacao += 10;
		} else {
			gotoxy(4,15);
			printf("Vc errou!");
			
			pontuacao -= 2.5;
		}
		
		getch();

		// verifica se ganhou quando todas forem reveladas
		for(i = 0; i < 4; i++) {
			for(j = 0; j < 5; j++) {
				if (reveladas[i][j] == 0) {
					ganhou = 0;
					break;
				}
				else
					ganhou = 1;
			}
		}
		
	} while (!ganhou);
	
	clrscr();
	gotoxy(4,2);
	printf("Fim!");
	
	gotoxy(4,4);
	printf("Parabens %s!", nome);
	
	gotoxy(4,4);
	printf("voce fez %.1f pontos!", (pontuacao < 0) ? 0 : pontuacao);

	getch();
}
