
/* Project 70
   Title:  Multiple indirection with integers

   This program show:
 
   How to use pointer of pointer in C Language.

   let's see how I can access those values using both simple indirection that is using a pointer to

   an integer and multiple indirection, using a pointer to a pointer to an integer.

   I warn you in advance that simple as this may seem, you probably need to stare at this quite a while

   in order to understand what's going on:)

   ***************************** 
    Output:
  
    multiple indirection example
    0
    1
    2
    array address is 4225568
    item pointed to by pi is 0
    item pointed to by ppi is 4225568
    item pointed to by double indirection of ppi is 0

    The address of pi is 6487552 and the value of ppi (what it points to) is 6487552

    array address is 4225568
    item pointed to by pi is 1
    item pointed to by ppi is 4225572
    item pointed to by double indirection of ppi is 1

    The address of pi is 6487552 and the value of ppi (what it points to) is 6487552

    array address is 4225568
    item pointed to by pi is 2
    item pointed to by ppi is 4225576
    item pointed to by double indirection of ppi is 2

    The address of pi is 6487552 and the value of ppi (what it points to) is 6487552

    ***************************** 

  Author: Huw Collingbourne
  Edited: j3
   Udemy: Advanced C Programming: Pointers
    link: https://www.udemy.com/course/advanced-c-programming-pointers
    date: jun, 11/2021

*/



#include <stdio.h>

#define LENGTH 3

int data[LENGTH];	    // some integers

int main(int argc, char **argv) {
	int *pi;			// a simple pointer to an integer
	int **ppi;			// a pointer to a pointer to an integer

	printf("multiple indirection example\n");

	// initialize our integer array
	for (int i = 0; i < LENGTH; i++) {
		data[i] = i;
	}
	for (int i = 0; i < LENGTH; i++) {
		printf("%d\n", data[i]);
	}

	/*
	* A: simple pointer to a pointer to an integer
	*
	*/
	pi = data;			// set the pointer to an integer  to the start of the data array
	
	ppi = &pi;			// and set the pointer to a pointer to pi itself
	                    // The asterisk(*), which is sometimes called the  
						// deferencing operator or the indirection operator, 
						// gives me access to the data it is stored at that address
	                    // Remember: (&) gives me reference to an address
                        //           (*) gives me access    to the data 

	for (int i = 0; i < LENGTH; i++) {
		printf("array address is %d\n", data);
		printf("item pointed to by pi is %d\n", *pi);
		printf("item pointed to by ppi is %d\n", *ppi);
		printf("item pointed to by double indirection of ppi is %d\n\n", **ppi);
		printf("The address of pi is %d and the value of ppi (what it points to) is %d\n\n", &pi, ppi);

		pi += 1;		// advance the pointer to point to the next element of the data array
	}

	return 0;
}
