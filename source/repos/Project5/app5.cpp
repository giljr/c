/*
  Using Vectors

  An array (vector) is a common-place data type, used to hold and describe 
  a collection of elements. These elements can be fetched at runtime by one 
  or more indices (identifying keys)

  Description:
  The system will accept user input and store the numbers in a vector.
  Then it will show all the elements in the vector in order and 
  then in the inverse order.

  Iteration statements
  The iteration statements repeatedly execute a statement
  for ( init_clause ; expression(optional) ; expression(optional) ) statement(1)

  Author: Borin (https://br.linkedin.com/in/borinvini)
  Edited by j3
  date: jun, 12/2020
*/

#include<stdio.h>
#include<stdlib.h>

#define VECTOR_SIZE 5

int main()
{
	int vec[VECTOR_SIZE] = { 0 };

	// Scanning the vector w/ for loop
	for (int i = 0; i < (VECTOR_SIZE); i++)
	{
		printf("Please enter the number at position %d :", i);
		scanf_s("%d", &vec[i]);
	}
	// Displaying the vector  w/ for loop
	printf("Displaying  the Vector of size %d:\n ", VECTOR_SIZE);
	for (int i = 0; i < (VECTOR_SIZE); i++)
	{
		printf("%d\t", vec[i]);	
	}
	// Displaying the vector  inverted w/ for loop
	printf("\nDisplaying  the Vector inverted: \n");
	for (int i = (VECTOR_SIZE - 1); i >= 0; i--)
	{
		printf("%d\t", vec[i]);
	}


	//system("pause");
	return 0;

}
