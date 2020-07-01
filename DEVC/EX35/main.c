/*
 Project 35
  
 Create, in C language, an algorithm that operates a calculator, performing the
 four basic mathematical operations. A menu should appear on the screen
 the 4 options, and the user will choose the option they want. For the choice of
 operation, use the conditional IF (if).
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
	
	if(opr == 1)
	{   
		// Addition
		res = x + y;
		printf("The result of Addition is: %.2f", res);
		
	} else 
	{
		if( opr == 2)
		{   
			// Subtraction
			res = x - y;
			printf("The result of Subtraction is: %.2f", res);
		}
		else 
		{
			if(opr == 3 )
			{   	
				// Multiplication
				res = x * y;
				printf("The result of Multiplication is: %.2f", res);				
			}
			else
			{   
				// Division
			 	res = x / y;
			 	printf("The result of Division is: %.2f", res);
			}

		}
		
	}
    
	//system("pause");
	return 0;
	
}
