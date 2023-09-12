/*
Desenvolva o projeto de um interpretador para as seguintes instruções:

RUN - Rodar o interpretador
RUN SOUND - Rodar o interpretador com "bips"
REP - Define o número de repetições de uma frase salva previamente com o comando TXT. 
recebe como argumento o número de repetições desejadas
TXT - Comando para entrada de nova frase. O argumento é a frase-texto que o usuário quiser que 
o interpretador rode pelo número de repetições definido.
CLEAR - limpa a tela do console.
CLEAR ALL - Limpa a tela e restaura variáveis.
EXIT - encerra o interpretador.
HELP - Apresenta a versão atual do interpretador e a breve explicação sobre 
*/
#include<stdio.h>

int my_strcmp(char *s1, char *s2);

void help();
void rep(int x);
char *run(char *txt, int n);
char *run_sound(char *txt, int n);
void clear_all(char *s);

main()
{
	char opt[15], txt[20] = "    - - - -";
	int rep=1, i;
	
	while(1)
	{
		printf("Input command: ");
		gets(opt);
		
		
		if(!my_strcmp(opt,"HELP"))
			help();
		else
			if(!my_strcmp(opt,"CLEAR"))
				system("cls");
			else
				if(!my_strcmp(opt,"REP"))
				{
					printf("\t       _");
					scanf("%d",&rep);
				}
				else
					if(!my_strcmp(opt,"TXT"))
					{
						printf("\t       _");
						gets(txt);
					}
					else
						if(!my_strcmp(opt,"RUN"))
						{
							run(txt,rep);
						}
						else
							if(!my_strcmp(opt,"RUN SOUND"))
							{
								run_sound(txt,rep);
							}
							else
								if(!my_strcmp(opt,"CLEAR ALL"))
								{
									system("cls");
									clear_all(txt);
									rep = 1;									
								}
								
								
									
	
		fflush(stdin);
			
	}
	
	system("PAUSE");
	return 0;
}

void help()
{
	puts("\tSIMPLE INTERPRETER W1.0\n");
	puts("\tCOMMANDS:");
	puts("\tRUN\t\t run the interpreter");
    puts("\tRUN SOUND\t run the program with \"bips\"");
    puts("\tREP\t\t repeats number, arg: 000 to 999");
    puts("\tTXT\t\t update text, arg: any text you want");
    puts("\tCLEAR\t\t clear screen without lost the data");
    puts("\tCLEAR ALL\t clear screen end erase data");
    puts("\tEXIT\t\t end interpreter\n");
    
    puts("\tPaulo Lima, 2023");
}

char *run(char *txt, int n)
{
	int i;
	for(i=0;  i<n; i++)
		printf("\t   %s\n",txt);
		
	return txt;
}

char *run_sound(char *txt, int n)
{
	int i;
	for(i=0;  i<n; i++)
		printf("\t   %s\a\n",txt);
		
	return txt;
}

void clear_all(char *s)
{
	int i;
	for(i=0; s[i]!='0' && i<4; i++)
	{
		s[i] = '-';
	}
}

int my_strcmp(char *s1, char *s2)
{
	int i=0;
	while(s1[i]==s2[i] && s1[i]!='\0')
		i++;
	
	return((unsigned char)s1[i] - (unsigned char)s2[i]);
 } 
