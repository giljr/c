/* 
 Project 06
 Studing C 
 Function call by reference in C
 
 Description
 The system really swap the variables values using pointers.
 (see previous project)
 
 The call by reference method of passing arguments to a function 
 copies the address of an argument into the formal parameter. 
 Inside the function, the address is used to access the actual 
 argument used in the call. It means the changes made to the 
 parameter affect the passed argument.

 To pass a value by reference, argument pointers are passed to 
 the functions just like any other value. So accordingly you 
 need to declare the function parameters as pointer types as 
 in the following function swap(), which exchanges the values 
 of the two integer variables pointed to, by their arguments.
 
       
      Note: 'Pass By Value': 
      
      Please try to remove the ampersand (and the asterisk from the 
	  swap function) and see the result; If instead of addresses of the argument, 
	  values are passed to the functions, it will use these copies of the arguments and it
	  will not affect the actual local variables declared; 
	
	  It means the changes made to the parameters will not affect the passed arguments:/
	   
 https://www.tutorialspoint.com/cprogramming/c_function_call_by_reference.htm
 
***********************************
Output
Before swap, value of a : 100
Before swap, value of b : 200
After swap, value of a  : 200
After swap, value of b  : 100
************************************
 
 Author: https://www.tutorialspoint.com/
 Edited by j3
 
 Date: Jun, 20/2020
 
*/

#include <stdio.h>
#include <stdlib.h>
 
/* function declaration */
void swap(int *x, int *y);
 
int main () {

   /* local variable definition */
   int a = 100;
   int b = 200;
 
   printf("Before swap, value of a : %d\n", a );
   printf("Before swap, value of b : %d\n", b );
 
   /* calling a function to swap the values.
      * &a indicates pointer to a ie. address of variable a and 
      * &b indicates pointer to b ie. address of variable b.
   */
   swap(&a, &b);
 
   printf("After swap, value of a : %d\n", a );
   printf("After swap, value of b : %d\n", b );
 
   return 0;
}

/* function definition to swap the values */
void swap(int *x, int *y) {

   int temp;
   temp = *x;    /* save the value at address x */
   *x = *y;      /* put y into x */
   *y = temp;    /* put temp into y */
  
   return;
}
