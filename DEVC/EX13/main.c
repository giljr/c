/*
 Project 13
 sprintf - The Use of

 The sprintf() works just like printf() but instead of sending output to console it returns 
 the formatted string.
 
 Description
 The system asks you for name, designation and salary.
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
	  

 *************************************
 Output:
	Enter your name: j3
	Enter your designation: student
	Enter your salary: 12

	Welcome j3 !
	Name: j3
	Designation: student
	Salary: 12
**************************************

 Author: https://overiq.com/c-programming-101/the-sprintf-function-in-c/
 Edited by j3
 
 Date: Jun, 21/2020	
*/

#include<stdio.h>
#include<string.h>
 
int main()
{
 
    int c;
    int sal;
    char name[30], designation[30], info[60];
 
    printf("Enter your name: ");
    gets(name);
    
    //scanf("%s", &name);
    //while((c=getchar())!= '\n' && c!= EOF){}
	 
    printf("Enter your designation: ");
    gets(designation);
    
    //scanf("%s", &designation);
    //while((c=getchar())!= '\n' && c!= EOF){}
 
    printf("Enter your salary: ");
    	
    scanf("%d", &sal);
    while((c=getchar())!= '\n' && c!= EOF){}
 
    sprintf(info, "Welcome %s !\nName: %s \nDesignation: %s\nSalary: %d", name, name, designation, sal);
 
    printf("\n%s", info);
    
    //system("pause");  
    // signal to operating system program ran fine
    return 0;
}

