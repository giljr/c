#include <stdio.h>
#include <stdlib.h>


/* Project 68
   Studying C Types (char, int, float & double) 

This program show:
 
How to get the type of a variable in C code?

***************************** 
 Output:

Char -> 1 Byte(s)
int -> 4 Byte(s)
float -> 4 Bytes(s)
double -> 8 Byte(s)
long double 16 Byte(s)
The Default C type is: int

*****************************

  . C Rule n 1 - no variable can assume the same char value;
  . C Rule n 2 - the absence of modifiers forces the compiler to use the signed;
  . C Rule n 3 - int is the standard type; 
  . C Rule n 4 - if you don't indicate the type, the compiler assumes int;
  
Compiler: Dev C ++ Version 2 - Jun,1991
		  (https://sourceforge.net/projects/orwelldevcpp/)
	    
  	Author: j3
  	date: jun, 08/2021
*/

int main() {
	
	char a;
	int b;
	float c;
	double d;
	long double e;
	
	signed f;
	
	printf("Char -> %d Byte(s)\n", sizeof(a));
	printf("int -> %d Byte(s)\n", sizeof(b));
	printf("float -> %d Bytes(s)\n", sizeof(c));
	printf("double -> %d Byte(s)\n", sizeof(d));
	printf("long double %d Byte(s)\n", sizeof(e));
	
	/* if you don't indicate the type the compiler assumes int */
	printf("The Default C type is: ");
	if(sizeof(f)==sizeof(char))
        printf("char");
    else if(sizeof(f)==sizeof(int))
        printf("int");
    else if(sizeof(f)==sizeof(double))
        printf("double");
	
	return 0;
}
