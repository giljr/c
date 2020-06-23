/* 
   Project 29
   
   Format specifiers in C
   
   printf(char *format, arg1, arg2, …)
   
   1 - Character format specifier : 	   %c
   2 - Integer format specifier   : 	   %d, %i
   3-  Floating-point format specifier :   %f, %e or %E
   4 - Unsigned Octal number for integer : %o
   5 - Unsigned Hexadecimal for integer :  %x, %X
   6 - String printing : 	           %s
   7 - Double floating-point number :      %lf
   
   
*****************************************************************************************
Output:

('A')             is a char  and as format specifier use %c  that results: A
(int x = 45)      is a int   and as format specifier use %d  that results: 45 or
(int y = 90)      is a int   and as format specifier use %i  that results: 45
(float a = 12.67) is a float and as format specifier use %f  that results: 12.670000 or
(float b = 17.69) is a float and as format specifier use %e  that results: 1.267000e+001
(int b = 9) is int to octal  and as format specifier use %o  that results: 10
(int c = 10) is a int to hex and as format specifier use %x  that results:  a
(char d[] = "j3") is string  and as format specifier use %s  that results: j3
(double e = 45.65) is double and as format specifier use %lf that results: 45.650000

*****************************************************************************************
  Author j3
  
  Date: Jun, 23/2020

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* 1 - Character format specifier : %c */
    char ch = 'A'; 
    printf("('A') 		  is a char  and as format specifier use %%c  that results: %c\n", ch);
    
    /* 2 - Integer format specifier   : %d, %i */
    int x = 45, y = 90; 
    printf("(int x = 45) 	  is a int   and as format specifier use %%d  that results: %d\ or\n", x); 
    printf("(int y = 90) 	  is a int   and as format specifier use %%i  that results: %i\n", x); 
    
    /* 3 - Floating-point format specifier : %f, %e or %E */
    float a = 12.67; 
    printf("(float a = 12.67) is a float and as format specifier use %%f  that results: %f or\n", a); 
    printf("(float b = 17.69) is a float and as format specifier use %%e  that results: %e\n", a); 
	
    /*  4 - Unsigned Octal number for integer : %o */
    int b = 8; 
    printf("(int b = 9) is int to octal  and as format specifier use %%o  that results: %o\n", b); 
	
	
    /* 5 - Unsigned Hexadecimal for integer : %x, %X */
    int c = 10; 
    printf("(int c = 10) is a int to hex and as format specifier use %%x  that results:  %x\n", c); 
	
	
    /* 6 - String printing : %s */
    char d[] = "j3"; 
    printf("(char d[] = \"j3\") is string  and as format specifier use %%s  that results: %s\n", d); 
	
    /* 7- Double floating-point number : %lf */
    double e = 45.65; 
    printf("(double e = 45.65) is double and as format specifier use %%lf that results: %lf\n", e);
	
    //system("pause");
    return 0;
}
