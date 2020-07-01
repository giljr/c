/*
 Project 35
 Simple Calculator v1 - Calculator v1 - Switch
 
 Decision Making in C (if , if..else, Nested if, if-else-if, switch )
  
 Create, in C language, an algorithm that operates a calculator, performing the
 four basic mathematical operations. A menu should appear on the screen
 the 4 options, and the user will choose the option they want. For the choice of
 operation, use the conditional switch.
 Menu Example:
 1 - addition;
 2 - subtraction;
 3 - multiplication;
 4 - division.
 
****************************************************
Output:

Calculator v1 - Welcome!
Please, Enter the first number: 1
Now, the second number: 2

        Menu
1 - Addition
2 - Subtraction
3 - Multiplication
4 - Division

Please, choose the required option: 1
The result of Addition is: 3.00

or 

Calculator v1 - Welcome!
Please, Enter the first number: 12.12
Now, the second number: 12.12

        Menu
1 - Addition
2 - Subtraction
3 - Multiplication
4 - Division

Please, choose the required option: 5
Invalid Operation:/
Try again :)

**************************************************** 
 Author: Borin (https://br.linkedin.com/in/borinvini) 
 Edited by j3
 
 Date: First Day, 07/2020 

*/

#include <stdio.h>

float x, y, res; 
int opr, c;

main()
{
	printf("Calculator v1 - Welcome!\n");
	
	printf("Please, Enter the first number: ");
	scanf("%f", &x);
	while ((c = getchar())!= '\n' && c != EOF) { }	
	
	printf("Now, the second number: ");
	scanf("%f", &y);
	while ((c = getchar())!= '\n' && c != EOF) { }
	
	printf("\n\tMenu\n");
	printf("1 - Addition\n");	
 	printf("2 - Subtraction\n");	
	printf("3 - Multiplication\n");	
	printf("4 - Division\n\n");
	
	printf("Please, choose the required option: ");
	scanf("%i", &opr);
	while ((c = getchar())!= '\n' && c != EOF) { }
	
	switch(opr)
	{
		case 1:
			res = x + y;
			printf("The result of Addition is: %.2f", res);
			break;
			
		case 2:
			// Subtraction
			res = x - y;
			printf("The result of Subtraction is: %.2f", res);
			break;
			
		case 3:
			// Multiplication
			res = x * y;
			printf("The result of Multiplication is: %.2f", res);	
			break;
			
		case 4:
			// Division
			res = x / y;
	   		printf("The result of Division is: %.2f", res);
			break;
			
		default:
			printf("Invalid Operation:/ \nTry again :) ");
			break;
	}
	
	//system("pause");
	return 0;
	
}
