/*
Project #05 (CSeries)

05_DEQUE_V1.C
-------------

Description:
This is a deque (en).
It transform the Project 04 code in English.
It form a deque of integer.
It's purpose is to implementation of Project #10 - MUSIC ALBUM APP!

Deque_v1 or Double Ended Queue is a generalized version of Queue data structure 
that allows insert and delete at both ends.

Supported Operations:

insertFront(): Adds an item at the front of Deque.
insertLast(): Adds an item at the rear of Deque.
insertMid(): Adds an item at the middle of deque.
deleteFront(): Deletes an item from front of Deque.
deleteLast(): Deletes an item from rear of Deque.
removeFromDeque(int): removes an item from entering position (initial is 1) 
displayDeque(): Displays a list of itens in console.

TODO: 

in the future (V2), we will also support these following operations: 
getFront(): Gets the front item from queue.
getRear(): Gets the last item from queue.
isEmpty(): Checks whether Deque is empty or not.
isFull(): Checks whether Deque is full or not.

BUG KNOWN:

Display empty item
Remove duplicated items or Avoid entering duplicated items

Applications of Deque:

Since Deque supports both stack and queue operations, it can be used as both. 
The Deque data structure supports clockwise and anticlockwise rotations 
in O(1) time which can be useful in certain applications.

This Deque supports these operations:
*****************************************************************************
Output:
_____________________________________

1.Insert at beginning of deque
2.Insert at end of deque
3.Insert at middle of deque
4.Remove from deque
5.Display deque items
6.Exit
_____________________________________
Which operation you chose? 5

0 1 2 3 

*****************************************************************************

Edited By: J3
Date: Nov, 2021
*/

#include<stdio.h>							   
#include<stdlib.h>

int menu();
void insertFront(int num);
void insertLast(int num);
void insertMid(int num, int position);
int removeFromDeque(int num);
void displayDeque();

struct SimpleDeque_Item {
	int data;
	struct SimpleDeque_Item *next;
} *head;

int  main() {
	int op, num, pos, c, res;
	head = NULL;

	while (1) {
		op = menu();
		switch (op) {
		case 1:
			printf("Enter the desired number: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} 
			insertFront(num);
			break;
		case 2:
			printf("Enter the desired number: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} 
			insertLast(num);
			break;
		case 3:
			printf("Enter the desired number: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} 
			printf("Enter the position you want to insert: ");
			scanf_s("%d", &pos);
			while ((c = getchar()) != '\n' && c != EOF) {}
			insertMid(num, pos);
			break;
		case 4:
			printf("Enter the number to be remove from Dequed: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {}
			res = removeFromDeque(num);
			if (res == 1)
				printf("Number removed from Deque!");
			else
				printf("Number not found!");
			break;
		case 5:
			displayDeque();
			break;
		case 6:
			return 0;
		default:
			printf("Invalid Number!\n");
		}
	}
	return 0;
}

int menu() {
	int op, c;
	system("Cls");
    
	printf("This Deque supports these operations:\n");
	printf("_____________________________________\n\n");
	printf("1.Insert at beginning of deque\n");
	printf("2.Insert at end of deque\n");
	printf("3.Insert at middle of deque\n");
	printf("4.Remove from deque\n");
	printf("5.Display deque items\n");
	printf("6.Exit\n");
	printf("_____________________________________\n");
	printf("Which operation you chose? ");
	

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} 
	
	system("Cls");
	return op;
}

void insertFront(int num)
{
	struct SimpleDeque_Item *NewItem;
	NewItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));
	NewItem->data = num;

	if (head == NULL)
	{
		head = NewItem;
		head->next = NULL;
	}
	else
	{
		NewItem->next = head;
		head = NewItem;
	}
}

void insertLast(int num)
{
	struct SimpleDeque_Item *NewItem;
	NewItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));
	struct SimpleDeque_Item *ScanItem;
	ScanItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));

	NewItem->data = num;

	if (head == NULL)
	{
		head = NewItem;
		head->next = NULL;
	}
	else
	{
		ScanItem = head;
		while (ScanItem->next != NULL)
			ScanItem = ScanItem->next;

		ScanItem->next = NewItem;
		NewItem->next = NULL;
	}
}

void insertMid(int num, int position)
{
	struct SimpleDeque_Item *NewItem;
	NewItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));
	struct SimpleDeque_Item *ScanItem;
	ScanItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));
	struct SimpleDeque_Item *AuxiliaryItem;
	AuxiliaryItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));

	NewItem->data = num;

	if (position == 0)
	{
		head = NewItem;
		head->next = NULL;
	}
	else
	{
		ScanItem = head;
		for (int i = 0; i < position - 1; i++)
			ScanItem = ScanItem->next;

		AuxiliaryItem = ScanItem->next;
		ScanItem->next = NewItem;
		NewItem->next = AuxiliaryItem;
	}
}

int removeFromDeque(int num)
{
	struct SimpleDeque_Item *ScanItem;
	ScanItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));
	struct SimpleDeque_Item *Anterior;
	Anterior = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));

	ScanItem = head;
	while (ScanItem != NULL) {
		if (ScanItem->data == num) {
			if (ScanItem == head) {
				head = ScanItem->next;
				free(ScanItem);
				return 1;
			}
			else {
				Anterior->next = ScanItem->next ;
				free(ScanItem);
				return 1;
			}
		}
		else {
			Anterior = ScanItem;
			ScanItem = ScanItem->next;
		}
	}
	return 0;
}

void displayDeque()
{
	struct SimpleDeque_Item *ScanItem;
	ScanItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));

	ScanItem = head;
	if (ScanItem == NULL) {
		return;
	}
	while (ScanItem != NULL) {
		printf("%d ", ScanItem->data);
		ScanItem = ScanItem->next;
	}
	printf("\n");

	system("pause");
	return;
}