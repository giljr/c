#include <stdio.h>
#include <stdlib.h>

/* Project 71
   Structs - Based on this Book: Beginning C - From Novice to Professional (Ivor Horton)
   pg. 414 - Using Arrays of Structures 
   
   This program shows how to use structured structs; on each iteration the user is
   prompted to indicate if he or she wants to enter data for another horse by entering Y or N.
   Note that the printf() statement uses a conditional operator to insert "nother" into the 
   output on every iteration after the first:)
   
   Some notes:
   hcount - used to accumulate the total number of structure entered;
   scanf() - Reads the char/int entered by the user; 
   break - immediately exits from the loop if the response is negative;
   struct horse My_horses[50] - This creates the potential for the program to read in data for up to 50 horses
   How to clear input buffer in C? https://stackoverflow.com/questions/7898215/how-to-clear-input-buffer-in-c
   
   ************************************************************
   output:

	Who is faisca mother? mimosa
	Do you want to enter details of another  horse (Y or N)? y
	
	Enter the name of the horse: trovao
	
	How old is trovao: 10
	
	How high is trovao: 1.8
	
	Who is trovao father? track
	
	Who is trovao mother? malhada
	Do you want to enter details of another  horse (Y or N)? n
	
	
	faisca is the name of your horse;
	It is 12 years old;
	Its high is 1.50 hands high;
	Its father is relampago;
	Its mother is mimosa.
	
	trovao is the name of your horse;
	It is 10 years old;
	Its high is 1.80 hands high;
	Its father is track;
	Its mother is malhada.
	--------------------------------
	Process exited after 58.61 seconds with return value 0
	
   ************************************************************
   
   Author: Ivor Horton
   Edited: J3
   Date: Jun, 2021
*/

int main(int argc, char *argv[]) {
	
	struct horse 
	{
		int age;
		float height;
		char name[20];
		char father[20];
		char mother[20];
	};
	
	struct horse My_horses[50];
	int hcount = 0;
	char test = '\0';
	
	for(hcount = 0; hcount < 50; hcount++)
	{
		int c;
		printf("Do you want to enter details of a%s horse (Y or N)? ", hcount?"nother " : "");
		scanf(" %c", &test);
		if(tolower(test)=='n') break;

		printf("\nEnter the name of the horse: ");
		scanf("%s", &My_horses[hcount].name);              	// Read the horse's name
		while ((c = getchar()) != '\n' && c != EOF) { }    	// clears input buffer 
		
		printf("\nHow old is %s: ", My_horses[hcount].name);
		scanf("%d", &My_horses[hcount].age);              	// Read the horse's age
		while ((c = getchar()) != '\n' && c != EOF) { } 	// clears input buffer
		
		printf("\nHow high is %s: ", My_horses[hcount].name);
		scanf("%f", &My_horses[hcount].height);          	// Read the horse's age
		while ((c = getchar()) != '\n' && c != EOF) { }  	// clears input buffer
		
		printf("\nWho is %s father? ", My_horses[hcount].name);
		scanf("%s", &My_horses[hcount].father);          	// Read the horse's father
		while ((c = getchar()) != '\n' && c != EOF) { }  	// clears input buffer
		
		printf("\nWho is %s mother? ", My_horses[hcount].name);
		scanf("%s", &My_horses[hcount].mother);         	// Read the horse's mother
		while ((c = getchar()) != '\n' && c != EOF) { } 	// clears input buffer
	}
	
	/* Now tell them what we know */
	for (int i = 0; i < hcount; i++)
	{
		printf("\n\n%s is the name of your horse; \nIt is %d years old; \nIts high is %.2f hands high; \nIts father is %s; \nIts mother is %s. ", 
		My_horses[i].name, My_horses[i].age, My_horses[i].height, My_horses[i].father, My_horses[i].mother);
	}
	
	return 0;
}
