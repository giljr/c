/*
Project #04 (CSeries)

04_SINGLY_LINKED_LIST.C
-----------------------

Description:

This is a in portuguese, which gives me base for the Project #10
music album - simulation of a playlist in the console.

********************************************************************
Output:
1.Inserir no inicio da lista encadeada simples2.Inserir no fim da lista encadeada simples
3.Inserir no meio da lista encadeada simples
4.Remover da lista encadeada simples
5.Listar a lista encadeada simples
6.Sair
Digite sua escolha: 5

0 1 2 3 5 

********************************************************************

Author: https://github.com/borinvini/
Directory:(EstruturaDeDados_AP2/ListaSimples_NaoCirc/ListaSimples_NaoCirc/)

Edited By: J3
Date: Nov, 2021
*/
#include<stdio.h>							   
#include<stdlib.h>

int menu();
void InserirInicio(int num);
void InserirFim(int num);
void InserirMeio(int num, int posicao);
int Remover(int num);
void Listar();

struct ElementoDaLista_Simples {
	int dado;
	struct ElementoDaLista_Simples *prox;
} *Head;

int  main() {
	int op, num, pos, c, res;
	Head = NULL;

	while (1) {
		op = menu();
		switch (op) {
		case 1:
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} 
			InserirInicio(num);
			break;
		case 2:
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} 
			InserirFim(num);
			break;
		case 3:
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} 
			printf("Digite a posicao que deseja inserir: ");
			scanf_s("%d", &pos);
			while ((c = getchar()) != '\n' && c != EOF) {} 
			InserirMeio(num, pos);
			break;
		case 4:
			printf("Digite o numero a ser removido: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} 
			res = Remover(num);
			if (res == 1)
				printf("Numero removido.");
			else
				printf("Numero nao encontrado.");
			break;
		case 5:
			Listar();
			break;
		case 6:
			return 0;
		default:
			printf("Invalido\n");
		}
	}
	return 0;
}

int menu() {
	int op, c;
	system("Cls");

	printf("1.Inserir no inicio da lista encadeada simples\n");
	printf("2.Inserir no fim da lista encadeada simples\n");
	printf("3.Inserir no meio da lista encadeada simples\n");
	printf("4.Remover da lista encadeada simples\n");
	printf("5.Listar a lista encadeada simples\n");
	printf("6.Sair\n");
	printf("Digite sua escolha: ");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} 
	
	system("Cls");
	return op;
}

void InserirInicio(int num)
{
	struct ElementoDaLista_Simples *NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	NovoElemento->dado = num;

	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}

void InserirFim(int num)
{
	struct ElementoDaLista_Simples *NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	struct ElementoDaLista_Simples *ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));

	NovoElemento->dado = num;

	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		ElementoVarredura = Head;
		while (ElementoVarredura->prox != NULL)
			ElementoVarredura = ElementoVarredura->prox;

		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = NULL;
	}
}

void InserirMeio(int num, int posicao)
{
	struct ElementoDaLista_Simples *NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	struct ElementoDaLista_Simples *ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	struct ElementoDaLista_Simples *ElementoAuxiliar;
	ElementoAuxiliar = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));

	NovoElemento->dado = num;

	if (posicao == 0)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		ElementoVarredura = Head;
		for (int i = 0; i < posicao - 1; i++)
			ElementoVarredura = ElementoVarredura->prox;

		ElementoAuxiliar = ElementoVarredura->prox;
		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = ElementoAuxiliar;
	}
}

int Remover(int num)
{
	struct ElementoDaLista_Simples *ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	struct ElementoDaLista_Simples *Anterior;
	Anterior = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;
	while (ElementoVarredura != NULL) {
		if (ElementoVarredura->dado == num) {
			if (ElementoVarredura == Head) {
				Head = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
			else {
				Anterior->prox = ElementoVarredura->prox ;
				free(ElementoVarredura);
				return 1;
			}
		}
		else {
			Anterior = ElementoVarredura;
			ElementoVarredura = ElementoVarredura->prox;
		}
	}
	return 0;
}

void Listar()
{
	struct ElementoDaLista_Simples *ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;
	if (ElementoVarredura == NULL) {
		return;
	}
	while (ElementoVarredura != NULL) {
		printf("%d ", ElementoVarredura->dado);
		ElementoVarredura = ElementoVarredura->prox;
	}
	printf("\n");

	system("pause");
	return;
}