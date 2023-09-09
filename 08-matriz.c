/*EXERCÍCIO PROPOSTO:
Desenvolva o projeto de uma matriz de 4 linhas e 6 colunas, que apareça na tela com o design conforme o Box 7.

-------------------------
|   |   |   |   |   |   |
-------------------------
|   |   |   |   |   |   |
-------------------------
|   |   |   |   |   |   |
-------------------------
|   |   |   |   |   |   |
-------------------------

Elabore uma interface onde o usuário digita o número da linha e número da coluna e um número inteiro de 0 a 999.
A matriz vai sendo preenchida a medida que o usuário vai inserindo novas entradas. Importante: neste sistema as 
linhas e colunas devem começar com índice 1. E todos os conteúdos devem ser inicializados em 0. Se digitado o número
de linha ou um número de coluna fora do eixo da matriz, simplismente não atualiza nada.
*/
#include<stdio.h>

/*==========PROTOTYPE OF FUNCTIONS==========*/
void inic(int s[4][6]);
void mostra(int mat[4][6]);


/*==========MAIN FUNCTION==========*/
main()
{
	int mat[4][6];
	int row, col, num;
	
	inic(mat);
	while(1)
	{
		mostra(mat);
		printf("Linha: ");
		scanf("%d", &row);
		printf("Coluna: ");
		scanf("%d", &col);
		printf("Number: ");
		scanf("%d", &num);
		
		if(row>=0 && row <=4 && col>=0 && col<=6 && num >=0 && num<=999)
			mat[--row][--col] = num;
				
		system("cls");		
	}	
}

/*==========DEVELOPMENT OF FUNCTIONS==========*/

/*Função para imprimir linhas*/
void line(int n, char ch)
{
	int i;
	
	for(i=0; i<n; i++)
		putchar(ch);
	putchar('\n');
} /* end line */

/*Função para iniciar a matriz em zero*/
void inic(int s[4][6])
{
	int i, j;
	for(i=0; i<4; i++)
	{
		for(j=0; j<6; j++)
		{
			s[i][j] = 0;
		}
	}
}

/*Função para imprimir a matriz */
void mostra(int mat[4][6])
{
	int i, j;
	line(31, '-');
	for(i=0; i<4; i++)
	{
		for(j=0;j<6; j++)
		{
			printf("| %3d", mat[i][j]);
		}
		printf("|\n");	
		line(31, '-');	
	}
}
