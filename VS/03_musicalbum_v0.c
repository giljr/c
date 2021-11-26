/* Project 03  -- DOUBLY LINKED LIST

	03_MUSICALBUM_V0.C
	---------------
    
    This is a college work using DOUBLY LINKED LIST.
	It is the first try to get the solution.
	I decided to abort because it give me no flexibility.
	
	The project 10 is the continuation of this effort :)
	
	Check it out o/

	************************************************************
	Output:
	
	_____________________!!!!!WELCOME TO JR'PLAYLIST!!!!'_______________________


	Do you What to enter a Track now (Y or N)?y

	Please enter the Track Number: 1

	Please enter the Artist Name: Pink Floyd

	Please enter the Music Name: Stairway To Haven

	Please enter the Track Duration (sec): 457

	Do you What to enter a Track now (Y or N)?n

	You added this(these) Music(s) in your album:

	________________Tracks______List__________________
	| Track | Artist Name |Music Title | Time(sec) |
	--------------------------------------------------
	| 1 | Pink Floyd | Stairway To Haven | 457 |

	__________________________________________________
		
   ************************************************************
    DOUBLY LINKED LIST:	       
	Based on: book - Beginning C From Novice to Professional
	4th Edition Pg 426   Author Ivor Horton 
	Chap 11 - Doubly Linked Lists

	References: 
	https://en.wikipedia.org/wiki/Frank_Sinatra
	https://en.wikipedia.org/wiki/The_Wall
	http://www.caetanoveloso.com.br/

	https://en.cppreference.com/w/c/io/fopen
	   
	UNINTER - Curso: Engenharia da Computacao
	Escola Superior Politecnica
	Author: Gilberto Jr RU 3326662 
	Edited: J3
	Date: Dez, 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

	
	char filename[] = "music_album_data.csv";

	char txt[150];
	
	
	typedef struct Track	{
		int track;
		char artist[50];
		char music[50];
		int duration;
		struct Track *next;                                    
		struct Track *previous;                                 
		
	}Track_t;
	
	Track_t *first = NULL;					       
	Track_t *current = NULL;				        
	Track_t *last = NULL;					       
	
	

	char test = '\0';
	 
	
	int c; 
	
	printf("\n\n_____________________!!!!!WELCOME TO JR'PLAYLIST!!!!'_______________________\n\n");

	for( ; ; )  
    {
	    printf("\nDo you What to enter a Track now (Y or N)?");
		scanf(" %c", &test);
		while ((c = getchar()) != '\n' && c != EOF) { } 	
	
		if(tolower(test) == 'n') break;
		
		current = (Track_t*) malloc(sizeof(Track_t));         				
		
		if(first == NULL)
		{
			first = current;                               
			current->previous = NULL;                      
		}
		else
		{
			last->next = current;  		               
			current->previous = last;                       
		}
			
		printf("\nPlease enter the Track Number: ");   	
    	scanf("%i", &current->track);		
		while ((c = getchar()) != '\n' && c != EOF) { } 		
			
		printf("\nPlease enter the Artist Name: ");
		gets(current->artist);
			
		printf("\nPlease enter the Music Name: ");
		gets(current->music);
			
		printf("\nPlease enter the Track Duration (sec): ");
		scanf("%i", &current->duration);		
		while ((c = getchar()) != '\n' && c != EOF) { } 	
 		
		current->next = NULL;  					
		last = current;     	     				
	}
	
	FILE *fpt;
	
    fpt = fopen(filename, "a+");
    
  	//fprintf(fpt,"Track,Artist_name,Music_title,Time(sec)\n");

	printf ("\n You added this(these) Music(s) in your album:\n\n"); 
	printf("________________Tracks______List__________________\n");
	printf("| Track | Artist Name |Music Title | Time(sec) |\n") ;
	printf("--------------------------------------------------\n");		
	
	while(current != NULL)     					
	{		
		
		fprintf(fpt,"%i,%s,%s,%i\n", current->track, current->artist, current->music, current->duration);
		
		printf("| %i | %s | %s | %i |\n", current->track, current->artist, current->music, current->duration);
		
		last = current;    					
		current = current->previous;  				
		free(last);
	}
	printf("\n__________________________________________________\n");
    printf("\n__________________________________________________\n");
	
	
	fclose(fpt);
	printf("\n %s file created sucessfully!\n\n",filename);
	return 0;
}

