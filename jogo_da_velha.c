#include<stdio.h>

#define  DIM  3

/*=================== FUNCTIONS PROTOTYPE ===================*/
char inic(char s[][DIM]); 
char jogo(char s[][DIM]);

/*====================== MAIN FUNCTION ======================*/
main()
{
	char velha[DIM][DIM];
	char ch='0';
	int lin, col, n_jogadas=0;
	
	inic(velha);
		
	while(1)
	{
		jogo(velha);
		
		printf("\n\nLinha: ");
		scanf("%d",&lin);
		printf("Coluna: ");
		scanf("%d",&col);
		putchar('\n');
		
		lin--;
		col--;
		
		if(velha[lin][col]==' ')
		{
			velha[lin][col] = ch = (ch=='0') ? 'X' : '0';
			
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
				printf("Jogados X venceu\n\n");
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
				printf("Jogados 0 venceu\n\n");
				break;
			}
			
			n_jogadas++;
			system("cls");
		}
		else
		{
			system("cls");
			printf("Posicao j\xa0 ocupada\nJogue novamente!!!\n\n");
		}			
		if(n_jogadas==DIM*DIM)
			break;
	}
			
	jogo(velha);
			
	printf("\n\nFIM DO JOGO!!!\n\n");
		
	system("PAUSE");
	return 0;
}

/*=================== DEVELOPMENT OF FUNCTIONS ===================*/
char inic(char s[][DIM])
{
	int i, j;
	for(i=0; i<DIM; i++)
		for(j=0; j<DIM; j++)
			s[i][j] = ' ';			
}

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
