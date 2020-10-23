#include <stdio.h>
#include <stdlib.h>

//// Estruturas de Dados ////
typedef struct objeto
{
	float valor;
	float peso;
	float VpP; // Valor/Peso
	int visitado;
} Objeto;

#define nObj 7
Objeto objPadroes[nObj] = {{10, 2, 5, -1}, {5, 3, 5.0/3.0, -1}, {15, 5, 3, -1}, {7, 7, 1, -1}, {6, 1, 6, -1}, {18, 4, 9.0/2.0, -1}, {3, 1, 3, -1}};


//// Declarações das Funções ////
void display();
void start_padrao();
void start_personalizado();
void sair();
void greed(int limite, Objeto *obj);
void greed1(int limite, Objeto *obj, int lenght);
void print(Objeto *obj, int lenght, int limite);

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
	
	printf("\nConcluído!\n");

	return 0;
}

//// Corpo das Funções ////
void display()
{
	system("clear");
	printf("##################################\n");
	printf("#            Knapsack            #\n");
	printf("#            Problem             #\n");
	printf("##################################\n");
	printf("#                                #\n");
	printf("# (1) Iniciar com objetos padrão #\n");
	printf("# (2) Definir objetos            #\n");
	printf("# (3) Sair                       #\n");
	printf("#                                #\n");
	printf("##################################\n");

	printf("\n>>> ");
}

void start_padrao()
{
	system("clear");
	printf("## Padrão ##\n\n");
	printf("Por padrão, temos 7 objetos com os seguintes atributos:\n\n");

	for(int i = 0; i < nObj; i++)
	{
		printf("[%d] - Valor: R$ %.2f\n", i, objPadroes[i].valor);
		printf("    - Peso: %.2f Kg\n", objPadroes[i].peso);
		printf("---------------------------\n");
	}

	printf("\nAperte enter para resolver o problema utilizando um algoritmo ambicioso...\n");
	getchar();
	getchar();
	greed(15, objPadroes);

	print(objPadroes, nObj, 15);

}

void start_personalizado()
{
	system("clear");
	printf("## Personalizado ##\n");
	printf("Número de Objetos desejados: ");
	int size;
	scanf("%d", &size);

	Objeto *objPersonalizados = malloc(size * sizeof(Objeto));

	printf("\n\nPreencha os atributos dos %d objetos: (Valor Peso):\n", size);
	for(int i = 0; i < size; i++)
	{
		printf("\n[%d]\n", i);
		scanf("%f %f", &(objPersonalizados+i)->valor, &(objPersonalizados+i)->peso);
		(objPersonalizados+i)->VpP = (objPersonalizados+i)->valor / (objPersonalizados+i)->peso;
		(objPersonalizados+i)->visitado = -1;
	}

	printf("\nDefina o peso limite, em Kg: ");
	float limite;
	scanf("%f", &limite);

	printf("\nPreenchimento de dados concluído.\nAperte enter para resolver o problema utilizando um algoritmo ambicioso...\n");

	getchar();
	getchar();
	greed1(limite, objPersonalizados, size);

	float lucro = 0;
	float peso = 0;
	printf("Os elementos que devem ser escolhidos para ter o maior valor, respeitando o limite de peso de %.2f Kg, são:\n\n", limite);
	for(int i = 0; i < size; i++)
	{
		if((objPersonalizados+i)->visitado == 1)
		{
			printf("%d Objeto de %.2f Kg (%.2f reais)\n", (objPersonalizados+i)->visitado, (objPersonalizados+i)->peso, (objPersonalizados+i)->valor);
			lucro += (objPersonalizados+i)->valor;
			peso += (objPersonalizados+i)->peso;
		}		
	}
	printf("\nTotalizando %.2f reais e %.2f Kg\n", lucro, peso);
}


void sair()
{
	printf("\nSaindo...\n");
	exit(EXIT_SUCCESS);
}

void greed(int limite, Objeto *obj)
{
	int lim = limite;
	int max = 0, indiceMax = -1;

	for (int i = 0; i < nObj-1; i++)          
	   	for (int j = 0; j < nObj-i-1; j++)
	       	if (obj[j].VpP > obj[j+1].VpP) {
	          	Objeto tmp = obj[j];
	          	obj[j] = obj[j+1];
	          	obj[j+1] = tmp;
	       	}

	for(int i = nObj-1; i > 0; i--)
	{
		if(lim - obj[i].peso >= 0) {
			obj[i].visitado = 1;
			lim -= obj[i].peso;
		}	
	}
}

void greed1(int limite, Objeto *obj, int lenght)
{
	int lim = limite;
	int max = 0, indiceMax = -1;

	for (int i = 0; i < lenght-1; i++)          
	   	for (int j = 0; j < lenght-i-1; j++)
	       	if ((obj+j)->VpP > (obj+j+1)->VpP) {
	          	Objeto tmp = obj[j];
	          	obj[j] = obj[j+1];
	          	obj[j+1] = tmp;
	       	}

	for(int i = lenght-1; i > 0; i--)
	{
		if(lim - (obj+i)->peso >= 0) {
			(obj+i)->visitado = 1;
			lim -= (obj+i)->peso;
		}	
	}
}

void print(Objeto *obj, int lenght, int limite)
{
	float lucro = 0;
	float peso = 0;
	printf("Os elementos que devem ser escolhidos para ter o maior valor, respeitando o limite de peso de %d Kg, são:\n\n", limite);
	for(int i = 0; i < lenght; i++)
	{
		if(obj[i].visitado == 1)
		{
			printf("%d Objeto de %.2f Kg (%.2f reais)\n", obj[i].visitado, obj[i].peso, obj[i].valor);
			lucro += obj[i].valor;
			peso += obj[i].peso;
		}		
	}
	printf("\nTotalizando %.2f reais e %.2f Kg\n", lucro, peso);
}
