/*
  Project 47 - How to add 2 Matrices
  
  Description
  
  This program simply asks for iquals m1 and m2 matrices
  then sum them up.
  It checks if the Rows and Columns of each matrices is equal:)
  If not, it presents a error message. 
  Otherwise, it proceeds to add operation.
  
***********************************************************
Output:

Please enter the number of rows of the first matrix:
2
Please enter the number of collumns of the first matrix:
2
Please enter the number of rows of the second matrix:
2
Please enter the number of collumns of the first matrix:
2
Please, enter the elements of the first matrix
2 2
2 2
Here is the first matrix:
2       2
2       2
Please, enter the elements of the second matrix
2 2
2 2
Here is the second matrix:
2       2
2       2


Here is the resultant addition matrix:
4       4
4       4 
***********************************************************
  
  Inspiration 
  
  PRABEESH R K (https://youtu.be/t3HZcNN09KU)
  Edited by J3
  
  Date: Jul, 16/2020
*/


#include <stdio.h>


int main()
{
	int r1, c1, r2, c2;

	
	printf("Please enter the number of rows of the first matrix: \n");
	scanf("%d", &r1);

	printf("Please enter the number of collumns of the first matrix: \n");
	scanf("%d", &c1);
	
	printf("Please enter the number of rows of the second matrix: \n");
	scanf("%d", &r2);

	printf("Please enter the number of collumns of the first matrix: \n");
	scanf("%d", &c2);
	
	
	if(r1 == r2 && c1 == c2)
	{
		/* Inside if scope, declaring the matrices */
		int m1[r1][c1]; 
	    int m2[r2][c2];
	    int r[r2][c2];
		int i, j;
			    
		printf("Please, enter the elements of the first matrix\n");
		for(int i = 0; i < r1; i++ )
		{			
			for(j = 0; j < c1; j++)
			{
				scanf("%d", &m1[i][j]);		
			}
			
		}
		printf("Here is the first matrix:\n");		
	    for(i = 0; i < r1; i++ )
		{
			for(j = 0; j < c1; j++)
			{
				printf("%d\t", m1[i][j]);
			}
			printf("\n");
		}
		
		printf("Please, enter the elements of the second matrix\n");
		for(i = 0; i < r2; i++ )
		{			
			for(j = 0; j < c2; j++)
			{
				scanf("%d", &m2[i][j]);		
			}
			
		}
		printf("Here is the second matrix:\n");		
	    for(i = 0; i < r2; i++ )
		{
			for(j = 0; j < c2; j++)
			{
				printf("%d\t", m2[i][j]);
			}
			printf("\n");
		}
		/* Proceeding to addition operation */
	    for(i = 0; i < r2; i++ )
		{
			for(j = 0; j < c2; j++)
			{
				r[i][j] = m1[i][j] + m2[i][j];
			}
			printf("\n");
		}
		printf("Here is the resultant addition matrix:\n");	
		
		for(i = 0; i < r2; i++ )
		{
			for(j = 0; j < c2; j++)
			{
				printf("%d\t", r[i][j]);
			}
			printf("\n");
		}	
		
		
    }
	else
	{
		printf("Error: The number of rows and columns must be the same:/\n");
	}

	//system("pause");
	return 0;
}
