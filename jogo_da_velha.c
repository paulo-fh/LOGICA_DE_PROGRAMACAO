#include<stdio.h>

#define  DIM  3

/*=================== FUNCTIONS PROTOTYPE ===================*/
char inic(char s[][DIM]);                 /*Inicia todos os elementos da matriz com espaço*/
char jogo(char s[][DIM]);				  /*Imprime o tabuleiro do jogo na tela*/

/*====================== MAIN FUNCTION ======================*/
main()
{
	char velha[DIM][DIM];
	char ch='0';
	int lin, col, n_jogadas=0;
	
	inic(velha);
		
	while(1)
	{
		jogo(velha);                 //Imprime o jogo em branco
		
		printf("\n\nLinha: ");
		scanf("%d",&lin);
		printf("Coluna: ");
		scanf("%d",&col);
		putchar('\n');
		
		lin--;	col--;             //Decrementa, já que inicia no índice 0
		
		if(velha[lin][col]==' ')   //Se a linha e a coluna digitada estiver vazia
		{
			velha[lin][col] = ch = (ch=='0') ? 'X' : '0';          //linha e coluna recebem ch (se ch estiver '0', recebe 'X', caso contrário recebe '0')
																   //OBS.: ch foi iniciado com '0' na declaração da variável
			
			if( (velha[0][0]=='X' && velha[0][1]=='X' && velha[0][2]=='X') || 
				(velha[1][0]=='X' && velha[1][1]=='X' && velha[1][2]=='X') ||
				(velha[2][0]=='X' && velha[2][1]=='X' && velha[2][2]=='X') ||
				(velha[0][0]=='X' && velha[1][1]=='X' && velha[2][2]=='X') ||
				(velha[0][2]=='X' && velha[1][1]=='X' && velha[2][0]=='X') ||
				(velha[0][0]=='X' && velha[1][0]=='X' && velha[2][0]=='X') ||
				(velha[0][1]=='X' && velha[1][1]=='X' && velha[2][1]=='X') ||
				(velha[0][2]=='X' && velha[1][2]=='X' && velha[2][2]=='X')  )
			{
				system("cls");
				printf("\n\tJogador 'X' venceu\n\n");
				break;
			}
			else
			if( (velha[0][0]=='0' && velha[0][1]=='0' && velha[0][2]=='0') || 
			    (velha[1][0]=='0' && velha[1][1]=='0' && velha[1][2]=='0') ||
			    (velha[2][0]=='0' && velha[2][1]=='0' && velha[2][2]=='0') ||
			    (velha[0][0]=='0' && velha[1][1]=='0' && velha[2][2]=='0') ||
			    (velha[0][2]=='0' && velha[1][1]=='0' && velha[2][0]=='0') ||
				(velha[0][0]=='0' && velha[1][0]=='0' && velha[2][0]=='0') ||
				(velha[0][1]=='0' && velha[1][1]=='0' && velha[2][1]=='0') ||
				(velha[0][2]=='0' && velha[1][2]=='0' && velha[2][2]=='0') )
			{
				system("cls");
				printf("\n\tJogador '0' venceu\n\n");
				break;
			}
			
			n_jogadas++;
			system("cls");
		}
		else
		{
			system("cls");
			printf("\n\tPosicao j\xa0 ocupada\nJogue novamente!!!\n\n");
		}
					
		if(n_jogadas==DIM*DIM)
		{
			puts("\n\tSEM VENCEDOR.\n");
			break;
		}
			
	}
			
	jogo(velha);
			
	puts("\n\n\tFIM DO JOGO!!!\n\n");
		
	system("PAUSE");
	return 0;
}

/*=================== DEVELOPMENT OF FUNCTIONS ===================*/

/*Inicia todos os elementos da matriz com espaço*/
char inic(char s[][DIM])
{
	int i, j;
	for(i=0; i<DIM; i++)
		for(j=0; j<DIM; j++)
			s[i][j] = ' ';			
}

/*Imprime o tabuleiro do jogo na tela*/
char jogo(char s[][DIM])
{
	int i, j;
	printf("   1   2   3\n\n");
	for(i=0; i<DIM; i++)
	{
		printf("%d ", i+1);
		for(j=0; j<DIM; j++)
		{
			printf(" %c %c",s[i][j], j==DIM-1 ? ' ' : '|');
		}
		
		if(i!=DIM-1)
			puts("\n  -----------");
	}
}
