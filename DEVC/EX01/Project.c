/*  
    Project 01
    Studying C Types (char, int, float & double) 
   	C Data Types
   	****************************
   	Type 	Descrition 	  Bits
   	****************************
   	char 	character 	8 
   	int	 	integer	16			
   	float 	floating point  32
   	double 	floating point  64 
   	****************************
   	modifiers: unsigned ( real numbers - only positive )
	             signed ( real numbers - positive & negative)
			      short (reduces capacity by half ) and 
				   long (doubles capacity )
  
  	notes: 
	  . Table above applicable for Atmega328p Microcontroller (8-bits or 16-bits);
	  
	  . C Rule n 1 - no variable can assume the same char value;
	  . C Rule n 2 - the absence of modifiers forces the compiler to use the signed;
	  . C Rule n 3 - int is the standard type; if you don't indicate the type, 
	    the compiler assumes int -> 'signed count' is equal to 'signed int count' 
		or (not modifier) 'int count';
		
	  . If your microcontroller is 32-bit, short assumes 16-bit;
	  . if your microcontroller is 16-bits, the short remains 16-bits, 
	    that is, no variable can assume the same char value(C Rule n 1);
	    
 ***************************** 
 Output:
	CHAR        1 Byte(s)
	INT         4  Byte(s)
	FLOAT       4  Byte(s)
	DOUBLE      8  Byte(s)
	LONG DOUBLE 16 Byte(s)
 *****************************
 
 	Compiler: Dev C ++ Version 2 - Jun,1991
		  	  (https://sourceforge.net/projects/orwelldevcpp/)
	    
  	Author: F. Simplicio (microgenios.com.br) 
  	Edited by j3
  	date: jun, 18/2020
*/

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	unsigned char a;
	unsigned int b;
	float c;
	double d;
	long double e;
	
	printf("CHAR        %d Byte(s)\n", sizeof(a));
	printf("INT         %d  Byte(s)\n", sizeof(b));
	printf("FLOAT       %d  Byte(s)\n", sizeof(c));
	printf("DOUBLE      %d  Byte(s)\n", sizeof(d));
	printf("LONG DOUBLE %d Byte(s)\n", sizeof(e));
	
	//system("pause");
	return 0;	
}
