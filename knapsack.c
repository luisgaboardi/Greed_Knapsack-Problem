#include <stdio.h>
#include <stdlib.h>

//// Estruturas de Dados ////
typedef struct objeto
{
	float valor;
	float peso;
} Objeto;

//// Declarações das Funções ////
void display();
void start_padrao();
void start_personalizado();
void sair();

//// Main ////
int main(int argc, char const *argv[])
{
	display();
	int menu_option;
	scanf("%d", &menu_option);

	switch(menu_option)
	{
		case 1:
			start_padrao();
			break;
		case 2:
			start_personalizado();
			break;
		case 3:
			sair();
			break;
	}
	
	return 0;
}

//// Corpo das Funções ////
void display()
{
	system("clear");
	printf("\n##################################\n");
	printf(  "#            Knapsack            #\n");
	printf(  "#            Problem             #\n");
	printf(  "##################################\n");
	printf(  "#                                #\n");
	printf(  "# (1) Iniciar com objetos padrão #\n");
	printf(  "# (2) Definir objetos            #\n");
	printf(  "# (3) Sair                       #\n");
	printf(  "#                                #\n");
	printf(  "##################################\n");

	printf("\n>>> ");
}

void start_padrao()
{
	system("clear");
	printf("Padrão\n");
}

void start_personalizado()
{
	system("clear");
	printf("Personalizado\n");
}


void sair()
{
	printf("\nSaindo...\n");
	exit(EXIT_SUCCESS);
}
