/* Project 16  -- QUICK SORT (Descendant Algorithm)
    
    Quicksort is an in-place sorting algorithm. 
	Developed by British computer scientist Tony Hoare in 1959 
	and published in 1961, it is still a commonly used algorithm for sorting. 
	When implemented well, it can be somewhat faster than merge sort 
	and about two or three times faster than heapsort. (WIKIPEDIA)
	
	Inventor: Tony Hoare
	Worst complexity: n^2
	Average complexity: n*log(n)
	Best complexity: n*log(n)
	Method: Partitioning
	Stable: No
	Class: Comparison sort
    
    Features:
       
    1- Pivot: 
    2- Compare values in the Right and Left position about the pivot
    3- Recursive
    
    TIME Comparing 100,000 Vector size:
    ____________________
    BUBBLE        QUICK
    __________  ________
    38.461000   0.028000
    ____________________
    
    ********************************************************************************
	Output

	QUICK SORT (Descendant)
	NOT ORDERED VECTOR:
	61      50      38      14      70      64      18      93      16      18
	ORDERED VECTOR:
	93      70      64      61      50      38      18      18      16      14
	Pressione qualquer tecla para continuar. . . 
    *********************************************************************************
    Based on: https://github.com/borinvini
	   
	UNINTER - Curso: Engenharia da Computacao
	Escola Superior Politecnica
	Author: Gilberto Jr RU 3326662 
	Edited: J3
	
	Date: Dec, 2021
	
	Please, watch the gif in this directory >         quick_ascending.gif
	                               And  see > quick_sort_step_by_step.png
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTORSIZE 10

void quicksort(int vet[], int p, int u);
int partition(int vet[], int p, int u);
void swap(int vet[], int i, int j);

int main()
{
	int vet[VECTORSIZE] = { 0 };
	srand(time(NULL));

	for (int i = 0; i < VECTORSIZE; i++)
		vet[i] = rand() % 100;

    	printf("QUICK SORT (Descendant)\n");
	printf("NOT ORDERED VECTOR:\n");
	for (int i = 0; i < VECTORSIZE; i++) // Print NOT ORDERED VECTOR
		printf("%d\t", vet[i]);

	quicksort(vet, 0, VECTORSIZE - 1);

	// Print resultants
	printf("\nORDERED VECTOR:\n");
	for (int i = 0; i < VECTORSIZE; i++) // Print ORDERED VECTOR
		printf("%d\t", vet[i]);
    	printf("\n");
	system("pause");
	return 0;
}

void quicksort(int vet[], int p, int u)
{
	int m;
	if (p < u)
	{
		m = partition(vet, p, u);
		quicksort(vet, p, m);
		quicksort(vet, m + 1, u);
	}
}

int partition(int vet[], int p, int u)   // Find pivot, scan and swap
{
	int pivo, pivo_pos, i, j;

	pivo_pos = (p + u) / 2;
	pivo = vet[pivo_pos];

	i = p - 1;
	j = u + 1;
	while (i < j)
	{
		do                               
		{
			j--;
		} while (vet[j] < pivo);         // change the signs at that point

		do                               
		{
			i++;
		} while (vet[i] > pivo);         // change the signs at that point

		if (i < j)
			swap(vet, i, j);
	}
	return j;
}

void swap(int vet[], int i, int j)
{
	int aux;
	aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}
