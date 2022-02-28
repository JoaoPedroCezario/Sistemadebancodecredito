#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void cash(void);

FILE *arquivo;
int deseja, busca;
float caixa, temp;

struct ag
{
	char cod[6], prop[20];
	float imposto;
};

struct ag sistema;

int main()
{
	int decorar, principal;
	
	arquivo = fopen("sistema.txt","a+");
	fclose(arquivo);
	
	system ("color e1");
	
	do{
	
	system ("cls");
	
	for (decorar=0;decorar<80;decorar++)
	{
		printf ("%c", 174);
	}
	
	printf ("\nBanco S.A. - Compilacao 1.3.0- 2017\n");
	printf ("\n[1] - Deposito/Saque\n[2] - Nova Conta\n[3] - Saldo\n[0] - Sair\n\n");
	cin>>deseja;
	system ("cls");
	
	if (deseja == 0)
	{
		return 0;
	}
	
	if (deseja == 1)
	{
		printf ("\nDEPOSITO/SAQUE\n\n");
		arquivo = fopen("sistema.txt","r+");
		printf ("Digite o Numero Da Conta: ");
		cin>>busca;
		busca=busca-1;
		
		fseek(arquivo,busca*sizeof(struct ag),SEEK_SET);
		fread(&sistema, sizeof(struct ag), 1, arquivo);
		
		cout<<"\n\nConta N:........."<<sistema.cod;
		cout<<"\nCorrentista:......."<<sistema.prop;
		cout<<"\nValor Na Conta:...."<<sistema.imposto;
		printf ("\n\n");
		caixa = sistema.imposto;
		fclose(arquivo);
		
		deseja = 1;
		
		cash();
	}
	
	if (deseja == 2)
	{
		printf ("\nNOVA CONTA\n\n");
		arquivo = fopen("sistema.txt","a+");
		
		printf ("Digite o Numero Da Conta: ");
		cin>>sistema.cod;
		printf ("\nDigite o Nome: ");
		cin>>sistema.prop;
		printf ("\nDigite o Valor Inicial: ");
		cin>>sistema.imposto;
		
		fwrite(&sistema, sizeof(struct ag), 1, arquivo);
		fclose(arquivo);
		
		arquivo = fopen("extrato %s", sistema.cod, "a+");
		fclose(arquivo);
	}
	
	if (deseja == 3)
	{
		arquivo = fopen("sistema.txt","r+");
		printf ("Digite o Codigo: ");
		cin>>busca;
		busca=busca-1;
		
		fseek(arquivo,busca*sizeof(struct ag),SEEK_SET);
		fread(&sistema, sizeof(struct ag), 1, arquivo);
		
		cout<<"\n\nConta:............"<<sistema.cod;
		cout<<"\nCorrentista:......."<<sistema.prop;
		cout<<"\nValor Na Conta:...."<<sistema.imposto;
		printf ("\n\n");
		
		fclose(arquivo);
		system ("pause");
	}
	
	}while (1 == 1);
}

void cash(void)
{
	printf ("\n\nDigite o Valor a Ser Retirado/Depositado: ");
	cin>>temp;
	
	caixa = caixa + temp;
	
	sistema.imposto = caixa;
	
	arquivo = fopen("sistema.txt","r+");
	fseek(arquivo,busca*sizeof(struct ag),SEEK_SET);
	fwrite(&sistema, sizeof(struct ag), 1, arquivo);
	
	printf ("\n\nGravado Com Sucesso!!!\n\n");
	system("pause");
	fclose(arquivo);
	return;
}
