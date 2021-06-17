/*
Project 75
      
   This program shows how to use recursion to find the minimum 
   and the maximum numbers from an given array. 
  
   Practice Exercise nº 4:
   
   Write in C language an algorithm that:
   1) Ask the user to enter their RU;
   2) Store each RU digit in a position of a vector;   
   3)Using a recursive function show what is the value of the smallest digit entered in the vector;
   4) Using another recursive function show which value of the largest digit entered in the vector.
   
   To demonstrate the operation use your RU as input to the algorithm.
   ************************************************************
   output:

	Enter size of the array: 7
	Enter your 7 Uninter RU Number: 3
	3
	2
	6
	6
	6
	2
	Minimum element in array = 2
	Maximum element in array = 6
	
	--------------------------------
	Process exited after 17.58 seconds with return value 0
	
   ************************************************************
   
   Author: Gilberto Oliveira Junior RU 3326662
   Edited: J3
   Date: Jun, 2021
*/

#include <stdio.h>
#define maxsize 100 

/*  Prototypes Functions declaration */
int maximum(int array[], int index, int len);
int minimum(int array[], int index, int len);

int main()
{
    int array[maxsize], N, max, min;
    int i;

    /* Input size and elements of array */
    printf("Enter size of the array: ");
    scanf("%d", &N);
    
    /* storing values in an array dynamically */    
	printf("Enter your %d Uninter RU Number: ", N);    
	for(i=0; i<N; i++)
    {
        scanf("%d", &array[i]);
    }
    
    /* Calling each of the recursive functions */

    max = maximum(array, 0, N);
    min = minimum(array, 0, N);

    printf("Minimum element in array = %d\n", min);
    printf("Maximum element in array = %d\n", max);

    return 0;
}

/* Recursive Maximum function declaration */
int maximum(int array[], int index, int len)
{
    int max;

    if(index >= len-2)
        return (array[index] > array[index + 1])
                    ? array[index]
                    : array[index + 1];

    max = maximum(array, index + 1, len);

    return (array[index] > max)
                ? array[index]
                : max;
}

/* Recursive Minimum function declaration */ 
int minimum(int array[], int index, int len)
{
    int min;

    if(index >= len-2)
    {
        return (array[index] < array[index + 1])
                    ? array[index]
                    : array[index + 1];
    }

    min = minimum(array, index + 1, len);

    return (array[index] < min)
                ? array[index]
                : min;
}

