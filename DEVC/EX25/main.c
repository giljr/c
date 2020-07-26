/*
  Project 25 - Controlling the Number of Decimal Places in the Output.
  
  Controlling the Output Field Width & Alignment in the field.
  
**************************************************************************
Output:

A plank    10.00 feet long can be cut into     4 pieces   2.50 feet long.

A plank 10.00    feet long can be cut into 4     pieces 2.50   feet long.


EXPLAINNING IT ALL:

Alignment in the field:
-------------------------------------

Aligment to the Left -> just put a minus sign following the % sign.
Like this: %-8.2f:)

Controlling the Output Field Width
-------------------------------------
The general form of the format specifier for floating-point
values can be written like this:

%[width][.precision][modifier]f

The first output value (%8.2f) now has a field width of
eight and two decimal places after the decimal point.

The second output value (%5.0f), which is the count of the number
of pieces, has a field width of five characters and no decimal places.

The third output value (%6.2f) will be presented in a field
width of six characters with two decimal places.

There you have it! Bye! o/
**************************************************************************
 
 From: Book: Beginning_c_5th_edition - Takes you Step-by-Step From Novice to C Programmer - Ivor Horton
       page - pg 46 - Floating-Point Number Representation - Chapter 2: First Steps in Programming
 Edited by j3
 
 Date: Jun, 22/2020
  
*/

#include <stdio.h>


	int main(void)
	{
		float plank_length = 10.0f; // In feet
 		float piece_count = 4.0f; // Number of equal pieces
 		float piece_length = 0.0f; // Length of a piece in feet
 		
 		piece_length = plank_length/piece_count;
 		printf("A plank %8.2f feet long can be cut into %5.0f pieces %6.2f feet long.\n",
 		plank_length, piece_count, piece_length);
 		
 		printf("\nA plank %-8.2f feet long can be cut into %-5.0f pieces %-6.2f feet long.\n",
 		plank_length, piece_count, piece_length);
 		
 		printf("\n\nEXPLAINNING IT ALL:\n\n");
 		
 		printf("Alignment in the field:\n");
 		printf("-------------------------------------\n");
 		
 		printf("\nAligment to the Left -> just put a minus sign following the %% sign. \n"); 
		printf("Like this: %%-8.2f:)\n\n");
 		 		
 		printf("Controlling the Output Field Width\n");
 		printf("-------------------------------------\n");
 		
		printf("The general form of the format specifier for floating-point\n\r"
		  	"values can be written like this:\n\n");
		
		printf("%%[width][.precision][modifier]f\n\n");
 		
		printf("The first output value (%%8.2f) now has a field width of \n\r"
         		"eight and two decimal places after the decimal point.\n\n\r" 
		 	"The second output value (%%5.0f), which is the count of the number\n\r"
         		"of pieces, has a field width of five characters and no decimal places.\n\n\r"
		 	"The third output value (%%6.2f) will be presented in a field\n\r"
		 	"width of six characters with two decimal places.\n\n\r"
		 	"There you have it! Bye! o/\n\n");
 	
		//system("pause");
		return 0;
	
}
