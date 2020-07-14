/*
  Project 42 - Matrices Multiplication
  
  Description
  This program calculates the multiplication of equal matrices.
  The matrices must be the same Row x Columns. (example: a[3][3] and b[3][3]).
  
  HowTo:
  (1) Declare matrices: int arr[5] or int arr[4][5]
  (2) Initialize matrices: int[2][3] = {1,2,3,4,5,6} or int[2][3] = {{1,2,3},{4,5,6}}
  (3) Access matrices: a[0][1]
  (4) a- With a Single Loop: 
            int a[5] = {1,2,3,4,5};
			for (int i=0; i<5; i++)
			{
			  printf("%d", a[i]);
		    }
		    
	   b- With a Double loop:            
	        int b[2][3] = {1,2,3},{4,5,6}};
			for (int i=0; i<2; i++)
			{ 
			   for (int j=0; j<3; j++)
			   {
			     printf("%d", b[i][j]);
			   }			  
		    }
	        
****************************************************
Output1:

Enter the rows and columns of matrix a: 3 3
Enter the elements of matrix a:
1 2 3
1 2 1
3 1 2
Enter the rows and columns of matrix b: 3 3
Enter the elements of matrix b:
1 2 3
1 2 1
3 1 2
Resultant Matrix:
12      9       11
6       7       7
10      10      14

Output2:

Enter the rows and columns of matrix a: 1 7
Enter the elements of matrix a:
1 2 3 4 5 6 7
Enter the rows and columns of matrix b: 7 1
Enter the elements of matrix b:
1
2
3
4
5
6
7
Resultant Matrix:
140
****************************************************
 
 From : Neso Academy
 		https://youtu.be/jzdQqoG1tZs
 
 Date: Jul, 13/2020

*/
#include <stdio.h>
#define MAX 50

int main()
{
	int a[MAX][MAX], b[MAX][MAX], product[MAX][MAX];
	int arows, acolumns, brows, bcolumns;
	int i,j,k;
	int sum = 0;
	
	/* Part 1 - Asking the user to enter the first matrix */
	printf("Enter the rows and columns of matrix a: ");
	scanf("%d %d", &arows, &acolumns);
	
	printf("Enter the elements of matrix a:\n");
	for(i = 0; i < arows; i ++)
	{
		for(j=0; j<acolumns; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	
	/* Part 1 - Asking the user to enter the second matrix
	            but before check if the extremes are equal */
	printf("Enter the rows and columns of matrix b: ");
	scanf("%d %d", &brows, &bcolumns);

	if(brows != acolumns)
	{
		printf("Sorry, we cannot multiply the matrices a and b \n");
	}
	else 
	{
		printf("Enter the elements of matrix b:\n");
		for(i=0; i<brows; i++)
			{
				for(j=0; j<bcolumns; j++)
					{
						scanf("%d", &b[i][j]);
					}	
		 	}
	}
	
	//printf("\n");
		
	for (i=0; i<arows; i++)
		{	
			for(j=0; j<bcolumns; j++)
			{
				for(k=0; k<brows; k++)
				{
					sum += a[i][k] * b[k][j];
				}
				product[i][j] = sum;
				sum = 0;
		}
	}
		
	// printing the array
	printf("Resultant Matrix:\n");
	for( i=0; i<arows; i++ )
	{
		for(j=0; j<bcolumns; j++)
		{
			printf("%d\t", product[i][j]);
		}
		
		printf("\n");
	}
	//system("pause");
	return 0;
}
