#include<stdio.h>

/*
	Autor: Paulo Lima
	Data: 20/05/2022
	
	Calcular a m�dia final (usando a pondera��o da UFRN) dadas as notas das 3 provas e
	produzir uma sa�da com a m�dia e a situa��o do aluno de acordo com o seguinte crit�rio:
	m�dia >= 7, aprovado; 5 < m�dia < 7, recupera��o; m�dia < 5, reprovado.

*/


main(){
	float n1, n2, n3, media;
	int qtd_notas = 3;
	
	printf("Digite a nota 1: ");
	scanf("%f",&n1);
	printf("Digite a nota 2: ");
	scanf("%f",&n2);
	printf("Digite a nota 3: ");
	scanf("%f",&n3);
	
	media = (n1+n2+n3)/qtd_notas;
	
	if(media >=7){
		printf("\nAluno aprovado com media %.1f\n", media);
	} else if(media > 5 && media <7){
		printf("\nAluno na recuperacao com media %.1f\n", media);
	} else{
		printf("\nAluno reprovado com media %.1f", media);
	}
}
