/*
  Project 02
  Simple use of modifiers
  'long' and 'short' is applicable only for integers!
  
  Exception: 'long double'

 ***************************** 
 Output:
	U_INT                   4
	U_SHORT_INT             2
	U_LONG_INT              4
	U_LONG_LONG_INT         8

	DOUBLE                  8
	LONG_DOUBLE             16
 *****************************
 
  Compiler: Dev C ++  Version 2 - Jun,1991
	  	    (https://sourceforge.net/projects/orwelldevcpp/)
	  
  Author: F. Simplicio (microgenios.com.br) 
  Edited by j3
  date: jun, 18/2020
*/


#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
{
	// The modifiers 'long' and 'short' is applicable only for integers!
	unsigned int a;
	unsigned short int b;
	unsigned long int c;
	unsigned long long int d;
		
	printf("U_INT			%d\n", sizeof(a));
	printf("U_SHORT_INT		%d\n", sizeof(b));
	printf("U_LONG_INT		%d\n", sizeof(c));
	printf("U_LONG_LONG_INT		%d\n", sizeof(d));
	
	// exception : long double
	double e;
	long double f;
	printf("\nDOUBLE			%d\n", sizeof(e));
	printf("LONG_DOUBLE		%d\n", sizeof(f));
	
	//system("pause");	
	return 0;
}
