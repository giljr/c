/*
  Project 51 - How To Declare a Matrix of Char (How to clear input buffer)
  
  Description:
  This program simply asks for the matrix size (must be in the range 1-10);
  Then displays the matrix entered by the user.
  
  What made it more difficult was learning How to clear input buffer in C;
  Please, pay attention to this shunk of code:
  
  while((c = getchar()) != '\n' && c != EOF){};
  
*****************************************************
Output:

Please, enter the matrix size:
3
Please, enter each value of the matrix, index 0,0 :a
Please, enter each value of the matrix, index 0,1 :b
Please, enter each value of the matrix, index 0,2 :c
Please, enter each value of the matrix, index 1,0 :d
Please, enter each value of the matrix, index 1,1 :e
Please, enter each value of the matrix, index 1,2 :f
Please, enter each value of the matrix, index 2,0 :g
Please, enter each value of the matrix, index 2,1 :h
Please, enter each value of the matrix, index 2,2 :i

Printing the matrix in the screen:
a       b       c
d       e       f
g       h       i

*****************************************************
  
  For more info:
  How to clear input buffer in C?
  https://stackoverflow.com/questions/7898215/how-to-clear-input-buffer-in-c
  
  Edited by J3
  Date: Jul, 18/2020
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int LINE;
int COLUMN;
int c, i, j;
char mtx[10][10];
	

int main()
{
    int size = 0;
	printf("Please, enter the matrix size: ");
	scanf("%d", &size);
	
	while ( size > 10 || size == 0)
	{		
		while((c = getchar()) != '\n' && c != EOF){};
		printf("Please, the matrix size must be in the range of 1-10: ");
	    	scanf("%d", &size);	    	
	}
    
	LINE = size;
    	COLUMN = size;

	for (i = 0; i < LINE; i++)
	{

		for (j = 0; j < COLUMN; j++)
		{
		    	mtx[size][size];
			while((c = getchar()) != '\n' && c != EOF){};
			printf("Please, enter each value of the matrix, index %d,%d :", i, j);
			scanf_s("%c", &mtx[i][j]);			
		}		

	}
	// Displaying the Matrix in the screen
	printf("\nPrinting the matrix in the screen:\n");
	for (i = 0; i < LINE; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			printf("%c\t", mtx[i][j]);
		}
		printf("\n");			
	}

	//system("pause");
	return 0;
}

