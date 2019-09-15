//Luciano Lopes de Sousa
//Bernardo Garcia Ferreira Junior

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contato 
{
	char nome[26];
	int numero;
};
void AdicionarContato(struct contato *agenda, int p);
void MostrarContatos(struct contato *agenda, int p);
void RemoverContato(struct contato *agenda, int p);
void ProcurarContato(struct contato *agenda, int p);

int main()
{
	int  p = 0;
	char opcao;

	struct contato *agenda[100]; 

	do
	{
		printf("---------------AGENDA------------------\n");
		printf("---------------------------------------\n");
		printf("NUMERO DE CONTATOS CADASTRADOS: %d\n", p);
		printf("---------------------------------------\n");
		printf("OPCOES:\n");
		printf("1 - ADICIONAR CONTATO\n");
		printf("2 - MOSTRAR CONTATOS\n");
		printf("3 - REMOVER CONTATO\n");
		printf("4 - BUSCAR CONTATO\n");
		printf("5 - SAIR\n");
		printf("Escolha uma opcao!\n");
		printf("---->");
		scanf(" %c", &opcao);

		switch(opcao) 
		{
		case '1':
			AdicionarContato(agenda, p);
			p += 1;
			system("cls"); 
			break;
		case '2':
			system("cls");
			MostrarContatos(agenda, p);
			break;
			system("cls");
		case '3':
			system("cls");
			MostrarContatos(agenda, p);
			RemoverContato(agenda, p);
			p -= 1;
			system("cls");
			break;
		case '4':
			system("cls");
			ProcurarContato(agenda, p);
			break;
		case '5':
			system("cls");
			printf("\n\t\t\tFinalizando programa!!!\n");
			exit(0);
			break;
		default:
			system("cls");
			printf("Opcao invalida!!\n\n");
			break;
		}
	}
	while(opcao != '5'); 

	return 0;
}

void AdicionarContato(struct contato *agenda, int p)
{
	printf("Nome: ");
	scanf(" %[^\n]", agenda[p].nome);
	printf("Numero: ");
	scanf("%d", &agenda[p].numero);
}

void MostrarContatos(struct contato *agenda, int p)
{
	int i;

	for(i = 0; i < p; i++)
	{
		printf("--------------------------------");
		printf("\n\nCONTATO N %d\n", i);
		printf("Nome: %s\n", agenda[i].nome);
		printf("Numero: %d\n\n\n", agenda[i].numero);
	}
}

void RemoverContato(struct contato *agenda, int p)
{
	int posicao, i;

	printf("Numeracao do contato para remover: ");
	scanf("%d", &posicao);

	if(posicao < p)
	{
		for(i = 0; i < p - posicao; i++)
		{
			agenda[posicao + i] = agenda[posicao + 1 + i];
		}                                                
	}
}
void ProcurarContato(struct contato *agenda, int p) 
{
	int i, resultado, index;
	char vet[30];

	printf("Digite o nome do contato: ");
	scanf("%s", &vet);

	for(i = 0; i < p; i++)
	{
		resultado = strcmp(strlwr(vet), strlwr(agenda[i].nome)); 
		                                
		if(resultado == 0)
		{
			index = i;
			printf("Nome: %s\n", agenda[index].nome);
			printf("Numero: %d\n\n", agenda[index].numero);
			break;
		}
	}
}
