/* Project 14  -- BUBBLE SORT (Descendant Algorithm)
    
    This algorithm works by repeatedly SWAPPING the 
    ADJACENT ELEMENTS if they are in wrong order.
    
    O(n^2)
    
    Features:
	
    
    1- Two loops: 
    	-external -> sweep vector size
    	-internal -> compares 2x2 and SWAP using Auxiliary Variable (aux)
        
        The 1st, Loops to vector size; the 2st, Loops from 1st to penultimate position
        and this chank of code is just SWAPPING the ADJACENT ELEMENTS: 

				aux = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = aux;

        if Ascendant or descendant just THIS SIGN change is necessary:

			    if (vec[i] < vec[i + 1])

    2- Based on: https://github.com/borinvini
	   
	UNINTER - Curso: Engenharia da Computacao
	Escola Superior Politecnica
	Author: Gilberto Jr RU 3326662 
	Edited: J3
	Date: Dec, 2021
	
	Please, watch the gif in this directory > buble_ascending.gif
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int vec[]);

#define VECTORSIZE 10

int main()
{
	int vec[VECTORSIZE] = { 0 };
	srand(time(NULL));

	printf("BUBBLE SORT (DES)\n");
	printf("-----------------\n");

	// Data insertion

	for (int i = 0; i < VECTORSIZE; i++)
		vec[i] = rand() % 100;

	printf("Not Ordered Vector:\n");
	for (int i = 0; i < VECTORSIZE; i++)
		printf("%d\t", vec[i]);

	BubbleSort(vec);

	// Print results
	printf("\nOrdered Vector:\n");
	for (int i = 0; i < VECTORSIZE; i++)
		printf("%d\t", vec[i]);


	printf("\n");
	system("pause");
	return 0;
}

void BubbleSort(int vec[])
{
	int aux;
	for (int n = 1; n <= VECTORSIZE; n++)
	{
		for (int i = 0; i < (VECTORSIZE - 1); i++)
		{
			if (vec[i] < vec[i + 1]) // CHANGE HERE!
			{
				aux = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = aux;
			}

		}

	}

}