#include<stdio.h>

/*
	Autor: Paulo Lima
	Data: 20/05/2022
	
	Para ler dois valores reais do teclado, calcular e imprimir na tela:
	
	a) A soma destes valores 
	b) O produto deles 
	c) O quociente entre eles
*/
main(){
	float num1, num2;
	
	printf("Digite o primeiro numero: ");
	scanf("%f",&num1);
	printf("Digite o segundo numero: ");
	scanf("%f",&num2);
	
	printf("\na) %.2f + %.2f = %.2f\n", num1, num2, num1+num2);
	printf("b) %.2f * %.2f = %.2f\n", num1, num2, num1*num2);
	printf("c) %.2f / %.2f = %.2f\n", num1, num2, num1/num2);
}
