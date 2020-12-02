/* 
POINTERS:

POINTERS POINTS TO AN ADDRESS.

A pointer is a variable whose value is an address in memory.

The address is a location in memory (where some data may be stored).

The value of a pointer that indicates a specific memory location.

'Indirection' means accessing data stored at the address given by a pointer.

'Dereferecing' is another term used to describe indirection. 

When you dealing w/ arrays you are dealing w/ addresses and
you will be using pointers.

Arrays in C are actually just a SEQUENTIAL OF ITEMS stored in 
some location in memory.

The ADDRESS OF AN ARRAY is the same as the address of the 
FIRST ITEM IN THE ARRAY because it is where the array begins.

Again, the NAME OF THE ARRAY is also the address of the array.

Once more, the address of an array is THE SAME AS THE FIRST ITEM IN 
THE ARRAY because it's where the array begin.

The NAME OF THE ARRAY is also the address of the array.

The C LANGUAGE adds '/0' NULL CHAR to the END OF THE ARRAY.
It is called STRING TERMINATOR.

In order to access the data at an address given by a pointer, 
you need to use the indirection or dereferecing operator.

BTW, put these symbols in the right of your attribution expression:
If you use & (Ampersand) = ADDRESS-OF OPERATOR - it returns THE 
ADDRESS IN MEMORY at which that value is stored.

If you use * (Asterisk) = DEREFERENCE OPERATOR - or 
INDIRECTION OPERATOR, it gives me access TO THE DATA it is 
stored at that address. This is called "dereferencing" the pointer.

Summary for the code below:

The code asks for:

&str1 , str1[0], str1, str1
&str2 , str1[0], str2, str2
  %d  ,   %d,      %d,  %s   

****************************
OUTPUT:

6487568 6487568 6487568 Hello
6487560 4210688 4210688 Goodbye

*****************************

MEMORY MAP:
--------+------------------------+--------+---------------------------------+---+-------------------------
 DSC    |    ARRAY               |  ...   |          ARRAY                  |...|  POINTER TO 'GOODBYE'
--------+------------------------+--------+---------------------------------+---+-------------------------
		|                        |        |                                 |   |
DATA    |'H' 'E' 'L' 'L' 'O' '/0'|  ...   |'G' 'O' 'O' 'D' 'B' 'Y' 'E' '/0' |...| 4210688
		| ^                      |        | ^                               |   |
NAME    | 6487568                |  ...   | 4210688                         |...| 'str2'
ADDRESS | 6487568                |  ...   | 4210688 (DOES NOT MATTER)       |...| 6487560
		| (Array is an address)  |        | ('cause we have a pointer here) |   |
--------+------------------------+--------+---------------------------------+---+-------------------------

*Data (of an Array is the chain of chars terminated by `/0`)
*Data (of a Pointer is a number that may be storing an address)

*Name (of an Array is the number of the pointer of the first character)
*Name (of a pointer is the name of the variable itself)

*Address (of an Array is the address of the first char)
*Address (of a pointer is a number)

Remember: (&) Address-of  (gives me address) 
          (*) Dereference (gives me data)

Credits: Huw Collingbourne - Director of Technology, SapphireSteel Software
Udemy Course: https://www.udemy.com/course/advanced-c-programming-pointers/

Editor: J3
Date: Dez, 2020
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char str1[] = "Hello";
	char *str2  = "Goodbye";
	
	printf("%d %d %d %s\n", &str1, &str1[0], str1, str1);
	printf("%d %d %d %s\n	", &str2, &str2[0], str2, str2);
	
	return 0;
}
