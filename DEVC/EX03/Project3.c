/*
 A simple function 'add' declaration.

 When declaring each parameters of the function,
 be aware of the type declared... 
 Watch out for the return type too!

 what is the largest number that fits in an 'char' or 'integer'?

************************************************
Output:

Adding 200 + 50 is equal to: 250
Adding 200 + 56 is equal to: 0 (Variable 'char' Overflow!)

Number 1 is stored in                   4 bytes!
Number 200 is stored in                 4 bytes!
Number 256 is stored in                 4 bytes!
Number 4,294,967,295 is storage in      4 Bytes!
Number 4,294,967,296 is storage in      8 Bytes!
*************************************************
 Note: 
 Warning: 
 [4,294,967,295] this decimal constant is unsigned only in ISO C90:
 https://stackoverflow.com/questions/9941261/warning-this-decimal-constant-is-unsigned-only-in-iso-c90

 Compiler: Dev C ++ Version 2 - Jun, 1991
		  (https://sourceforge.net/projects/orwelldevcpp/)

 Author: F. Simplicio (microgenios.com.br) 
 Edited by j3
 date: jun, 18/2020
*/
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
unsigned char add(unsigned char x, unsigned char y)
{
	return x + y;
}

int main(void)
{
	unsigned char result;
	//  language treats constants as integer
	result = add(200, 50);
	// Watch out if the copy of the number 200 fits in the char x value
	// as char can assume values between 0-255, so 200 is ok!
	// Again, can 50 fits inside char value? yep! with plenty of room!
	printf("Adding 200 + 50 is equal to: %d\n", result);
	// Now, be aware!  the result 250 fits inside 'unsigned char'? 
	// yep! with little clearance!
	// if you put 56 what will happen? Try to put y = 56;
	// See the comparation 'char' and 'int' below:
	// Range of 'char' 0-255
	// int  0b 00000000 00000000 (0)
	// char 0b          11111111 (255) OK!!!
	// Plus 1:
	// int  0b 00000001 00000000 (256)
	// char 0b          00000000 (0) BUG!!!!
	result = add(200, 56);
	printf("Adding 200 + 56 is equal to: %d (Variable 'char' Overflow!)\n", result);
	
	// What is the small unity of storage in 32-bit processor? Answer: integer.
	// Any number up to 2^32-bits are stored as integer. The word is integer! See:
	printf("\nNumber 1 is stored in			%d bytes! ", sizeof(1));
	printf("\nNumber 200 is stored in			%d bytes! ", sizeof(200));
	printf("\nNumber 256 is stored in			%d bytes! ", sizeof(256));
	printf("\nNumber 4,294,967,295 is storage in 	%d Bytes!", sizeof(4294967295));
	printf("\nNumber 4,294,967,296 is storage in 	%d Bytes!", sizeof(4294967296));
	//system("pause");
	return 0;
}
