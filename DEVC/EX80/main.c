/* Project 80  -- DOUBLY LINKED LIST
    
	This example should produce the same output as Project 77, 
    burt here we are using DOUBLY LINKED LIST.
    
    Please see the comments to the previous project (69)
     
	PRACTICE 1
	
	Write an algorithm in C language that meets the following requirements:
	1) The fields of a record must store the Name, birthday and month of birthday;
	2) Ask the user to enter 12 records;
	3) Records must be stored in a vector;
	4) Through the pointer to the record vector, show in each month of the year
	   who are the people who have birthdays.
	
	To demonstrate the operation, take screenshots of the terminal using its name
	complete and your birthday day and month in one of the requested input logs.
	************************************************************
	Output:

	Do you What to enter details of another anniversary date (Y or N)?Y
	Please enter the ID number to the next register: 1001
	Please enter the name of the boy or girls: Gilbert Jr
	Please enter the Day of Anniversary to this register: 14
	Please enter the Month of Anniversary to this register: 1
	Do you What to enter details of a anniversary date (Y or N)?y
	Please enter the ID number to the next register: 1002
	Please enter the name of the boy or girls: Luc Skydiver
	Please enter the Day of Anniversary to this register: 18
	Please enter the Month of Anniversary to this register: 8
	Do you What to enter details of a anniversary date (Y or N)?n
	
	 You have Entered these dates:
	
	_____Anniversary______Calendar______
	 Cod |   Name   | Day | Month
	------------------------------------
	 12588032 | Luc Skydiver | 18 | 8
	 12588032 | Gilbert Jr | 14 | 1
	
	____________________________________
	
	____________________________________
		
   ************************************************************
   Representation of the Memories Blocks: (https://asciiflow.com/)
   
            DOUBLY LINKED LIST:
            
                      Head                              Tail
                   +----------+     +---------+     +---------+
           NULL--->¦.¦      ¦.¦---->¦.¦     ¦.¦---->¦.¦     ¦.¦---> NULL
                   +----------+     +---------+     +---------+
                       ¦                 ¦
		       +->Register1      +->Register2
                                                 

                  +-------------+
*first      NULL <¦     ¦ ¦ ¦ ¦ ¦--> NULL  -> 80186
                  +-+-+-+-+-+-+-¦                   ¦
*current   80186 <¦.¦ ¦ ¦ ¦ ¦ ¦.+--> NULL  -> 80186-¦> NULL -> 90144  -> NULL
                  +-+-+-+-+-+-+-¦                   ¦
*previous         ¦.¦ ¦ ¦ ¦ ¦ ¦.+--> NULL  -> 80186 +--------> 90144
                  +-+-+-+-+-+-+-¦                   ¦                ¦
 *last     80186 <¦.¦ ¦ ¦ ¦ ¦ ¦.+--> NULL  -> 90144 ¦                ¦
                  +-------------¦                   ¦                ¦
                  ¦     ...     ¦                   ¦                ¦
                  ¦             ¦                   ¦                ¦
           80186 <+-------------¦   Register1 <-----+                ¦                 ?
                  ¦+++++++++++++¦                                    ¦
                  ¦+++++++++++++¦                                    ¦
                  ¦+++++++++++++¦                                    ¦
                  ¦+++++++++++++¦                                    ¦
                  +-------------¦                                    ¦
                  ¦             ¦                                    ¦
                  ¦     ...     ¦                                    ¦
           90144 <+-------------¦   Register2  <---------------------+
                  ¦+++++++++++++¦
                  ¦+++++++++++++¦
                  ¦+++++++++++++¦
                  ¦+++++++++++++¦
                  +-------------¦
                  ¦             ¦
                  ¦             ¦
                  ¦             ¦
                  ¦             ¦
                  +-------------+
	       
	Based on: book - Beginning C From Novice to Professional
	4th Edition Pg 426   Author Ivor Horton 
	Chap 11 - Doubly Linked Lists
	   
	UNINTER - Curso: Engenharia da Computa??o
	Escola Superior Politecnica
	Author: Gilberto Jr RU 3326662 
	Edited: J3
	Date: Jun, 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/* This program uses pointer, malloc and structs :) */

int main(int argc, char *argv[]) {
	
	/* Declaration of the structure to hold anniversaries data */
	typedef struct Niver
	{
		int id;
		char name[50];
		int day;
		int month;	
		struct Niver *next;                                 /* Pointer to the next structure */
		struct Niver *previous;                             /* Pointer to the previous structure */ 
		
	}Niver_t;
	
	Niver_t *first = NULL;					        /* Pointer to the first Register */
	Niver_t *current = NULL;				        /* Pointer to the current Register */
	Niver_t *last = NULL;					        /* Pointer to the previus Register */
	
	/* Pointer to structure array declaration */
	//Niver_t *ptr2Calendar[12];
	
	/* Register counter */ 
	//int rcounter = 0;
	
	/* Test value for ending input */
	char test = '\0';
	 
	/* Variable to deal with buffer's cleaning */
	int c; 
	
	/* rcount - is the counter for each register entered:) */	
	//for(rcounter = 0; rcounter < 12; rcounter++)
	for( ; ; )  // Infinite loop; you do not have to worry about arrays and mess around with indexes
	{
		//printf("\nDo you What to enter details of a%s anniversary date (y or N)?", rcounter?"nother":"");
		printf("\nDo you What to enter details of a%s anniversary date (Y or N)?", first == NULL?"nother":"");
		
		scanf(" %c", &test);
		//while ((c = getchar()) != '\n' && c != EOF) { } 	/* clears input buffer */
	
		if(tolower(test) == 'n') break;
		
		/* Allocate memory to hold the structure */
		/* This statement allocates the space for each structure dynamically as it's requered */
		/* The malloc() function allocates the number of bytes specified by its argument and 
		   returns the address of the block of memory allocated as a pointer to type void */
		//ptr2Calendar[rcounter] = (Niver_t*) malloc(sizeof(Niver_t));
		current = (Niver_t*) malloc(sizeof(Niver_t));         				
		
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
			
				
		printf("\nPlease enter the ID number to the next register: ");
		//scanf("%i", &Calendar[rcount].id);                    /* Read the id of the person in the register */	
		//scanf("%i", &ptr2Calendar[rcounter]->id);	
		scanf("%i", current->id);	
		while ((c = getchar()) != '\n' && c != EOF) { } 	/* clears input buffer */	
		
		printf("\nPlease enter the name of the boy or girls: ");
		//gets(Calendar[rcount].name);
		//gets(ptr2Calendar[rcounter]->name);
		gets(current->name);
		//scanf("%s", &current->name);
		//while ((c = getchar()) != '\n' && c != EOF) { } 
			
		printf("\nPlease enter the Day of Anniversary to this register: ");
		//scanf("%i", &Calendar[rcount].day); // Read the id of the person in the register	
		//scanf("%i", &ptr2Calendar[rcounter]->day);
		scanf("%i", &current->day);		
		while ((c = getchar()) != '\n' && c != EOF) { } 	/* clears input buffer */
			
		printf("\nPlease enter the Month of Anniversary to this register: ");
		//scanf("%i", &Calendar[rcount].month);                 /* Read the id of the person in the register */	
		//scanf("%i", &ptr2Calendar[rcounter]->month);
		scanf("%i", &current->month);		
		while ((c = getchar()) != '\n' && c != EOF) { } 	/* clears input buffer */
 		
		current->next = NULL;  					/* In case it is the last... */
		last = current;     	     				/* Save address of the last register */
	}
	
	//current = first;                				/* Starting at the beginning */
	
	/* Printing the receipt if everything is ok */
	printf ("\n You have Entered these dates:\n\n"); 
	printf("_____Anniversary______Calendar______\n");
	printf(" Cod |   Name   | Day | Month \n") ;
	printf("------------------------------------\n");		
	/* This for loop prints the output and frees the memory allocated, block by block */	
	//for(int i = 0; i < rcounter; i++)
	while(current != NULL)     					/* As long as we have a valid pointer */ 
	{		
		//printf("%i| %s |%i |%i \n", Calendar[i].id, Calendar[i].name);
		//printf(" %i | %s | %i | %i \n", ptr2Calendar[i]->id, ptr2Calendar[i]->name, ptr2Calendar[i]->day, ptr2Calendar[i]->month);
		printf(" %i | %s | %i | %i \n", current->id, current->name, current->day, current->month);
		
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
	printf("\n____________________________________\n");
        printf("\n____________________________________\n");
	
	return 0;
}

