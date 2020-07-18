/*
  Project 52 - 2D Matrix - Pointer use to save memory
  
  Description:
  This program shows how we should use pointers in C;
  Use 1-D Matrix instead of 2-D matrix. See how...
  
  Topics:
	1) Storing a collection of strings at a time using the two-dimensional array.
	2) A disadvantage of using the two-dimensional array.
	3) An alternative method of storing the strings using a one-dimensional array of pointers.
  Notes:
    1) You have to specify the numbers of collumns; there's no problem if you won't specify the 
	   numbers of rows;
	2) Using 2-D arrays a lots of memory space is simply wasted
	   | 2 |   | P | i | n | e | a | p | p | l | e | \0 |
	   | 2 |   | A | p | p | l | e | s | \0 | \0 | \0 | \0 | 
                                          *    *    *        (3/24 lost memory spaces :/
    3) Solution: unisng pointer
         | 2 |   | P | i | n | e | a | p | p | l | e | \0 | 2 |   | A | p | p | l | e | s | \0 |
		                                                      (0/21 lost memory space :) 
		   ^                                                ^
	  *fruits[0][0]                                     *fruits[0][1]    
	        
**************************************************
Output:
2 Apples are lesser than 3 Bananas

************************************************** 
  Inspiration: Neso Academy 
              (Array of Strings - https://youtu.be/AefKSoNpZtQ)
  Edited by J3  
  Date: Jul, 18/2020
*/

#include <stdio.h>
#include <string.h>

int main()
{
	//char fruits[][12] = {"2 Oranges", "2 Apples", "3 Bananas", "1 Pineapple"};
	char *fruits[] = {"2 Oranges", "2 Apples", "3 Bananas", "1 Pineapple"};
	
	if (strcmp(fruits[1], fruits[2]) < 0)
		printf("%s are lesser than %s", fruits[1], fruits[2]);
		
	else if(strcmp(fruits[1], fruits[2]) > 0)
		printf("%s are greater than %s", fruits[1], fruits[2]); 
	
	//system("pause");
	return 0;
}

