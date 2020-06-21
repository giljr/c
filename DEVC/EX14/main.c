/*
  sprintf - Another Use (convert integer & float to strings)
  
  Another important use of sprintf() function is to convert integer and float values to strings.
  Description
  The system simply outputs 2 strings.
  Then returns each strings using 1 sprintf function.
 
  There is an option for get(acquire, obtain) the outuput other than gets() method:
  scanf(): but this actually is more difficult, since we need to clear input buffer.
  Reference:  
  https://stackoverflow.com/questions/7898215/how-to-clear-input-buffer-in-c/7898516#7898516

	Syntax: int sprintf(char *str,                    // Array that stores the output
	                    const char *control_string,   // Parameter that format the output:
						[ arg_1, arg_2, ... ]);       // %d - data - integers - 5
						                              // %f - floating points - 5	
	Included in <stdio.h> library.                    // %e - exponential - (scientific) - 2^2
	                                                  // %g - Fixed decimal - 5.05
													  // %.2f - float - number of decimal - 5.12
	  

  *********************
  Output:
  s1 = 100
  s2 = 300.00
  *********************
  
  Author: https://overiq.com/c-programming-101/the-sprintf-function-in-c/
  Edited by j3
 
  Date: Jun, 21/2020
*/

#include<stdio.h>
#include<string.h>

 
int main()
{
    char s1[20];
    char s2[20];
 
    int x = 100;
    float y = 300;
 
    sprintf(s1, "%d", x);
    sprintf(s2, "%.2f", y);
 
    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
 
    // signal to operating system program ran fine
    return 0;
}
