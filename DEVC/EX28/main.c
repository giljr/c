/*
   Project 28 - FINDING THE LIMITS: <limits.h>
   
   Table: Symbols Representing Range Limits for Integer Types
   ---------------------------------------------------------- 

    -----------------------------------
 	Type	Lower_limit 	Upper_limit
    ----	-----------   	-----------
	char	CHAR_MIN 		CHAR_MAX
	short 	SHRT_MIN 		SHRT_MAX
	int 	INT_MIN 		INT_MAX
	long 	LONG_MIN 		LONG_MAX
	long 	long LLONG_MIN 	LLONG_MAX
	-----------------------------------
	
***************************************************************************
Output:
--------------------------------------------------------------------------
                    Table: Variables types store values from:
--------------------------------------------------------------------------
CHAR:                       -128 -> 127
UNISIGNED CHAR:                0 -> 255
SHORT (INT):              -32768 -> 32767
UNSINED SHORT (INT):           0 -> 65535
INT:                 -2147483648 -> 2147483647
UNSIGNED INT:                  0 -> 4294967295
LONG:                -2147483648 -> 2147483647
UNSIGNED LONG:                 0 -> 4294967295
LONG LONG:  -9223372036854775808 -> 9223372036854775807
UNSIGNED LONG LONG:            0 -> 18446744073709551615
--------------------------------------------------------------------------
SMALLEST POSITIVE NON-ZERO VALUE OF FLOAT  is 1.175e-038
LARGEST  FLOAT                             is 3.403e+038
SMALLEST NON-ZERO VALUE OF DOUBLE          is 2.225e-308
LARGEST DOUBLE                             is 1.798e+308
SMALLEST NON-ZERO VALUE OF LONG DOUBLE     is 3.205e-317
LARGEST VALUE OF LONG DOUBLE               is 3.205e-317
--------------------------------------------------------------------------

*************************************************************************** 
   From Beginning_c_5th_edition
   Edited by j3
   
   Date: Jun, 22/2020
*/

#include <stdio.h> // For command line input and output
#include <limits.h> // For limits on integer types
#include <float.h> // For limits on floating-point types

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	printf("--------------------------------------------------------------------------\n");
	printf("                    Table: Variables types store values from:\n");
	printf("--------------------------------------------------------------------------\n");
	printf("CHAR:\t\t\t %d -> %d\n",     		 CHAR_MIN, CHAR_MAX);
 	printf("UNISIGNED CHAR:\t\t 0 -> %u\n",      UCHAR_MAX);
 	printf("SHORT (INT):\t\t %d -> %d\n",        SHRT_MIN, SHRT_MAX);
 	printf("UNSINED SHORT (INT):\t 0 -> %u\n",   USHRT_MAX);
 	printf("INT:\t\t\t %d -> %d\n",              INT_MIN, INT_MAX);
 	printf("UNSIGNED INT:\t\t 0 -> %u\n",        UINT_MAX);
 	printf("LONG:\t\t\t %ld -> %ld\n",           LONG_MIN, LONG_MAX);
 	printf("UNSIGNED LONG:\t\t 0 -> %lu\n", 	 ULONG_MAX);
 	printf("LONG LONG:\t\t %lld -> %lld\n",      LLONG_MIN, LLONG_MAX);
 	printf("UNSIGNED LONG LONG:\t 0 -> %llu\n",  ULLONG_MAX);
 	printf("--------------------------------------------------------------------------\n");
 	printf("SMALLEST POSITIVE NON-ZERO VALUE OF FLOAT  is %.3e\n",  FLT_MIN);
 	printf("LARGEST  FLOAT    			   is %.3e\n",  			FLT_MAX);
 	printf("SMALLEST NON-ZERO VALUE OF DOUBLE  	   is %.3e\n",  	DBL_MIN);
 	printf("LARGEST DOUBLE                      	   is %.3e\n",  DBL_MAX);
 	printf("SMALLEST NON-ZERO VALUE OF LONG DOUBLE 	   is %.3Le\n", LDBL_MIN);
 	printf("LARGEST VALUE OF LONG DOUBLE           	   is %.3Le\n", LDBL_MAX);
	printf("--------------------------------------------------------------------------\n");
	//system("pause");
	return 0;
}
