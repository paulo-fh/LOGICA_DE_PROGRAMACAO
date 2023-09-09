/*EXERC�CIO PROPOSTO:
Desenvolva o projeto de uma matriz de 4 linhas e 6 colunas, que apare�a na tela com o design conforme o Box 7.

-------------------------
|   |   |   |   |   |   |
-------------------------
|   |   |   |   |   |   |
-------------------------
|   |   |   |   |   |   |
-------------------------
|   |   |   |   |   |   |
-------------------------

Elabore uma interface onde o usu�rio digita o n�mero da linha e n�mero da coluna e um n�mero inteiro de 0 a 999.
A matriz vai sendo preenchida a medida que o usu�rio vai inserindo novas entradas. Importante: neste sistema as 
linhas e colunas devem come�ar com �ndice 1. E todos os conte�dos devem ser inicializados em 0. Se digitado o n�mero
de linha ou um n�mero de coluna fora do eixo da matriz, simplismente n�o atualiza nada.
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

/*Fun��o para imprimir linhas*/
void line(int n, char ch)
{
	int i;
	
	for(i=0; i<n; i++)
		putchar(ch);
	putchar('\n');
} /* end line */

/*Fun��o para iniciar a matriz em zero*/
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

/*Fun��o para imprimir a matriz */
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
