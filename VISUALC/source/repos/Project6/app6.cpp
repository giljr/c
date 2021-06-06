/*
  Using Matrices

  Matrices is the plural of matrix.
  Matrix is an arrangement of numbers into rows and columns.

  Description:
  The system will accept user input at each index of the matrix
  and store these numbers in a matrix arrangement 3x3.
  Then it will show all the elements of the matrix in the screen
  then display the Main diogonal of the matrix too :)

  Iteration statements
  The iteration statements repeatedly execute a statement
  for ( init_clause ; expression(optional) ; expression(optional) ) statement(1)

  author: Borin (https://br.linkedin.com/in/borinvini) 
  Edited by j3
  date: jun, 13/2020
*/

#include<stdio.h>
#include<stdlib.h>

#define LINE	3
#define COLUMN	3

int main()
{
	//Declaring the matrix and init each element as zero
	int mtx[LINE][COLUMN] = { 0 };

	// Repetition statement w/ 2 for loops (one 4 Ln and other 4 Cl)
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			printf("Please, enter each value of the matrix, index %d,%d :", i, j);
			scanf_s("%d", &mtx[i][j]);
		}

	}
	// Displaying the Matrix in the screen
	printf("Printing the matrix in the screen:\n");
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			printf("%d\t", mtx[i][j]);
		}
		printf("\n");
	}

	// Displaying the Main diagonal
	// The main diagonal of a matrix consists of those 
	// elements that i is igual to  j :)
	printf("Printing the matrix 'Main diagonal':\n");
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if (i == j)
			{
				printf("%d\t", mtx[i][j]);
			}
		}
	}

	//system("pause");
	return 0;
}


