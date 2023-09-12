/*Escreva um programa que permirta fazer uma jogada para um tipo de sena, indicando os n�meros a apostar, 
os quais dever�o ser criados aleatoriamente

Qtd de n�:     6   |   7   |   8   |   9    |   10   |    11    |    12    |    13    |     14    |    15     |
Valor em : R$ 3,50 | 24,50 | 98,00 | 294,00 | 735,00 | 1.617,00 | 3.234,00 | 6.006,00 | 10.510,50 | 17.517,50 |
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUMS 60
#define MIN_APOSTA 6             
#define MAX_APOSTA 15	
#define NUM_LIN 10          //Qtd de n�s apresentados por linha no volante		 

/*========================  PROTOTYPE OF FUNCTIONS  ========================*/
void inic_Randon();         //Inicia o gerador de n� aleat�rios com um n� que depende da hora que se executa a fun��o. 
void inic(int *v);          //Inicia com ZERO o vetor de controle dos n�s selecionados.
int ler_Ns_Apostar();       //L� a qtd de n�meros a apostar.
void gerar(int *v, int n);  //Gera n n�s aleat. e coloca na respectiva posi��o do vetor
void apresentar(int *res);  //Apresenta o formato do volante colocando XX nos n/s selecionados para a aposta

/*============================   MAIN FUNCTION   ==========================*/
main()
{
	int vetor[NUMS];
	int n_nums;
	
	inic_Randon();
	while(1)
	{
		inic(vetor);
		
		if( (n_nums = ler_Ns_Apostar() ) == 0)
			break;
		
		gerar(vetor, n_nums);   //Gerar n�s a apostar
		apresentar(vetor);
		putchar('\n');
	}	
	system("PAUSE");
	return 0;	
}

/*=======================  DEVELOPMENT OF FUNCTIONS  =======================*/

/*Inicia o gerador de n� aleat�rios com um n� que depende da hora que se executa a fun��o */
void inic_Randon()
{
	time_t ultime;
	time(&ultime);
	srand((unsigned) ultime);
}

/*Inicia com ZERO o vetor de controle dos n�s selecionados*/
void inic(int *v)
{
	int i;
	for(i=0; i<NUMS; i++)
		v[i] = 0;
}

/*L� a qtd de n�meros a apostar. Aceita valores entre MIN_APOSTA e MAX_APOSTA. 
Aceita o valor ZERO para indicar que se quer terminar o prog.*/
int ler_Ns_Apostar()
{
	int n;
	do{
		printf("Quantos n�s quer apostar ( 0 - Terminar ): ");
		scanf("%d",&n);
		
	}while((n<MIN_APOSTA || n>MAX_APOSTA) && n!=0);
	
	return n;
}

/*Gera n n�meros aleat�rios e coloca a respectiva posi��o do vetor com o valor 1 que indica que esse n� foi selecionado*/
void gerar(int *v, int n)
{
	int i, indice;
	for(i=1; i<=n; i++)
	{
		indice = rand()%NUMS;  //Devolve n� aleat�rio entre 0 e NUMS-1
		if(v[indice]==0)       //N�o foi selecionado
			v[indice] = 1;
		else                   //Este n� j� tinha sido selecionado, logo decrementa-se o contador para voltar a  
			i--;               //calcular mais uma vez o i-�ssimo n� aleat�rio.
	}
}

/*Apresenta o formato do volante colocando XX nos n/s selecionados para a aposta*/
void apresentar(int *res)
{
	int i;
	for(i=0; i<NUMS; i++)
	{
		if(res[i]==0)
			printf(" %2d", i+1);
		else
			printf(" XX");
			
		if((i+1)%NUM_LIN==0)
			putchar('\n');
	}	
}

