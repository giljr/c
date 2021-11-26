/* Project 83  -- BUBBLE SORT (Ascendant Algorithm)
    
    This algorithm works by repeatedly SWAPPING the 
    ADJACENT ELEMENTS if they are in wrong order.
    
    O(n^2)
    
    Features:
	
    
    1- Two loops: 
    	-external -> sweep vector size
    	-internal -> compares 2x2 and SWAP using Auxiliary Variable (aux)
    	
    Based on: https://github.com/borinvini
	   
	UNINTER - Curso: Engenharia da Computacao
	Escola Superior Politecnica
	Author: Gilberto Jr RU 3326662 
	Edited: J3
	Date: Nov, 2021
	
	Please, watch the gif in this directory > buble_ascending.gif
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int vet[]);

#define VECTORSIZE 10

int main()
{
	int vec[VECTORSIZE] = { 0 };
	srand(time(NULL));

	// Data insertion
	for (int i = 0; i < VECTORSIZE; i++)
		vec[i] = rand() % 100;
	
	printf("BUBBLE SORT (Ascendant)\n");

	printf("NOT ORDERED VECTOR:\n");
	for (int i = 0; i < VECTORSIZE; i++)           //print NOT ORDERED VECTOR
		printf("%d\n", vec[i]);

	BubbleSort(vec);

	// Print resultants
	printf("ORDERED VECTOR:\n");
	for (int i = 0; i < VECTORSIZE; i++)           // print ORDERED VECTOR
		printf("%d\n", vec[i]);


	printf("\n");
	system("pause");
	return 0;
}

void BubbleSort(int vec[])
{
	int aux;
	for (int n = 1; n <= VECTORSIZE; n++)          // 1st Loop to vector size
	{
		for (int i = 0; i < (VECTORSIZE - 1); i++) // 2st Loop from 1st to penultimate position
		{
			if (vec[i] > vec[i + 1])                 // SWAPPING the ADJACENT ELEMENTS
			{
				aux = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = aux;
			}

		}

	}

}
