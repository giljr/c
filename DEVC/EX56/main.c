/*
  Project 56 - String Copy, String Concat & Malloc in C
  
  Description:
  This program demostrate the use of malloc + strcpy + strcat;
  
  The system asks for 5 array of strings;
  then it stores array by array in a array of 5 elements
  where each element in the array is of type character pointer.
  Confused? Read on!
  
  What is de diff?
  char *message     -> message points to a character
  char* messages[5] -> messages is an array of 5 elements
                       where each element in the array is
                       of type character pointer.
                       
 Here is the essence of the algorithm: 
  ----------  ----------------------     --------------------------                     
     Array    Address representation     Memory at random position
  ---------   ----------------------     --------------------------
     Seq        Mem     _char*_          ...points to these adds...
		        _______	            ____________________
  messages[0]   200    | 1000 | ----->1000 | o | n | e | \0 |   |
  messages[1]   201    | 1556 | -------              _____________________
  messages[2]   202    | 2012 |  ---    ------>1556 | t | w | o | \0 |   |
  messages[3]   203    |   ?  |    |           _____________________
  messages[4]   204    |   ?  |    ------>2012 | f | o | u | r  |\0 |

*********************************************************************
Output:

Enter the string: This
messages[This]
Enter the string: is
messages[is]
Enter the string: a
messages[a]
Enter the string: malloc
messages[malloc]
Enter the string: demo
messages[demo]

Total Characters = 17
Total Memory allocated = 18
Printing all strings concatenated by strcat():
This is a malloc demo
All the memory used by malloc is now released!!!
Do not forget the free method of malloc!!!

*********************************************************************
  Inspiration & Credits:
  BestDotNetTraining
  Array of String in C Programming language 
  ( https://youtu.be/pB-nvbCg3yc )
  
  Edited by J3
  Date: Jul, 19/2020
  
 
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
	char* messages[5] = {"one", "two", "four"};
	char* allstrings;
	int i;
	int total = 0;
	for(i = 0; i < 5; i++)
	{
		printf("Enter the string: ");
		
		/* If you forget to alloc mem, the program will crash :/ */
		messages[i]= (char*)malloc(10);
		
		scanf("%s", messages[i]);
		
		printf("messages[%s]\n", messages[i]);
		
		total += strlen(messages[i]);
		
	}
	printf("\nTotal Characters = %d\n", total);	
	
	/* Concatenating the strings */
	allstrings = (char*)malloc(total+1);
	
	printf("Total Memory allocated = %d\n", total+1);
	
	/* Using string copy to save each arrays to allstring variable */
	strcpy(allstrings, messages[0]);
	
	/* Finally, cancatenating (strcat) the string, first one must be set previously */
	for(i = 1; i < 5; i++)
	{
		strcat(allstrings, " ");
		strcat(allstrings, messages[i]);
	}
	printf("Printing all strings concatenated by strcat():\n");
	printf("%s\n", allstrings);
	
	/* Deallocating the memories - This is critical! */
	free(allstrings);
	for(i = 0; i < 5; i++)
		free (messages[i]);
	printf("All the memory used by malloc is now released!!!\n");
	printf("Do not forget the free method of malloc!!!\n");
	
	//system("pause");
	return 0;
}
