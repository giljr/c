/* Project 17  -- Linear Search Algorithm
    
    Sequential Search
    Sorting algorithm
    In computer science, a linear search or sequential search is a method 
	for finding an element within a list. It sequentially checks each 
	element of the list until a match is found or the whole list has been searched. 
	(Wikipedia)
	
	Worst complexity: O(n)
	Average complexity: O(n)
	Space complexity: O(1)
	Average performance: O(n/2)
	Class: Search algorithm
    
    Features:
       
    1- find an element within a list
    
    Based on: https://github.com/borinvini
	   
	UNINTER - Curso: Engenharia da Computacao
	Escola Superior Politecnica
	Author: Gilberto Jr RU 3326662 
	Edited: J3
	
	Date: Nov, 2021
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SequentialSearch(int vec[], int sought);

#define VECTORSIZE 10

int main()
{
	int vec[VECTORSIZE] = { 0 };
	int sought, found, i;
	srand(time(NULL));

	// Entering data
	for (int i = 0; i < VECTORSIZE; i++)
		vec[i] = rand() % 1000;
		
	printf("Sequential Search Algorithm\n");

	printf("Vector Generation:\n");
	for (int i = 0; i < VECTORSIZE; i++)
		printf("%d\t", vec[i]);

	printf("\nSelect a value to search: ");
	scanf_s("%d", &sought);

	found = SequentialSearch(vec, sought);

	if (found == -1)
		printf("\nValue not found. \n");
	else
		printf("Value found in the position %d. \n", found);

	system("pause");
	return 0;

}

int SequentialSearch(int vec[], int sought)
{
	int found, i;

	found = 0;
	i = 0;
	while ((i <= VECTORSIZE) && (found == 0))
	{
		if (vec[i] == sought)
			found = 1;
		else
			i++;
	}

	if (found == 0)
		return -1;
	else
		return i + 1;

}