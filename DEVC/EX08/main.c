/*
 How to use NULL in C
 
 Description
 Initially we declare a NULL pointer (good practice!:)
 Then use a selection statement to see if it is NULL our not:)

 Several programming languages make use of the concept of null.
 Go has nil, JavaScript has null, Python has None, and so on.
 C has NULL.
 NULL however is used differently from other languages. 
 In C, NULL is limited to identifying a null pointer.

 When we initialize a pointer, we might not always know what it points to. 
 That is when NULL is useful :)
 
*******************************
 Output
 	The value of ptr is: 0
	Pointer is a null value
*******************************
 
 Author: https://flaviocopes.com/c-null/
 Edited by j3
 Date Jun, 20/2020
 
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int * ptr = NULL;
	//int i = 0;
	//ptr = &i;
	
	printf("The value of ptr is: %x\n", ptr);
	
	if (ptr)
		printf("Pointer is not a null value\n");
	if (!ptr)
		printf("Pointer is a null value\n");
	
	//system("pause");
	return 0;
}
