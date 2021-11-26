/*
Project #05 (CSeries)

06_MUSICALBUM_V1.C
------------------
(Please, see cmplete project at: 10_MUSICALBUM_V2.C)

Description:
This is a deque. It implements a J3 MUSIC ALBUM!
Welcome!

Deque_v1 or Double Ended Queue is a generalized version of Queue data structure 
that allows insert and delete at both ends.

Supported Operations:

insertFront(): Adds an item at the front of Deque.
insertLast(): Adds an item at the rear of Deque.
insertMid(): Adds an item at the middle of deque.
removeFromDeque(int): removes an item from entering position (initial is 1) 
displayDeque(): Displays a list of itens in console.

TODO: 

In the future (V2), we will also support these following operations: 
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

******************************************************************************
OUTPUT:
This Deque supports these operations:
_____________________________________

1.Insert at beginning of deque
2.Insert at end of deque
3.Insert at middle of deque
4.Remove from deque
5.Display deque items
6.Exit
_____________________________________
Which operation you chose? 1
Enter the desired Track number: 1
Enter the Artist name: Queens      
Enter the Music name: We Are The Champions
Enter the Duration of the track: 451

Which operation you chose? 5
_____________________________________
Track: 1
Artist: Queens
Music: We Are The Champions
Duration: 451
_____________________________________

******************************************************************************
UNINTER - ESCOLA SUPERIOR POLITECNICA 
Edited By: J3
Date: Nov, 2021
*/

#include<stdio.h>                              
#include<stdlib.h>
#include <string.h>

int menu();
void insertFront(int track, char[], char[], int);
void insertLast(int track, char[], char[], int);
void insertMid(int track, char artist[50], char music[50], int duration, int position);
int removeFromDeque(int track);
void displayDeque();

struct SimpleDeque_Item {
    int track;
    char artist[50];
    char music[50];
    int duration;
    struct SimpleDeque_Item *next;
} *head;

int  main() {
    int op, num, pos, c, res, track, duration;
    char artist[50], music[50];
    head = NULL;


    while (1) {
        op = menu();
        switch (op) {
        case 1: // 1.Insert at beginning of deque
            printf("Enter the desired Track number: ");
            scanf_s("%d", &track);
            while ((c = getchar()) != '\n' && c != EOF) {} 

            printf("Enter the Artist name: ");
            scanf_s("%[a-zA-z ]]",&artist);
            while ((c = getchar()) != '\n' && c != EOF) {} 

            printf("Enter the Music name: ");
            scanf_s("%[a-zA-z ]]",&music);
            while ((c = getchar()) != '\n' && c != EOF) {} 

            printf("Enter the Duration of the track: ");
            scanf_s("%d", &duration);
            while ((c = getchar()) != '\n' && c != EOF) {} 

            insertFront(track, artist, music, duration);
            break;
        case 2: // 2.Insert at end of deque
            printf("Enter the desired Track number: ");
            scanf_s("%d", &track);
            while ((c = getchar()) != '\n' && c != EOF) {} 

            printf("Enter the Artist name: ");
            scanf_s("%[a-zA-z ]]",&artist);
            while ((c = getchar()) != '\n' && c != EOF) {} 

            printf("Enter the Music name: ");
            scanf_s("%[a-zA-z ]]",&music);
            while ((c = getchar()) != '\n' && c != EOF) {} 

            printf("Enter the Duration of the track: ");
            scanf_s("%d", &duration);
            while ((c = getchar()) != '\n' && c != EOF) {} 

            insertLast(track, artist, music, duration);
            break;
        case 3: // 3.Insert at middle of deque
            printf("Enter the desired Track number: ");
            scanf_s("%d", &track);
            while ((c = getchar()) != '\n' && c != EOF) {} 

            printf("Enter the Artist name: ");
            scanf_s("%[a-zA-z ]]",&artist);
            while ((c = getchar()) != '\n' && c != EOF) {} 

            printf("Enter the Music name: ");
            scanf_s("%[a-zA-z ]]",&music);
            while ((c = getchar()) != '\n' && c != EOF) {} 

            printf("Enter the Duration of the track: ");
            scanf_s("%d", &duration);
            while ((c = getchar()) != '\n' && c != EOF) {} 
            printf("Enter the position you want to insert the new track: ");
            scanf_s("%d", &pos);
            while ((c = getchar()) != '\n' && c != EOF) {}
            insertMid(track, artist, music, duration, pos);
            break;
        case 4: // 4.Remove from deque
            printf("Enter the desired Track number: ");
            scanf_s("%d", &track);
            while ((c = getchar()) != '\n' && c != EOF) {} 
  
            res = removeFromDeque(track);
            if (res == 1)
                printf("Track Number removed from Deque!");
            else
                printf("Track Number not found!");
            break;
        case 5: // 5.Display deque items
            displayDeque();
            break;
        case 6: // 6.Exit
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

void insertFront(int track, char artist[50], char music[50], int duration)
{
    struct SimpleDeque_Item *NewItem;
    NewItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));
    
    NewItem->track = track;
    strcpy(NewItem->artist , artist);
    strcpy(NewItem->music , music);
    NewItem->duration = duration;

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

void insertLast(int track, char artist[50], char music[50], int duration)
{
    struct SimpleDeque_Item *NewItem;
    NewItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));
    struct SimpleDeque_Item *ScanItem;
    ScanItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));

    NewItem->track = track;
    strcpy(NewItem->artist , artist);
    strcpy(NewItem->music , music);
    NewItem->duration = duration;

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

void insertMid(int track, char artist[50], char music[50], int duration, int position)
{
    struct SimpleDeque_Item *NewItem;
    NewItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));
    struct SimpleDeque_Item *ScanItem;
    ScanItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));
    struct SimpleDeque_Item *AuxiliaryItem;
    AuxiliaryItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));

    NewItem->track = track;
    strcpy(NewItem->artist , artist);
    strcpy(NewItem->music , music);
    NewItem->duration = duration;

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
        if (ScanItem->track == num) {
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
        printf("_____________________________________\n");
        printf("Track: %i\n", ScanItem->track);
        printf("Artist: %s\n", ScanItem->artist);
        printf("Music: %s\n", ScanItem->music);
        printf("Duration: %i\n", ScanItem->duration);
        printf("_____________________________________\n");
        ScanItem = ScanItem->next;
    }
    printf("\n");

    system("pause");
    return;
}
