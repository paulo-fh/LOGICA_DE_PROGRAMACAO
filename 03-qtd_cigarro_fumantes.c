#include<stdio.h>

/*
	Autor: Paulo Lima
	Data: 20/05/2022
	
	Calcular a quantidade dinheiro gasta por um fumante. Dados: o número de anos que ele
	fuma, o nº de cigarros fumados por dia e o preço de uma carteira.	
*/


main(){
	int tempo_Anos, qtd_ciga, dias, total_cart, qtd_carteira = 20;
	float preco_Cart_Ciga, valor_unid_cigar, valor_gasto;
	
	printf("Informe ha quantos anos eh fumante: ");
	scanf("%d",&tempo_Anos);
	printf("Quantos cigarros fuma por dia: ");
	scanf("%d",&qtd_ciga);
	printf("Informe o preco de uma carteira de cigarros: ");
	scanf("%f",&preco_Cart_Ciga);
	
	//converte ano(s) em dia(s)
	dias = tempo_Anos * 365;
	valor_unid_cigar = preco_Cart_Ciga / qtd_carteira;
	
	
	valor_gasto = dias * qtd_ciga * valor_unid_cigar;
	
	printf("\nValor gasto com cigarro: %.2f\n", valor_gasto);
}
