/* Project 77

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
	Please enter the name of the boy or girls: Gilberto Jr	
	Please enter the Day of Anniversary to this register: 14	
	Please enter the Month of Anniversary to this register: 1	
	Do you What to enter details of another anniversary date (y or N)?y	
	Please enter the ID number to the next register: 1002	
	Please enter the name of the boy or girls: Mara Maravilha	
	Please enter the Day of Anniversary to this register: 12	
	Please enter the Month of Anniversary to this register: 2	
	Do you What to enter details of another anniversary date (y or N)?y	
	Please enter the ID number to the next register: 1003	
	Please enter the name of the boy or girls: John Lennon	
	Please enter the Day of Anniversary to this register: 30	
	Please enter the Month of Anniversary to this register: 3	
	Do you What to enter details of another anniversary date (y or N)?y	
	Please enter the ID number to the next register: 1004	
	Please enter the name of the boy or girls: Elton John	
	Please enter the Day of Anniversary to this register: 18	
	Please enter the Month of Anniversary to this register: 4	
	Do you What to enter details of another anniversary date (y or N)?y	
	Please enter the ID number to the next register: 1005	
	Please enter the name of the boy or girls: Yves SaintClair	
	Please enter the Day of Anniversary to this register: 19	
	Please enter the Month of Anniversary to this register: 5	
	Do you What to enter details of another anniversary date (y or N)?y	
	Please enter the ID number to the next register: 1006	
	Please enter the name of the boy or girls: Emily White	
	Please enter the Day of Anniversary to this register: 14	
	Please enter the Month of Anniversary to this register: 6	
	Do you What to enter details of another anniversary date (y or N)?y	
	Please enter the ID number to the next register: 1007	
	Please enter the name of the boy or girls: Eleanor Endevour	
	Please enter the Day of Anniversary to this register: 02	
	Please enter the Month of Anniversary to this register: 7	
	Do you What to enter details of another anniversary date (y or N)?y	
	Please enter the ID number to the next register: 1008	
	Please enter the name of the boy or girls: Jeremy Blum	
	Please enter the Day of Anniversary to this register: 19	
	Please enter the Month of Anniversary to this register: 8	
	Do you What to enter details of another anniversary date (y or N)?y	
	Please enter the ID number to the next register: 1009	
	Please enter the name of the boy or girls: Emanuel Macron	
	Please enter the Day of Anniversary to this register: 19	
	Please enter the Month of Anniversary to this register: 9	
	Do you What to enter details of another anniversary date (y or N)?y	
	Please enter the ID number to the next register: 1010	
	Please enter the name of the boy or girls: Paul McArthur	
	Please enter the Day of Anniversary to this register: 16	
	Please enter the Month of Anniversary to this register: 10	
	Do you What to enter details of another anniversary date (y or N)?y	
	Please enter the ID number to the next register: 1011	
	Please enter the name of the boy or girls: Peter Roger	
	Please enter the Day of Anniversary to this register: 17	
	Please enter the Month of Anniversary to this register: 11	
	Do you What to enter details of another anniversary date (y or N)?y	
	Please enter the ID number to the next register: 1012	
	Please enter the name of the boy or girls: Othon Resende	
	Please enter the Day of Anniversary to this register: 19	
	Please enter the Month of Anniversary to this register: 12
		
	 You have Entered these dates:
	
	_____Anniversary______Calendar______
	 Cod |   Name   | Day | Month
	------------------------------------
	 1001 | Gilberto Jr | 14 | 1
	 1002 | Mara Maravilha | 12 | 2
	 1003 | John Lennon | 30 | 3
	 1004 | Elton John | 18 | 4
	 1005 | Yves SaintClair | 19 | 5
	 1006 | Emily White | 14 | 6
	 1007 | Eleanor Endevour | 2 | 7
	 1008 | Jeremy Blum | 19 | 8
	 1009 | Emanuel Macron | 19 | 9
	 1010 | Paul McArthur | 16 | 10
	 1011 | Peter Roger | 17 | 11
	 1012 | Othon Resende | 19 | 12

	____________________________________
	
	____________________________________
		
   ************************************************************
       
	Based on: book - Beginning C From Novice to Professional
	4th Edition Pg 418   Author Ivor Horton 
	Chap 11 - Dynamic Memory Allocation for Structure
	   
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
		
	}Niver_t;
	
	/* Pointer to structure array declaration */
	Niver_t *ptr2Calendar[12];
	
	/* Register counter */ 
	int rcounter = 0;
	
	/* Test value for ending input */
	char test = '\0';
	 
	/* Variable to deal with buffer's cleaning */
	int c; 
	
	/* rcount - is the counter for each register entered:) */	
	for(rcounter = 0; rcounter < 12; rcounter++)
	{
		printf("\nDo you What to enter details of a%s anniversary date (y or N)?", rcounter?"nother":"");
		scanf(" %c", &test);
		while ((c = getchar()) != '\n' && c != EOF) { } 	/* clears input buffer */
	
		if(tolower(test) == 'n') break;
		
		/* Allocate memory to hold the structure */
		/* This statement allocates the space for each structure dynamically as it's requered */
		/* The malloc() function allocates the number of bytes specified by its argument and 
		   returns the address of the block of memory allocated as a pointer to type void */
		ptr2Calendar[rcounter] = (Niver_t*) malloc(sizeof(Niver_t));
				
		printf("\nPlease enter the ID number to the next register: ");
		//scanf("%i", &Calendar[rcount].id);                // Read the id of the person in the register	
		scanf("%i", &ptr2Calendar[rcounter]->id);		
		while ((c = getchar()) != '\n' && c != EOF) { } 	// clears input buffer	
		
		printf("\nPlease enter the name of the boy or girls: ");
		//gets(Calendar[rcount].name);
		gets(ptr2Calendar[rcounter]->name);
		//while ((c = getchar()) != '\n' && c != EOF) { } 
			
		printf("\nPlease enter the Day of Anniversary to this register: ");
		//scanf("%i", &Calendar[rcount].day); // Read the id of the person in the register	
		scanf("%i", &ptr2Calendar[rcounter]->day);		
		while ((c = getchar()) != '\n' && c != EOF) { } 	// clears input buffer
			
		printf("\nPlease enter the Month of Anniversary to this register: ");
		//scanf("%i", &Calendar[rcount].month);             // Read the id of the person in the register	
		scanf("%i", &ptr2Calendar[rcounter]->month);		
		while ((c = getchar()) != '\n' && c != EOF) { } 	// clears input buffer
	}
	
	/* Printing the receipt if everything is ok */
	printf ("\n You have Entered these dates:\n\n"); 
	printf("_____Anniversary______Calendar______\n");
	printf(" Cod |   Name   | Day | Month \n") ;
	printf("------------------------------------\n");		
	/* This for loop prints the output and frees the memory allocated, block by block */	
	for(int i = 0; i < rcounter; i++)
	{		
		//printf("%i| %s |%i |%i \n", Calendar[i].id, Calendar[i].name);
		printf(" %i | %s | %i | %i \n", ptr2Calendar[i]->id, ptr2Calendar[i]->name, ptr2Calendar[i]->day, ptr2Calendar[i]->month);
		/* It is very important to free each block of memory previously allocated;
		   If you don't keep track and don't free it after malloc, you might have memory leaks :/
		   it's considered good style to free memory as soon as you don't need it any more. Read this post:
		   https://stackoverflow.com/questions/654754/what-really-happens-when-you-dont-free-after-malloc */
		free(ptr2Calendar[i]);
	}
	printf("\n____________________________________\n");
    	printf("\n____________________________________\n");
	
	return 0;
}
