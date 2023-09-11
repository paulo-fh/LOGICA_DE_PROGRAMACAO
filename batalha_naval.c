#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*==================== PROTOTYPE OF FUNCTIONS ====================*/
void naval(char b[][10]);          /*Function to draw the matrix*/
void new_seed();                   /*Function to generate randon numbers*/
unsigned map_col(char col);        /*convert letter column to number column*/

/*======================== MAIN FUNCTION ========================*/
main()
{
	char boats[8][10] = {0},   //starts all elements with 0 (zero)
		 opt  = 'j',
		 sort =  1,
		 col  =  0;
	unsigned num,
			 row     = 0,
			 acertos = 0,
			 erros   = 0;
	register int i, j;
	
	do{
		if(sort)
		{
			system("cls");
			new_seed();
			
			for(i=0; i<8; i++)
			{
				for(j=0; j<10; j++)
				{
					num = rand() % 100 + 1;
					if(num%2)
						boats[i][j] = '@';
					else
						boats[i][j] = 0x20;
				}
			}
			
			naval(boats);
		}
		else
		{
			printf("Opcao invalida\n");
			sort = 1;
		}
		
		printf("(s) Sortear novamente\n");
		printf("(j) Jogar!\n>>> ");
		scanf(" %c", &opt);
		
		if(opt!='s' && opt!='S')
			sort = 0;
		
	}while(opt!='j' && opt!='J');
	
	system("cls");
	naval(boats);
	printf("ALVOS ATINGIDOS: %3d | ERROS: %3d\n", acertos, erros);
	
	while(1)
	{
		printf("Digite a posicao para o disparo: ");
		scanf(" %c%d",&col,&row);
		
		system("cls");
		
		if(boats[row-1][map_col(col)] == '@')
		{
			boats[row-1][map_col(col)] = '*';
			acertos++;
			putchar('\a');
		}
		else
		{
			erros++;
			putchar('\a');
			putchar('\a');
			putchar('\a');
			
			if(erros>5)
			{
				printf("FOMOS DERROTADO!\n");
				for(i=0; i<5; i++)
					putchar('\a');
				system("PAUSE");
				exit(0);
			}
		}
		
		naval(boats);
		printf("ALVOS ATINGIDOS: %3d | ERROS: %3d\n", acertos, erros);
	}
	
	system("PAUSE");
	return 0;
}

/*==================== DEVELOPMENT OF FUNCTIONS ====================*/
/*Function to draw the matrix*/
void naval(char b[][10])
{
	int i,j;
	putchar('\n');
	printf("     A   B   C   D   E   F   G   H   I   J   \n");
	printf("  -----------------------------------------\n");	
	for(i=0; i<8; i++)
	{
		printf("%d |", i+1);
		for(j=0; j<10; j++)
		{
			printf(" %c |", b[i][j]);
		}
		printf("\n  -----------------------------------------\n");
	}
	putchar('\n');
}

/*Function to generate randon numbers*/
void new_seed()
{
//	unsigned long capture;
	time_t capture;
	time(&capture);
	srand((unsigned)capture);
}            

/*Converte o caractere da coluna no inteiro para o índice da matriz*/      
unsigned map_col(char col) 
{
	switch(col)
	{
		case 'a':
    	case 'A': return 0;   
    	case 'b':
    	case 'B': return 1;    
	    case 'c':
	    case 'C': return 2; 
	    case 'd':
	    case 'D': return 3; 
	    case 'e':
	    case 'E': return 4; 
	    case 'f':
	    case 'F': return 5; 
	    case 'g':
	    case 'G': return 6; 
	    case 'h':
	    case 'H': return 7;  
	    case 'i':
	    case 'I': return 8; 
	    case 'j':
	    case 'J': return 9;          
    }    
} 
