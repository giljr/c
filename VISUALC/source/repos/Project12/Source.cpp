/*
   Project 12 - Visual C++ 2019 - Exercise 3 - Homework - Frequency of Characters in a Matrix of Strings
   
   Description:

   Make an algorithm in C language that receives as input a matrix
   of characters. Each position in the array must store a character;
   The matrix dimension should be MxN, where M and N are chosen input data
   by the user. Declare the matrix as having a maximum size of 10x10, and validate the values
   M and N, which must be between 1 and 10, including 1 and 10. For validation, the user must
   get stuck in the program until you enter a valid number for M and N;
   After choosing the dimension of the matrix and populating it with characters:
   1) Count the number of occurrences of each character that appears in the matrix.
	  After counting, list each character entered and the number of occurrences;
   2) Create a function that receives the first registered character as a parameter
	  in the matrix. The function must return a numeric data. If the character is
	  uppercase, return the result of this character divided by 10 in the function.
	  Otherwise, return the result of the character multiplied by 2;

   Here is the output test:

***************************************************************
Output:

Please, enter the matrix dimension (number): 2
Thanks! Your matrix wil be mtx[2][2]:
Now populate the mtx[2][2].
Enter letter for index:
mtx[0][0]: G
mtx[0][1]: i
mtx[1][0]: l
mtx[1][1]: l

Printing the matrix in the screen:
G       i
l       l

The frequencies of characters in a matrix are:
G/g occurs 1 times.
I/i occurs 1 times.
L/l occurs 2 times.

Math Operation:
G is the First Character entered in the matrix and its numeric value is 71;
if we take 71 and divide by 10 we get 7.

***************************************************************
   Based: Projects 49, 51 & 58 :)

   Edited by J3
   Date: Jul, 20/2020
*/

#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>

int ROW;
int COLUMN;

int b;

int i, j;
char mtx[10][10];
int size = 0;
int c = 0, count[26] = { 0 }, x, sum;

/* prototype function */
int getFirstChar(int c);

int main()
{
	/* Ask for the Matrix dimension - Entering a number between 1 & 10 */
	printf("Please, enter the matrix dimension (number): ");
	scanf_s("%d", &size);

	while (size > 10 || size == 0)
	{
		while ((c = getchar()) != '\n' && c != EOF) {};
		printf("Please, the matrix size must be in the range of 1-10\n:");
		scanf_s("%d", &size);

	}

	ROW = size;
	COLUMN = size;

	printf("Thanks! Your matrix wil be mtx[%d][%d]:\n", size, size);
	printf("Now populate the mtx[%d][%d].\nEnter letter for index:\n", size, size);
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			mtx[size][size];
			while ((c = getchar()) != '\n' && c != EOF) {};
			printf("mtx[%d][%d]: ", i, j);
			scanf_s("%c", &mtx[i][j]);
		}

	}

	// Displaying the Matrix in the screen
	printf("\nPrinting the matrix in the screen:\n");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			printf("%c\t", mtx[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			/* Considering characters from 'a' to 'z' and 'A' to 'Z' */

			if (mtx[i][j] >= 'a' && mtx[i][j] <= 'z')
			{
				x = mtx[i][j] - 'a';
				count[x]++;
			}
			else
				if (mtx[i][j] >= 'A' && mtx[i][j] <= 'Z')
				{
					x = mtx[i][j] - 'A';
					count[x]++;
				}

		}

	}
	/** Calculating the frequency table */
	printf("\nThe frequencies of characters in a matrix are:\n");
	for (c = 0; c < 26; c++)

		if (count[c] != 0)
		{
			printf("%c/%c occurs %d times.\n", c + 'A', c + 'a', count[c]);
		}

	/* Testing requirement 2 above */
	printf("\nMath Operation:\n");
	printf("%c is the First Character entered in the matrix and its numeric value is %d;\n", mtx[0][0], mtx[0][0]);
	getFirstChar(mtx[0][0]);

	return 0;
}

/* Function to addressing requirement 2 above */
int getFirstChar(int c)
{
	if (isupper(c))
	{
		int r = c / 10;
		printf("if we take %d and divide by 10 we get %d.", c, r);
		return r;
	}
	else
	{
		int r = c * 2;
		printf("if we take %d and multiply by 2 we get %d.", c, r);
		return r;
	}

}