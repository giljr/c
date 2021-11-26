/* Project 89  -- DOUBLY LINKED LIST
    
    This is a college work using DOUBLY LINKED LIST.
    
         
	PRACTICE 1
	
	Write an algorithm in C language that meets the following requirements:
	1) The fields of a record must store the music's and artist's name, and track's duration;
	2) Ask the user to enter records;
	3) Records must be stored in a vector;
	4) Make a Menu to enter new tracks;
    5) Through the pointer to the record vector, show the playlist
	
	To demonstrate the operation, take screenshots of the terminal using its name
	complete and your birthday day and month in one of the requested input logs.
	************************************************************
	Output:

		
   ************************************************************
   Representation of the Memories Blocks: (https://asciiflow.com/)
   
            DOUBLY LINKED LIST:
   
	       
	Based on: book - Beginning C From Novice to Professional
	4th Edition Pg 426   Author Ivor Horton 
	Chap 11 - Doubly Linked Lists
	   
	UNINTER - Curso: Engenharia da Computacao
	Escola Superior Politecnica
	Author: Gilberto Jr RU 3326662 
	Edited: J3
	Date: Dez, 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/* This program uses pointer, malloc and structs :) */

int main(int argc, char *argv[]) {
	
	/* Declaration of the structure to hold anniversaries data */
	typedef struct Track	{
		int track;
		char artist[50];
		char music[50];
		int duration;
		struct Track *next;                                     /* Pointer to the next structure */
		struct Track *previous;                                 /* Pointer to the previous structure */ 
		
	}Track_t;
	
	Track_t *first = NULL;					        /* Pointer to the first Register */
	Track_t *current = NULL;				        /* Pointer to the current Register */
	Track_t *last = NULL;					        /* Pointer to the previus Register */
	
	
	/* Test value for ending input */
	char test = '\0';
	 
	/* Variable to deal with buffer's cleaning */
	int c; 
	
	printf("\n\n_____________________!!!!!WELCOME TO JR'PLAYLIST!!!!'_______________________\n\n");

	for( ; ; )  /* Infinite loop; you do not have to worry about arrays and mess around with indexes */
	{
	    printf("\nDo you What to enter a Track now (Y or N)?");
		scanf(" %c", &test);
		//while ((c = getchar()) != '\n' && c != EOF) { } 	/* clears input buffer */
	
		if(tolower(test) == 'n') break;
		
		/* Allocate memory to hold the structure */
		/* This statement allocates the space for each structure dynamically as it's requered */
		/* The malloc() function allocates the number of bytes specified by its argument and 
		   returns the address of the block of memory allocated as a pointer to type votrack */
		//ptr2Calendar[rcounter] = (Track_t*) malloc(sizeof(Track_t));
		current = (Track_t*) malloc(sizeof(Track_t));         				
		
		if(first == NULL)
		{
			first = current;                                /* Set pointer to first register */
			current->previous = NULL;                       /* The first node points previous to NULL */
		}
		else
		{
			last->next = current;  		                /* Set next pointer for previous register */
			current->previous = last;                       /* Previous address for current node */
		}
			
		printf("\nPlease enter the Track Number: ");
		//scanf("%i", &Calendar[rcount].month);                 /* Read the track of the person in the register */	
		//scanf("%i", &ptr2Calendar[rcounter]->month);
		scanf("%i", &current->track);		
		while ((c = getchar()) != '\n' && c != EOF) { } 	/* clears input buffer */	
			
		printf("\nPlease enter the Artist Name: ");
		gets(current->artist);
		//scanf("%s", &current->artist);
		//while ((c = getchar()) != '\n' && c != EOF) { } 
			
		printf("\nPlease enter the Music Name: ");
		gets(current->music);
		//scanf("%i", &current->music);		
		//while ((c = getchar()) != '\n' && c != EOF) { } 	/* clears input buffer */
			
		printf("\nPlease enter the Track Duration (sec): ");
		//scanf("%i", &Calendar[rcount].month);                 /* Read the track of the person in the register */	
		//scanf("%i", &ptr2Calendar[rcounter]->month);
		scanf("%i", &current->duration);		
		while ((c = getchar()) != '\n' && c != EOF) { } 	/* clears input buffer */
 		
		current->next = NULL;  					/* In case it is the last... */
		last = current;     	     				/* Save address of the last register */
	}
	
	//current = first;                				/* Starting at the beginning */
	
	/* Printing the receipt if everything is ok */
	printf ("\n You have Entered these Musics:\n\n"); 
	printf("__________________________Tracks______List____________________________\n");
	printf("| Track |  Artist Name  |         Music Title         | Time(sec) |\n") ;
	printf("----------------------------------------------------------------------\n");		
	/* This for loop prints the output and frees the memory allocated, block by block */	
	//for(int i = 0; i < rcounter; i++)
	while(current != NULL)     					/* As long as we have a valtrack pointer */ 
	{		
		printf("| %i | %s | %s | %i |\n", current->track, current->artist, current->music, current->duration);
		
		last = current;    					/* Save the pointer so we can free memory */
		//current = current->next;  				/* Get the pointer to the next */
		current = current->previous;  				/* PRINTTING IN REVERSE ORDER */
		
		/* It is very important to free each block of memory previously allocated;
		   If you don't keep track and don't free it after malloc, you might have memory leaks :/
		   it's considered good style to free memory as soon as you don't need it any more. Read this post:
		   https://stackoverflow.com/questions/654754/what-really-happens-when-you-dont-free-after-malloc */		   
		//free(ptr2Calendar[i]);     
		//free(previous); 
		free(last);
	}
	    printf("\n______________________________________________________________________\n");
        printf("\n_______________________________________________________________________\n");
	
	return 0;
}

