/*
Enunciado:
Crie um jogo da memória, onde um jogador deve adivinhar a posição de todos os
pares de números de 1 a 10 dentro de uma matriz. O sistema deve gerar uma matriz
de 4x5, com pares de números de 1 a 10, em posições aleatórias a cada
inicialização do jogo. O sistema exibe na tela a matriz sem os números
(imagem 1). A cada rodada o jogador deve escolher uma letra para a coluna e um
número para a linha, e o sistema revela o número, então o jogador escolhe outra
linha e coluna. Se os dois números forem iguais, eles permanecem revelados
(imagem 2) e o jogador ganha 10 pontos. Se não forem iguais, o jogador perde 2,5
pontos, os números são escondidos e a próxima rodada é iniciada. Quando todos os
números forem revelados, o jogo termina, e a pontuação é exibida para o jogador.

Aluno: Éderson Luis dos Reis Fernandes
Aluno: Tayson Barbosa Alves
*/

#include <stdio.h>
#include <conio.c>
#include <time.h>

void exibe_cartas(int cartas[4][5], int reveladas[4][5], int p_linha[2], int p_coluna[2]) {
	int i, j, cont;
	int nao_eh_palpite;
	char colunas[5] = {'A','B','C','D','E'};

	// Exibir as opcoes para linha.
	for(i = 1; i <= 4; i++) {
		gotoxy(4, 4+i*2);
		printf("  %i  ", i);
	}

	// Exibir as opcoes para coluna.
	for(j = 0; j < 5; j++) {
		gotoxy(10+j*5, 4);
		printf("  %c  ", colunas[j]);
	}

	// Exibir a matriz.
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 5; j++) {
			cont = 0;
			nao_eh_palpite = 1;
			// Verificar se a celula atual deve ser exibida como um palpite.
			while(cont < 2) {
				if (p_linha[cont] == i && p_coluna[cont] == j) {
					gotoxy(9+j*5, 5+i*2);
					printf("-----");
					gotoxy(9+j*5, 6+i*2);
					printf("|> %i ", cartas[i][j]);
					gotoxy(9+j*5, 7+i*2);
					printf("-----");

					nao_eh_palpite = 0;
				}
				cont++;
			}
			// Se a celula nao eh um palpite exibe se ela ja foi acertada.
			if (nao_eh_palpite) {
				if (reveladas[i][j] == 1) {
					gotoxy(9+j*5, 5+i*2);
					printf("-----");
					gotoxy(9+j*5, 6+i*2);
					printf("|  %i ", cartas[i][j]);
					gotoxy(9+j*5, 7+i*2);
					printf("-----");
				} else {
					gotoxy(9+j*5, 5+i*2);
					printf("-----");
					gotoxy(9+j*5, 6+i*2);
					printf("|    ");
					gotoxy(9+j*5, 7+i*2);
					printf("-----");
				}
			}
		}
		gotoxy(9+j*5, 5+i*2);
		printf("-");
		gotoxy(9+j*5, 6+i*2);
		printf("|");
		gotoxy(9+j*5, 7+i*2);
		printf("-");
	}
}

main() {
	int cartas[4][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{1,2,3,4,5},
		{6,7,8,9,10}
	};

	/*
		Percorre todos os valores da matriz e troca por uma posicao aleatoria.
	*/
	int i, j;
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

	// Matriz que indica as cartas ja acertadas, 1 = exibe.
	int reveladas[4][5] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
	};

	char nome[20];
	int ganhou = 0, perdeu = 0;
	float pontuacao = 0;
	char continuar;

	clrscr();

	gotoxy(4,2);
	printf("Jogo da Memoria!");

	gotoxy(4,4);
	printf("Digite o seu nome: ");
	scanf(" %s", nome);

	do {
		clrscr();

		gotoxy(4,2);
		printf("Jogo da Memoria!");

		gotoxy(32, 2);
		printf("%.1f", pontuacao);

		// Coletar os dois palpites.
		int palpite_linha[2] = {-1,-1};
		int palpite_coluna[2] = {-1,-1};
		int linha;
		char coluna;
		int cont = 0;

		// Exibe a matriz se nenhum palpite.
		exibe_cartas(cartas, reveladas, palpite_linha, palpite_coluna);

		while(cont < 2) {	
			gotoxy(4,15+cont*4);
			printf("Digite uma linha: ");
			scanf(" %i",&linha);

			// Palpite de linha deve ser menos 1 pq a matriz inicia em 0.
			palpite_linha[cont] = linha - 1;

			gotoxy(4,17+cont*4);
			printf("Digite uma coluna: ");
			scanf(" %c",&coluna);

			// Muda para caixa alta assim o jogador pode digitar 'a' ou 'A'. 
			coluna = toupper(coluna);

			// Troca de letra para numero pq o indice da matriz e numerico.
			switch(coluna) {
				case 'A':
					palpite_coluna[cont] = 0;
					break;
				case 'B':
					palpite_coluna[cont] = 1;
					break;
				case 'C':
					palpite_coluna[cont] = 2;
					break;
				case 'D':
					palpite_coluna[cont] = 3;
					break;
				case 'E':
					palpite_coluna[cont] = 4;
					break;
			}

			// Exibe a matriz indicando os palpites.
			exibe_cartas(cartas, reveladas, palpite_linha, palpite_coluna);

			cont++;
		}

		// Testa se os dois palpites sao iguais && nao sao a mesma celula.
		if ((cartas[palpite_linha[0]][palpite_coluna[0]] == cartas[palpite_linha[1]][palpite_coluna[1]])
			&& (palpite_linha[0] != palpite_linha[1] || palpite_coluna[0] != palpite_coluna[1])) {
			gotoxy(4,23);
			printf("Voce acertou!");

			// Cartas sao marcadas como acerto.
			reveladas[palpite_linha[0]][palpite_coluna[0]] = 1;
			reveladas[palpite_linha[1]][palpite_coluna[1]] = 1;
			
			palpite_linha[0] = -1;
			palpite_linha[1] = -1;
			palpite_coluna[0] = -1;
			palpite_coluna[1] = -1;

			pontuacao += 10;
		} else {
			gotoxy(4,23);
			printf("Voce errou!");

			pontuacao -= 2.5;
		}

		gotoxy(4,25);
		printf("Continuar (S/N)?  ");
		continuar = getch();

		continuar = toupper(continuar);

		if (continuar == 'N') {
			perdeu = 1;
			break;
		}

		// Verifica se ganhou quando todas forem reveladas.
		ganhou = 1;
		for(i = 0; i < 4; i++) {
			for(j = 0; j < 5; j++) {
				if (reveladas[i][j] == 0)
					ganhou = 0;
			}
		}

	} while (!ganhou && !perdeu);

	clrscr();
	gotoxy(4,2);
	printf("Fim!");

	if (ganhou == 1) {
		gotoxy(4,4);
		printf("Parabens %s!", nome);

		gotoxy(4,4);
		printf("Voce fez %.1f pontos!", (pontuacao < 0) ? 0 : pontuacao);
	} else {
		gotoxy(4,4);
		printf("Volte sempre %s!", nome);
	}

	getch();
}
