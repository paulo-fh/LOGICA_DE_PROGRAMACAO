#include<stdio.h>

/*
	Autor: Paulo Lima
	Data: 20/05/2022
	
	Para ler 3 números reais do teclado e verificar se o primeiro é maior que a soma dos
	outros dois.
*/
main(){
	float num1, num2, num3;
	
	printf("Digite o primeiro numero: ");
	scanf("%f",&num1);
	printf("Digite o segundo numero: ");
	scanf("%f",&num2);
	printf("Digite o terceiro numero: ");
	scanf("%f",&num3);
	
	if(num1 > num2+num3){
		printf("O primeiro numero eh maior que a soma dos outros dois numeros.");
	}else{
		printf("O primeiro numero eh menor que a soma dos outros dois numeros.");
	}
}
