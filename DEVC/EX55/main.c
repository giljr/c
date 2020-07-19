/*
 Project 55 - 3-D Matrix - How to Access it with a Triple Loops
 
 Description:
 This program simple plays with a 3-Dimentianal matrix:)
 
*********************************
Output:
1       2       3
4       5       6
7       8       9

10      11      12
13      14      15
16      17      18

19      20      21
22      23      24
25      26      27

*********************************

 Inspiration & Credits to:
   Introduction to Three-Dimensional (3D) Arrays
   Neso Academy (https://youtu.be/bbkdiUbou74)
 
 Edited by J3
 Date: Jul, 19/2020
*/

#include <stdio.h>

#define ROW  3
#define COLUMN	3

int main()
{
	/* Declaring a 3-D Matrix */
	int mtx[ROW][COLUMN][COLUMN] = 
	{
		{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} },
		{ {10, 11, 12}, {13, 14, 15}, {16, 17, 18} },
		{ {19, 20, 21}, {22, 23, 24}, {25, 26, 27} }
	};
	
	/* Printing a 3-D Matrix  - triple loops */
	int i, j, k;
	for(i = 0; i < ROW; i++)
	{
		for(j = 0; j < COLUMN; j++)
		{
			for(k=0; k < COLUMN; k++)
			{
				printf("%d\t", mtx[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	//system("pause");
	return 0;
}
