/*
Project #10 (CSeries)

10_MUSICALBUM_V2.C
------------------

Description:

This is a deque. It implements a J3 MUSIC ALBUM!
It simulate a playlist on the console.
Pre load file available. 
See Projects 05,06,07, and 08. 
These 4 project help me find this solution.
Enjoy!
Welcome!

Deque_v1 or Double Ended Queue is a generalized version of Queue data structure 
that allows insert and delete at both ends.

How To Use:

1. Use VSCode. 
Please see this tutorial to get running:
https://medium.com/jungletronics/vs-code-how-to-run-it-right-away-6fc9e569099a
2. Load this file to the same directory: musicalbum_v0.csv
3. Enjoy it! It´s free!

Code Base: 

https://github.com/borinvini/EstruturaDeDados_AP2
Credits: https://br.linkedin.com/in/borinvini

Requirements:

EXERCISE N. 1

Make a C language algorithm that emulates the characteristics of a video player
songs running in text mode via command prompt.
1. You must create a playlist of songs using a linked list. The list
chained can be single or double, circular or non-circular. stay at
at the discretion of the student to decide.
2. You must store the name of each song, artist/band and the duration of the
range. For storage use a heterogeneous data structure.
3. For data entry, you can create a data reading through
an on-screen menu or have them stored in a text file on your
computer and only load this file when running the program. or both
solutions. Also decide how you will implement the insert (in the beginning,
at the end or in the middle of the linked list);
4. There should be a menu on the screen. This menu must allow the insertion of new ones.
songs (if you opted for manual data entry), you must have the option to
list all songs in the playlist (listing a linked list) on the screen
and end the program;
Use as a basis the code of lists of the PRACTICE CLASS 2 of the discipline. code is
available on the teacher's Github. The link is in practice class 2 (see Base code);

Supported Operations:

insertFront(): Adds an item at the front of Deque.
insertLast(): Adds an item at the rear of Deque.
insertMid(): Adds an item at the middle of deque.
deleteFront(): Deletes an item from front of Deque.
deleteLast(): Deletes an item from rear of Deque.
removeFromDeque(int): removes an item from entering position (initial is 1) 
displayDeque(): Displays a list of itens in console.

TODO: 

In the future (V2), we will also support these following operations: 
getFront(): Gets the front item from queue.
getRear(): Gets the last item from queue.
isEmpty(): Checks whether Deque is empty or not.
isFull(): Checks whether Deque is full or not.

KNOWN BUGs:

Display empty item;
Remove duplicated items or Avoid entering duplicated items;
Validate entry file;
while data entry, permission to abondon de operation;
Error treatment on file manipulation;

Applications of Deque:

Since Deque supports both stack and queue operations, it can be used as both. 
The Deque data structure supports clockwise and anticlockwise rotations 
in O(1) time which can be useful in certain applications.

We Use These Functions:

https://en.cppreference.com/w/c/io/fopen
We used both fopen [see loadfile()] as well as fopen_s[see 6.Exit on switch]
As this is for academic purposes, we decided to keep the form less safe. If in production, prefer the safe way
Mode & Descriptions:
r
Opens an existing text file for reading purpose.
	
w
Opens a text file for writing. If it does not exist, then a new file is created. 
Here your program will start writing content from the beginning of the file.
	
a
Opens a text file for writing in appending mode. If it does not exist, 
then a new file is created. Here your program will start appending content 
in the existing file content.

r+
Opens a text file for both reading and writing.

w+
Opens a text file for both reading and writing. 
It first truncates the file to zero length if it exists, 
otherwise creates a file if it does not exist.

a+
Opens a text file for both reading and writing. 
It creates the file if it does not exist. 
The reading will start from the beginning but writing can only be appended.

Difficulties Encountered In Coding:

1. String Handling:
the implementation of the source code provided only integer structure; 
when including strings the handling is more difficult; 
C treats strings as a string´s array of character w/ /0 as terminator; 
printing to the console or load to a file on disk, the rules change.

2. Load File:
when loading the file we use ´r´ [see loadfile()]; At the exit, w+ [see 6.Exit on switch].
https://en.cppreference.com/w/c/io/fscanf
To simplifying: scanf receives data from the console; sscan receives from a stream.
I load each line of the file and parse the line, piece by piece [see loadfile()]
3.  Getting a Very Clean Code As Possible:
I avoided comments in the code to leave it as recommended in the book: Clean Code:
https://www.amazon.com.br/Clean-Code-Handbook-Software-Craftsmanship/dp/0132350882

3. Honestly, the hardest part was this excerpt [loadFile()]:
sscanf(line, "%i,%[^,], %[^,], %i", &track, artist, music, &duration);
this breaks the line to pieces.
scanf receive from console.
sscanf receives from a stream and use regex: ^,
which means: read to the comma, break.

In the end of the day, these are the observations.
I hope they are useful to someone. 
I write it down because I will certainly forget soon:/ 
Bye!

******************************************************************************
Output:
WELCOME to J3 MUSIC ALBUM!!! ENJOY!!!
This Deque supports these operations:
_____________________________________

1.Insert at beginning of deque       
2.Insert at end of deque
3.Insert at middle of deque
4.Remove from deque
5.Display deque items
6.Exit
_____________________________________
Which operation you chose? 5
_____________________________________
Track: 1
Artist: Frank Sinatra
Music: Ive Got You Under My Skin
Duration: 465
_____________________________________
_____________________________________
Track: 2
Artist: Caetano Veloso
Music: Anjos Tronxos
Duration: 647
(...)
_____________________________________
Track: 13
Artist: Led Zepellin
Music: Stairway to Haven
Duration: 457
_____________________________________
_____________________________________
Track: 14
Artist: U2
Music: Sunday Bloody Sunday
Duration: 457
_____________________________________
...
Exiting:

 musicalbum_v0.csv file saved sucessfuly!

 Thank You kindly!

******************************************************************************
UNINTER - ESCOLA SUPERIOR POLITÉCNICA
Graduation: Computer Engineering
Academic Work - Please, see requerements above o/

Edited By: J3
Date: Nov, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 20

char filename[MAX_LEN] = "musicalbum_v0.csv";
FILE *file;

// Prototypes:
int menu();
void insertFront(int, char[], char[], int);
void insertLast(int, char[], char[], int);
void insertMid(int, char[], char[], int, int);
int removeFromDeque(int);
void displayDeque();
void loadFile(char[]);


struct SimpleDeque_Item
{
    int track;
    char artist[50];
    char music[50];
    int duration;
    struct SimpleDeque_Item *next;
} * head;

int main()
{
    int op, num, pos, c, res, track, duration;
    char artist[50], music[50];
    head = NULL;

    FILE *fpt;
    errno_t err;

    loadFile(filename);

    while (1)
    {
        op = menu();
        switch (op)
        {
        case 1: // 1.Insert at beginning of deque
            printf("Enter the desired Track number: ");
            scanf_s("%d", &track);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            printf("Enter the Artist name: ");
            scanf_s("%[a-zA-z ]]", &artist);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            printf("Enter the Music name: ");
            scanf_s("%[a-zA-z ]]", &music);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            printf("Enter the Duration of the track: ");
            scanf_s("%d", &duration);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            insertFront(track, artist, music, duration);
            break;
        case 2: // 2.Insert at end of deque
            printf("Enter the desired Track number: ");
            scanf_s("%d", &track);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            printf("Enter the Artist name: ");
            scanf_s("%[a-zA-z ]]", &artist);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            printf("Enter the Music name: ");
            scanf_s("%[a-zA-z ]]", &music);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            printf("Enter the Duration of the track: ");
            scanf_s("%d", &duration);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            insertLast(track, artist, music, duration);
            break;
        case 3: // 3.Insert at middle of deque
            printf("Enter the desired Track number: ");
            scanf_s("%d", &track);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            printf("Enter the Artist name: ");
            scanf_s("%[a-zA-z ]]", &artist);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            printf("Enter the Music name: ");
            scanf_s("%[a-zA-z ]]", &music);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            printf("Enter the Duration of the track: ");
            scanf_s("%d", &duration);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            printf("Enter the position you want to insert the new track: ");
            scanf_s("%d", &pos);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            insertMid(track, artist, music, duration, pos);
            break;
        case 4: // 4.Remove from deque
            printf("Enter the desired Track number: ");
            scanf_s("%d", &track);
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

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
            err = fopen_s(&fpt, filename, "w+");
            
            /* Saving all Tracks to a File */
            struct SimpleDeque_Item *ScanItem;
            ScanItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));

            ScanItem = head;
            if (ScanItem == NULL)
            {
                return 1;
            }
            while (ScanItem != NULL)
            {
                fprintf(fpt, "%i,%s,%s,%i\n", ScanItem->track, ScanItem->artist, ScanItem->music, ScanItem->duration);
                ScanItem = ScanItem->next;
            }
            /* Closing the file to avoid memory leakage */
            fclose(fpt);
            printf("\n %s file saved sucessfuly!\n\n", filename);
            printf("\nThank You kindly!\n\n");
            return 0;
        default:
            printf("Invalid Number!\n");
        }
    }
    return 0;
}

int menu()
{
    int op, c;
    system("Cls");

    printf("WELCOME to J3 MUSIC ALBUM!!! ENJOY!!!\n");

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
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }

    system("Cls");
    return op;
}

void insertFront(int track, char artist[50], char music[50], int duration)
{
    struct SimpleDeque_Item *NewItem;
    NewItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));

    NewItem->track = track;
    strcpy(NewItem->artist, artist);
    strcpy(NewItem->music, music);
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
    strcpy(NewItem->artist, artist);
    strcpy(NewItem->music, music);
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
    strcpy(NewItem->artist, artist);
    strcpy(NewItem->music, music);
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

int removeFromDeque(int track)
{
    struct SimpleDeque_Item *ScanItem;
    ScanItem = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));
    struct SimpleDeque_Item *Anterior;
    Anterior = (struct SimpleDeque_Item *)malloc(sizeof(struct SimpleDeque_Item));

    ScanItem = head;
    while (ScanItem != NULL)
    {
        if (ScanItem->track == track)
        {
            if (ScanItem == head)
            {
                head = ScanItem->next;
                free(ScanItem);
                return 1;
            }
            else
            {
                Anterior->next = ScanItem->next;
                free(ScanItem);
                return 1;
            }
        }
        else
        {
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
    if (ScanItem == NULL)
    {
        return;
    }
    while (ScanItem != NULL)
    {
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

void loadFile(char filename[])
{

    file = fopen(filename, "r+");
    char line[500];
    while (fgets(line, sizeof(line), file))
    {
        int track;
        char artist[50] = {0};
        char music[50] = {0};
        int duration;

        sscanf(line, "%i,%[^,], %[^,], %i", &track, artist, music, &duration);
            
        insertLast(track, artist, music, duration);
    }

    fclose(file);
}
