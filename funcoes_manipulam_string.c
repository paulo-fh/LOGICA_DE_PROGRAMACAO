/*FUNÇÕES DE MANIPULAÇÃO DE STRINGS*/

#include <stdio.h>

/*=========================   PROTOTYPE OF FUNCTIONS   =========================*/
int my_strlen(char *s);                   /* Devolve o n° de caracteres na string (sem contar o '\0) */
int isnull(char *s);					  /*Verifica se uma string contém ou não algum caractere, devolvendo o valor lógico correspondente*/
char *my_strcpy(char *dest, char *orig);  /*Copia a string orig para a string dest*/
char *my_strcat(char *dest, char *orig);  /*Coloca a string orig imediatamente depois da string dest*/
int my_strcountc(char *s, char ch);       /*Devolve o n° de ocorrências do caractere ch na string s */
int my_strcountd(char *s);				  /*Devolve o número de dígitos da string*/
int my_isdigit(char c);                   /*Verifica se o caractere é um digito (0..9)*/
int indchr(char *s, char ch);             /*Devolve o índice da primeira ocorrência do caractere ch na string*/
int my_strpal(char *s);                   /*Verifica se a string é um palindromo, isto é, se é lida da mesma forma da esquerda para a direita 
                                            e da direita para a esquerda*/
char *my_strrev(char *s);				  /*Inverte a string e devolve-a invertida*/
int my_strcmp(char *s1, char *s2);        /*Compara a string s1 e s2 alfabeticamente*/
char *my_strpad(char *s);                 /*Coloca um espaço em branco após cada um dos caracteres da string s*/
char *my_strdelc(char *s, char ch);        /*Apaga todas as ocorrências do caractere ch na string s*/
                                            

/*=========================        MAIN FUNCTION       =========================*/
main()
{
	char str[]  = "Hello";
	char str1[] = "";
	char str3[] = "WR Kits";
	char str4[] = "Paulo";
	char str5[] = " Lima";
	char str6[] = "Engenharia da computacao";
	char str7[] = "15(quinze) abacates";
	char str8[] = "Engenharia da computacao";
	char str9[] = "assa";
	char str10[] = "marmotao";
	char str11[] = "Mario";
	char str12[] = "Maria";
	char str13[] = "Ola";
	char str14[] = "Engenharia da computacao";
	
	printf("Length: %d\n\n", my_strlen(str));
	printf("is null? %d\n\n", isnull(str1));        //imprime UM se for nulo
	
	printf("Antes de strcpy: %s\n",str3);
	my_strcpy(str3,"Luis Damas");
	printf("Depois de strcpy: %s\n\n",str3);
	printf("strcat: %s\n\n",my_strcat(str4,str5));
	printf("strcountc: %d\n\n", my_strcountc(str6,'e'));
	printf("strcountd: %d\n\n", my_strcountd(str7));
	printf("indchr: %d\n\n", indchr(str8,'w'));
	printf("my_strpal: %d\n\n", my_strpal(str9));
	printf("my_strrev: %s\n\n", my_strrev(str10));
	printf("my_strcmp: %d\n\n", my_strcmp(str11,str12));
	printf("my_strpad: %s\n\n", my_strpad(str13));
	printf("my_strdelc: %s\n\n", my_strdelc(str14,'h'));
	
	
	system("PAUSE");          /*Pausa a execução (Pressione qualquer tecla para continuar)*/
}


/*=========================  DEVELOPMENT OF FUNCTIONS  =========================*/

/* Devolve o n° de caracteres na string (sem contar o '\0) */
int my_strlen(char *s)
{
	int i=0;

	while(s[i]!='\0')
		i++;
	return i;
}

/*Verifica se uma string contém ou não algum caractere, devolvendo o valor lógico correspondente*/
int isnull(char *s)
{
	return (s[0] == '\0');
}

/*Copia a string orig para a string dest*/
char *my_strcpy(char *dest, char *orig)
{
	int i;
	for(i=0; orig[i]!='\0'; i++)
		dest[i] = orig[i];
		
	dest[i] = '\0';
	
	return dest;
}

/*Coloca a string orig imediatamente depois da string dest*/
char *my_strcat(char *dest, char *orig)
{
	int i, len;
	for(i=0, len=my_strlen(dest); orig[i]!='\0'; i++, len++)
	{
		dest[len] = orig[i];
	}
	dest[len]='\0';
	return dest;
}

/*Devolve o número de ocorrências do caractere ch na string s */
int my_strcountc(char *s, char ch)
{
	int i, conta;
	for(i=0, conta=0; s[i]!='\0'; i++)
		if(s[i] == ch)
			conta++;

	return conta;
}

/*Devolve o número de dígitos da string*/
int my_strcountd(char *s)
{
	int i, dig;
	for(i=dig=0; s[i]!='\0'; i++)
	{
		if(my_isdigit(s[i]))
			dig++;
	}
	return dig;
}

/*Verifica se o caractere é um digito (0..9)*/
int my_isdigit(char c)
{
	return (c>='0' && c<='9');
}

/*Devolve o índice da primeira ocorrência do caractere ch na string*/
int indchr(char *s, char ch)
{
	int i;
	for(i=0; s[i]!='\n'; i++)
		if(s[i]==ch)
			return i;
	
	return -1;
}

/*Verifica se a string é um palindromo, isto é, se é lida da mesma forma da esquerda para a direita e da direita para a esquerda*/
int my_strpal(char *s)
{
	int i, len;
	for(i=0, len=my_strlen(s)-1; i<len; i++, len--)
		if(s[i]!=s[len])
			return 0;
	return 1;
}

/*Inverte a string e devolve-a invertida*/
char *my_strrev(char *s)
{
	int i, len;
	char tmp;
	for(i=0, len=my_strlen(s)-1; i<len ; i++, len--)
	{
		tmp  = s[i];
		s[i] = s[len];
		s[len] = tmp;
	}
	return s;		
}

/*Compara a string s1 e s2 alfabeticamente*/
int my_strcmp(char *s1, char *s2)
{
	int i=0;
	while(s1[i]==s2[i] && s1[i]!='\0')
		i++;
	
	return s1[i] - s2[i];
}

/*Coloca um espaço em branco após cada um dos caracteres da string s*/
char *my_strpad(char *s)
{
	int i=my_strlen(s);
	
	s[2*i] = s[i];    /*coloca o delimitador na nova posição*/
	for(i--; i>=0; i--)
	{
		s[2*i] = s[i];
		s[2*i+1] = ' ';
	}				
	return s;
}

/*Apaga todas as ocorrências do caractere ch na string s*/
char *my_strdelc(char *s, char ch)
{
	int i, j;
	for(i=j=0; s[i]!='\0'; i++)
		if(s[i] != ch)
			s[j++] = s[i];
	s[j]='\0';
	return s;
}

