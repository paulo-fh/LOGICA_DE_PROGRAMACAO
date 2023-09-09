#include<stdio.h>

/*
	Autor: Paulo Lima
	Data: 20/05/2022
	
	Ler dois números inteiros, x e y, e imprimir o quociente e o resto da divisão inteira entre
	eles.
*/

main(){
	int n1, n2;
	
	printf("Digite um numero inteiro: ");
	scanf("%d",&n1);
	printf("Digite outro numero inteiro: ");
	scanf("%d",&n2);
	
	printf("Quociente = %d\n", n1 / n2);
	printf("Resto = %d\n", n1 % n2);	
}
