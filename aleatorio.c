#include <stdio.h>
#include <conio.c>
#include <time.h>

main() {
	int matriz[4][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{1,2,3,4,5},
		{6,7,8,9,10}
	};
	
	int i, j;
	
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 5; j++) {
			gotoxy(2+(j*5),2+(i*2));
			printf("%i",matriz[i][j]);
		}
	}
	
	int seg = 0, linha = 0, coluna = 0;
	seg = time(0);
	srand(seg);
	int aux = 0;
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 5; j++) {
			linha = rand() % 4;
			coluna = rand() % 5;
			aux = matriz[i][j];
			matriz[i][j] = matriz[linha][coluna];
			matriz[linha][coluna] = aux;
			gotoxy(2+(j*5),10+(i*2));
			printf("%i/%i",linha,coluna);
		}
	}
	
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 5; j++) {
			gotoxy(2+(j*5),18+(i*2));
			printf("%i",matriz[i][j]);
		}
	}
}
