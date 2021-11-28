/*
Project #11 (CSeries)
11_HASH_V0.C
------------------
Description:

This is a HashTable which implements a hash function.
A hash function turns a key into a random-looking number, 
and it must always return the same number given the same key.

A hash function turns a key into a random-looking number, 
and it must always return the same number given the same key.

Look at the output to know more ;)

*************************************************
OUTPUT:

1. Insert in Hash2. Remove from Hash
3. Search the Hash
4. Show the Hash
5. Exit
Choose the operation: 1

Type the number: 100
Inserting in position 0 of Table...
Pressione qualquer tecla para continuar. . .

Choose the operation: 1

Type the number: 110
Inserting in position 0 of Table...

1. Insert in Hash2. Remove from Hash
3. Search the Hash
4. Show the Hash
5. Exit
Choose the operation: 4

List of keys by position 0:
 110 -> 100 -> 

 List of keys by position 1:
 

 List of keys by position 2:
 

 List of keys by position 3:
 

 List of keys by position 4:
 

 List of keys by position 5:


 List of keys by position 6:


 List of keys by position 7:


 List of keys by position 8:


 List of keys by position 9:

Pressione qualquer tecla para continuar. . . 
*************************************************
UNINTER - ESCOLA SUPERIOR POLITÉCNICA
Graduation: Computer Engineering

Please visit my website for more info: 
https://medium.com/jungletronics/hash-tables-in-c-5293c2bf6061

Edited By: J3
Date: Nov, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VECTORSIZE 10

//Typedef definition
typedef struct HashList
{
	int key;
	struct HashList *prox;
} HashList_t;

typedef struct Table
{
	int Size;
	HashList_t **ListKey;
} Table_t;

//Prototypes
int menu();
int HashingFunction(int);
void InsertHash(Table_t *, int, int);
void ShowHash(Table_t *);
void RemoveHash(Table_t *, int, int);
void SearchHash(Table_t *, int, int);

int main()
{
	int op, c, num, pos;
	Table_t *TableHash = (Table_t *)malloc(sizeof(Table_t));
	TableHash->Size = VECTORSIZE;
	TableHash->ListKey = (HashList_t **)malloc(VECTORSIZE * sizeof(HashList_t *));

	for (int i = 0; i < VECTORSIZE; i++)
		TableHash->ListKey[i] = NULL;

	while (1)
	{
		op = menu();
		switch (op)
		{
		case 1: //insert
			printf("Type the number: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF)
			{
			}
			pos = HashingFunction(num);
			printf("Inserting in position %d of Table...\n", pos);
			system("pause");
			InsertHash(TableHash, num, pos);
			break;
		case 2: //remove
			printf("Type the number to remove: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF)
			{
			}
			pos = HashingFunction(num);
			printf("Removing from position %d of Table...\n", pos);
			printf("WARNING: The System returns if nothing is found, ok? \n");
			system("pause");
			RemoveHash(TableHash, num, pos);
			break;
		case 3: //search
			printf("Type the number to search: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF)
			{
			}
			pos = HashingFunction(num);
			printf("Searching for number %i ...\n", num);
			printf("WARNING: The System returns if nothing is found, ok? \n");
			system("pause");
			SearchHash(TableHash, num, pos);
			system("pause");
			break;
		case 4: //show
			ShowHash(TableHash);
			system("pause");
			break;
		case 5:
			return 0;
			break;
		default:
			printf("Invalid\n");
			break;
		}
	}
	return 0;
}

int menu()
{
	int op, c;
	system("Cls");

	printf("1. Insert in Hash\n");
	printf("2. Remove from Hash\n");
	printf("3. Search the Hash\n");
	printf("4. Show the Hash\n");
	printf("5. Exit\n");
	printf("Choose the operation: ");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF)
	{
	}

	system("Cls");
	return op;
}

int HashingFunction(int num)
{
	return (num % VECTORSIZE);
}

void InsertHash(Table_t *TableHash, int num, int pos)
{
	HashList_t *NewItem;
	NewItem = (HashList_t *)malloc(sizeof(HashList_t));
	NewItem->key = num;
	NewItem->prox = NULL;

	NewItem->prox = TableHash->ListKey[pos];
	TableHash->ListKey[pos] = NewItem;
}

void SearchHash(Table_t *TableHash, int num, int pos)
{
	HashList_t *ScanItem;
	ScanItem = (HashList_t *)malloc(sizeof(TableHash));
	ScanItem = TableHash->ListKey[pos];

	HashList_t *Auxiliar;
	Auxiliar = (HashList_t *)malloc(sizeof(HashList_t));

	if (TableHash->ListKey[pos]->key == num)
	{
		TableHash->ListKey[pos] = TableHash->ListKey[pos]->prox;
		printf("YES, The number %d was found in table!\n", num);
	}
	else
	{
		while (ScanItem->key != num)
		{
			Auxiliar = ScanItem;
			ScanItem = ScanItem->prox;
		}
		Auxiliar->prox = ScanItem->prox;
		printf("YES, The number %d was found in table!\n", num);
	}
}

void RemoveHash(Table_t *TableHash, int num, int pos)
{
	HashList_t *ScanItem;
	ScanItem = (HashList_t *)malloc(sizeof(TableHash));
	ScanItem = TableHash->ListKey[pos];

	HashList_t *Auxiliar;
	Auxiliar = (HashList_t *)malloc(sizeof(HashList_t));

	if (TableHash->ListKey[pos]->key == num)
	{
		TableHash->ListKey[pos] = TableHash->ListKey[pos]->prox;
		free(ScanItem);
	}
	else
	{
		while (ScanItem->key != num)
		{
			Auxiliar = ScanItem;
			ScanItem = ScanItem->prox;
		}
		Auxiliar->prox = ScanItem->prox;
		free(ScanItem);
	}
}

void ShowHash(Table_t *TableHash)
{
	int v;
	for (v = 0; v < TableHash->Size; v++)
	{
		HashList_t *ScanItem = TableHash->ListKey[v];
		printf("\n List of keys by position %d:\n ", v);
		while (ScanItem != NULL)
		{
			printf("%d -> ", ScanItem->key);
			ScanItem = ScanItem->prox;
		}
		printf("\n");
	}
}