
/*
  Project 49 - Matriz manipulation in the extreme "/
  
  Description
  
  This program asks for matrix size input initially;
  then it asks for matrix values;
  display matrix with letter; Converts it to integers;
  and, finally shows how to use pointers to scan a matrix.
  
  
******************************************************************
Output:

Please, enter the matrix m0[i][j] size: 2
We'll populate it with ASCII letter from 97:
Here is the matrix: m0[2] x [2]
a       b
c       d

Please enter 4 elements for m1[2][2]:
Enter value for m1[0][0]:1
Enter value for m1[0][1]:2
Enter value for m1[1][0]:3
Enter value for m1[1][1]:4

Here is the 4 elements entered for m1[2][2]:
1       2
3       4

Matrix m2[5][4] is populated by letters elements:
a       b       c       d
e       f       g       h
i       j       k       l
m       n       o       p
q       r       s       t

Converting Matrix m2[5][4] to integers:
97      98      99      100
101     102     103     104
105     106     107     108
109     110     111     112
113     114     115     116

Using Pointer to scanning a matrix m3[3][3]:
m3[0][0] = 1
m3[0][1] = 2
m3[0][2] = 3
m3[1][0] = 4
m3[1][1] = 5
m3[1][2] = 6
m3[2][0] = 7
m3[2][1] = 8
m3[2][2] = 9
******************************************************************
  Edited by J3
  Date Jul, 17/2020
*/
#include <stdio.h>

char letter1;
char letter2;
int res;
int size = 10;
int i, j, k;

char m0[10][10];

int main()
{
	printf("Please, enter the matrix m0[i][j] size: ");
	scanf("%i", &size);
	int y = size * size;
	
	printf("We'll populate it with ASCII letter from 97:\n");
	printf("Here is the matrix: m0[%i] x [%i]\n", size, size);
	int x = 97;
	
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			m0[i][j] = x;
			x++;		  		    		
		}			
	}
	
	/* Printing */
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			printf("%c\t", m0[i][j]);		  		    		
		}
		printf("\n");			
	}
	
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			for(k = 0; k < size; k++)
			{
				m0[i][j];			
			}		  		    		
		}			
	}
	
	printf("\nPlease enter %d elements for m1[%d][%d]:\n", y, size, size);	
/* 2D array declaration*/

/* 2D array declaration*/
int m1[size][size];
/* Counter variables for the loop */
int i, j;

for(i=0; i<size; i++) 
{

  for(j=0;j<size;j++) 
  {
     printf("Enter value for m1[%d][%d]:", i, j);
     scanf("%d", &m1[i][j]);
  }
}

/* Displaying array elements */
printf("\nHere is the %d elements entered for m1[%d][%d]:\n", y, size, size);
for(i=0; i<size; i++) 
{
  for(j=0;j<size;j++) 
  {
     printf("%d\t", m1[i][j]);
  }
  printf("\n");
}

/* Populating a matrix with letters */
printf("\nMatrix m2[5][4] is populated by letters elements:\n");
char m2[5][4] ={
        {'a','b','c','d'},
        {'e','f','g','h'},
        {'i','j','k','l'},
        {'m','n','o','p'},
        {'q','r','s','t'}
        };

 for (int i=0; i<5; i++)
{
	for(j=0; j<4; j++)
	 {
		printf("%c\t",m2[i][j]);
	}
  printf("\n");
} 
  
/* Converting a matrix for integers */
printf("\nConverting Matrix m2[5][4] to integers:\n");     

for (int i=0; i<5; i++)
{
	for(j=0; j<4; j++)
	 {
		printf("%i\t",m2[i][j]);
	 }

   printf("\n");
}
/* Using pointers: */
/* To use pointer, just declare it and pointing it to initial address of matrix */
printf("\nUsing Pointer to scanning a matrix m3[3][3]:\n"); 
// 2d array
int m3 [3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, {7, 8, 9} };
/* Declaring the pointer to integer as NULL */
int *pointer = NULL;
/* Pointing the address of the initial value of matrix -> m3[0][0] */
/* You can also write *m3 */
pointer = &m3[0][0]; 
/* Loop of row */
for (i = 0; i < 3; ++i) 
{   /* Loop for column */
    for (j = 0; j < 3; ++j)
    {
        /*Read element of 2D array*/
        //printf("m3[%d][%d] = %d\n", i, j, *(pointer + ( i + j)));
        printf("m3[%d][%d] = %d\n", i, j, *pointer++);
		//printf("m3[%d][%d] = %d\n", i, j, *pointer);
        //pointer++;
    }
}

return 0;
}
