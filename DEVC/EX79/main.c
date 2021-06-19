/* Project 79  -- LINKED LIST
    
	This example should produce the same output as Project 77, 
	but here you have yet another mode of operation.
	
	How it works?
	This time, not only do you have space for structures allocatted,
	but also you have only three pointers defined initially.
	
	Niver_t *first = NULL;				Pointer to the first Register 
	Niver_t *current = NULL;			Pointer to the current Register 
	Niver_t *previous = NULL;			Pointer to the previus Register 
	
	Each of these pointers has been defined as a pointer to a Niver structure.
	The pointer first is used solely to store the address of the first structure.
	The second and third pointers are working storage: current holds the address
	of the current Niver structure that you're dealing with, and previous keeps
	track of the address of the previous structure that was processed.
	
	This arragement is called a LINKED LIST.
	
	The only drawback of using LINKED LIST is if you want to access it randomly, 
	you pay a penalty in slower access to the data.
	
	The advantage is that you accupy only the minimum memory necessary to store
	and process the list and you don't need to mess around with indexes (it is unnecessary 
	to keep count of how many sets of data are read in :)
     
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
	
	
	Do you What to enter details of a anniversary date (y or N)?y
	Please enter the ID number to the next register: 1001
	Please enter the name of the boy or girls: Gilbert Jr
	Please enter the Day of Anniversary to this register: 14
	Please enter the Month of Anniversary to this register: 1
	Do you What to enter details of another anniversary date (y or N)?y
	Please enter the ID number to the next register: 1002
	Please enter the name of the boy or girls: Luk Skydiver
	Please enter the Day of Anniversary to this register: 18
	Please enter the Month of Anniversary to this register: 8
	Do you What to enter details of another anniversary date (y or N)?n
	
	 You have Entered these dates:
	
	_____Anniversary______Calendar______
	 Cod |   Name   | Day | Month
	------------------------------------
	 1001 | Gilbert Jr | 14 | 1
	 1002 | Luk Skydiver | 18 | 8
	
	____________________________________
		
   ************************************************************
       
	Based on: book - Beginning C From Novice to Professional
	4th Edition Pg 422   Author Ivor Horton 
	Chap 11 - Pointers to Structure As Structure Members
	   
	UNINTER - Curso: Engenharia da Computação
	Escola Superior Politécnica
	Author: Gilberto Jr RU 3326662 
	Edited: J3
	Date: Jun, 2021
 */

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include <ctype.h>
//#include <stdlib.h>

/* This program uses pointer, malloc and structs :) */

int main(int argc, char *argv[]) {
	
	/* Declaration of the structure to hold anniversaries data */
	typedef struct Niver
	{
		int id;
		char name[50];
		int day;
		int month;	
		struct Niver *next;                                     /* Pointer to the next structure */ 
		
	}Niver_t;
	
	Niver_t *first = NULL;						/* Pointer to the first Register */
	Niver_t *current = NULL;					/* Pointer to the current Register */
	Niver_t *previous = NULL;					/* Pointer to the previus Register */
	
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
		printf("\nDo you What to enter details of a%s anniversary date (y or N)?", first?"nother":"");
		scanf(" %c", &test);
		while ((c = getchar()) != '\n' && c != EOF) { } 	/* clears input buffer */
	
		if(tolower(test) == 'n') break;
		
		/* Allocate memory to hold the structure */
		/* This statement allocates the space for each structure dynamically as it's requered */
		/* The malloc() function allocates the number of bytes specified by its argument and 
		   returns the address of the block of memory allocated as a pointer to type void */
		//ptr2Calendar[rcounter] = (Niver_t*) malloc(sizeof(Niver_t));
		current = (Niver_t*) malloc(sizeof(Niver_t));
		
		if(first == NULL)
			first = current;                		/* Set pointer to first register */
		
		if(previous != NULL)
			previous->next = current;  		        /* Set next pointer for previous register */ 
				
		printf("\nPlease enter the ID number to the next register: ");
		//scanf("%i", &Calendar[rcount].id);                	/* Read the id of the person in the register */	
		//scanf("%i", &ptr2Calendar[rcounter]->id);	
		scanf("%i", &current->id);	
		while ((c = getchar()) != '\n' && c != EOF) { } 	/* clears input buffer */	
		
		printf("\nPlease enter the name of the boy or girls: ");
		//gets(Calendar[rcount].name);
		//gets(ptr2Calendar[rcounter]->name);
		gets(&current->name);
		//scanf("%s", &current->name);
		//while ((c = getchar()) != '\n' && c != EOF) { } 
			
		printf("\nPlease enter the Day of Anniversary to this register: ");
		//scanf("%i", &Calendar[rcount].day); // Read the id of the person in the register	
		//scanf("%i", &ptr2Calendar[rcounter]->day);
		scanf("%i", &current->day);		
		while ((c = getchar()) != '\n' && c != EOF) { } 	/* clears input buffer */
			
		printf("\nPlease enter the Month of Anniversary to this register: ");
		//scanf("%i", &Calendar[rcount].month);             	/* Read the id of the person in the register */	
		//scanf("%i", &ptr2Calendar[rcounter]->month);
		scanf("%i", &current->month);		
		while ((c = getchar()) != '\n' && c != EOF) { } 	/* clears input buffer */
 		
		current->next = NULL;  					/* In case it is the last... */
		previous = current;     				/* Save address of the last register */
	}
	
	current = first;                				/* Starting at the beginning */
	
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
		
		previous = current;    					/* Save the pointer so we can free memory */
		current = current->next;  				/* Get the pointer to the next */
		
		/* It is very important to free each block of memory previously allocated;
		   If you don't keep track and don't free it after malloc, you might have memory leaks :/
		   it's considered good style to free memory as soon as you don't need it any more. Read this post:
		   https://stackoverflow.com/questions/654754/what-really-happens-when-you-dont-free-after-malloc */		   
		//free(ptr2Calendar[i]);     
		free(previous); 
	}
	printf("\n____________________________________\n");
    	printf("\n____________________________________\n");
	
	return 0;
}
