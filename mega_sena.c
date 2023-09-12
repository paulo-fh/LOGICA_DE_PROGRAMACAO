/*Escreva um programa que permirta fazer uma jogada para um tipo de sena, indicando os números a apostar, 
os quais deverão ser criados aleatoriamente

Qtd de n°:     6   |   7   |   8   |   9    |   10   |    11    |    12    |    13    |     14    |    15     |
Valor em : R$ 3,50 | 24,50 | 98,00 | 294,00 | 735,00 | 1.617,00 | 3.234,00 | 6.006,00 | 10.510,50 | 17.517,50 |
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUMS 60
#define MIN_APOSTA 6             
#define MAX_APOSTA 15	
#define NUM_LIN 10          //Qtd de n°s apresentados por linha no volante		 

/*========================  PROTOTYPE OF FUNCTIONS  ========================*/
void inic_Randon();         //Inicia o gerador de n° aleatórios com um n° que depende da hora que se executa a função. 
void inic(int *v);          //Inicia com ZERO o vetor de controle dos n°s selecionados.
int ler_Ns_Apostar();       //Lê a qtd de números a apostar.
void gerar(int *v, int n);  //Gera n n°s aleat. e coloca na respectiva posição do vetor
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
		
		gerar(vetor, n_nums);   //Gerar n°s a apostar
		apresentar(vetor);
		putchar('\n');
	}	
	system("PAUSE");
	return 0;	
}

/*=======================  DEVELOPMENT OF FUNCTIONS  =======================*/

/*Inicia o gerador de n° aleatórios com um n° que depende da hora que se executa a função */
void inic_Randon()
{
	time_t ultime;
	time(&ultime);
	srand((unsigned) ultime);
}

/*Inicia com ZERO o vetor de controle dos n°s selecionados*/
void inic(int *v)
{
	int i;
	for(i=0; i<NUMS; i++)
		v[i] = 0;
}

/*Lê a qtd de números a apostar. Aceita valores entre MIN_APOSTA e MAX_APOSTA. 
Aceita o valor ZERO para indicar que se quer terminar o prog.*/
int ler_Ns_Apostar()
{
	int n;
	do{
		printf("Quantos n°s quer apostar ( 0 - Terminar ): ");
		scanf("%d",&n);
		
	}while((n<MIN_APOSTA || n>MAX_APOSTA) && n!=0);
	
	return n;
}

/*Gera n números aleatórios e coloca a respectiva posição do vetor com o valor 1 que indica que esse n° foi selecionado*/
void gerar(int *v, int n)
{
	int i, indice;
	for(i=1; i<=n; i++)
	{
		indice = rand()%NUMS;  //Devolve n° aleatório entre 0 e NUMS-1
		if(v[indice]==0)       //Não foi selecionado
			v[indice] = 1;
		else                   //Este n° já tinha sido selecionado, logo decrementa-se o contador para voltar a  
			i--;               //calcular mais uma vez o i-éssimo n° aleatório.
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

