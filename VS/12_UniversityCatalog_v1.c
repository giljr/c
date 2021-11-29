/*
Project #12 (CSeries)
11_UNIVERSITYCATALOG_V1.C
------------------

Description:

This is a HashTable which implements a hash function.
A hash function turns a key into a random-looking number, 
and it must always return the same number given the same key.

A hash function turns a key into a random-looking number, 
and it must always return the same number given the same key.

Look at the output to know more ;)

Requerements:

Exercise 2:

Make an algorithm in C language that performs the search for a UNINTER student in AVA. 
The search must be performed using a very efficient data structure
for this search task. Among the structures that can be used are: tree binary or hash.

1. You must store the student's name, e-mail address and RU. 
   To storage uses a heterogeneous data structure.

2. It is not necessary to read the data from the student data
   manually. You can now pre-register the data in your code.
   Register at least 10 student contacts in your data structure.
   One of the contacts must be your own name and your UNINTER RU;

3. In an on-screen menu, ask the user to enter an RU. The program should
   perform the search for this RU in the data structure and, if it finds the RU,
   must show the corresponding name of the student and the email of this contact.
   If not, an error message should be displayed.

4. To test the program, test the search with your RU and put in the capture of screen.

*************************************************
OUTPUT:

List of keys by position 0:
 331066610 -> 
_____________________________________
RU: 331066610
Student: Raquel Nogueira
Email: rnogueira@gmail
_____________________________________
3306660 -> 
_____________________________________
RU: 3306660
Student: Lucas Nogueira Oliveira
Email: luke@gmail
_____________________________________


 List of keys by position 1:
 3316661 -> 
_____________________________________
RU: 3316661
Student: Joao Pedro Nogueira Oliveira
Email: joaonogueira@gmail
_____________________________________


 List of keys by position 2:
 3326662 ->
_____________________________________
RU: 3326662
Student: Gilberto Oliveira Junior
Email: giljr@gmail
_____________________________________


 List of keys by position 3:
 3336663 ->
_____________________________________
RU: 3336663
Student: Anderson Silva
Email: asilva@gmail
_____________________________________


 List of keys by position 4:
 3346664 ->
_____________________________________
RU: 3346664
Student: Aparecido Lima
Email: alima@gmail
_____________________________________


 List of keys by position 5:
 3356665 ->
_____________________________________
RU: 3356665
Student: John Lennon
Email: jlennon@gmail
_____________________________________


 List of keys by position 6:
 3366666 ->
_____________________________________
RU: 3366666
Student: Jimmy Hendrix
Email: jhendrix@gmail
_____________________________________


 List of keys by position 7:
 3376667 ->
_____________________________________
RU: 3376667
Student: Marilia Mendonca
Email: mmendonca@gmail
_____________________________________


 List of keys by position 8:
 3376668 ->
_____________________________________
RU: 3376668
Student: Fred Mercury
Email: fmercury@gmail
_____________________________________


 List of keys by position 9:
 3396669 ->
_____________________________________
RU: 3396669
Student: Caetano Veloso
Email: cveloso@gmail
_____________________________________

Pressione qualquer tecla para continuar. . . 
*************************************************

UNINTER - ESCOLA SUPERIOR POLITÉCNICA
GILBERTO OLIVEIRA JUNIOR
RU - 3326662
Graduation: Computer Engineering
Academic Work - Please, see requerements above o/

Edited By: J3
Date: Nov, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VECTORSIZE 10

//Typedef definition
typedef struct HashList
{	int id;
    	char student[50];
    	char email[50];
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
void InsertHash(Table_t *, int, char[], char[], int);
void ShowHash(Table_t *);
void RemoveHash(Table_t *, int, int);
void SearchHash(Table_t *, int, int);

int main()
{
	int op, c, id, pos;
	Table_t *TableHash = (Table_t *)malloc(sizeof(Table_t));
	TableHash->Size = VECTORSIZE;
	TableHash->ListKey = (HashList_t **)malloc(VECTORSIZE * sizeof(HashList_t *));
    	char student[50], email[50];

	for (int i = 0; i < VECTORSIZE; i++)
		TableHash->ListKey[i] = NULL;

	while (1)
	{
		op = menu();
		switch (op)
		{
		case 1: //insert
			printf("Type the id of the student: ");
			scanf_s("%d", &id);
			while ((c = getchar()) != '\n' && c != EOF)
			{
			}
            printf("Type the name of the student: ");
			scanf_s("%[a-zA-z ]]", &student);
			while ((c = getchar()) != '\n' && c != EOF)
			{
			}
            printf("Type the email of the student: ");
			scanf_s("%[a-zA-z@ ]]", &email);
			while ((c = getchar()) != '\n' && c != EOF)
			{
			}
			pos = HashingFunction(id);
			printf("Inserting in position %d of Table...\n", pos);
			system("pause");
			InsertHash(TableHash, id, student, email, pos);
			break;
		case 2: //remove
			printf("Type the number to remove: ");
			scanf_s("%d", &id);
			while ((c = getchar()) != '\n' && c != EOF)
			{
			}
			pos = HashingFunction(id);
			printf("Removing from position %d of Table...\n", pos);
			printf("WARNING: The System returns if nothing is found, ok? \n");
			system("pause");
			RemoveHash(TableHash, id, pos);
			break;
		case 3: //search
			printf("Type the number to search: ");
			scanf_s("%d", &id);
			while ((c = getchar()) != '\n' && c != EOF)
			{
			}
			pos = HashingFunction(id);
			printf("Searching for id %i ...\n", id);
			printf("WARNING: The System returns if nothing is found, ok? \n");
			system("pause");
			SearchHash(TableHash, id, pos);
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

int HashingFunction(int id)
{
	return (id % VECTORSIZE);
}

void InsertHash(Table_t *TableHash, int id, char student[50], char email[50], int pos)
{
	HashList_t *NewItem;
	NewItem = (HashList_t *)malloc(sizeof(HashList_t));
	NewItem->id = id;
    	strcpy(NewItem->student, student);
    	strcpy(NewItem->email, email);
	NewItem->prox = NULL;

	NewItem->prox = TableHash->ListKey[pos];
	TableHash->ListKey[pos] = NewItem;
}

void SearchHash(Table_t *TableHash, int id, int pos)
{
	HashList_t *ScanItem;
	ScanItem = (HashList_t *)malloc(sizeof(TableHash));
	ScanItem = TableHash->ListKey[pos];

	HashList_t *Auxiliar;
	Auxiliar = (HashList_t *)malloc(sizeof(HashList_t));

	if (TableHash->ListKey[pos]->id == id)
	{
		TableHash->ListKey[pos] = TableHash->ListKey[pos]->prox;
		printf("YES, The student RU-%d was found in table!\n", id);
	}
	else
	{
		while (ScanItem->id != id)
		{
			Auxiliar = ScanItem;
			ScanItem = ScanItem->prox;
		}
		Auxiliar->prox = ScanItem->prox;
		printf("YES, The The student RU-%d was found in table!\n", id);
	}
}

void RemoveHash(Table_t *TableHash, int id, int pos)
{
	HashList_t *ScanItem;
	ScanItem = (HashList_t *)malloc(sizeof(TableHash));
	ScanItem = TableHash->ListKey[pos];

	HashList_t *Auxiliar;
	Auxiliar = (HashList_t *)malloc(sizeof(HashList_t));

	if (TableHash->ListKey[pos]->id == id)
	{
		TableHash->ListKey[pos] = TableHash->ListKey[pos]->prox;
		free(ScanItem);
	}
	else
	{
		while (ScanItem->id != id)
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
			printf("%d -> ", ScanItem->id);
        		printf("\n_____________________________________\n");
        		printf("RU: %i\n", ScanItem->id);
       		 	printf("Student: %s\n", ScanItem->student);
        		printf("Email: %s\n", ScanItem->email);
        		printf("_____________________________________\n");
			ScanItem = ScanItem->prox;
		}
		printf("\n");
	}
}
