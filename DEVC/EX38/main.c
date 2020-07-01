/*
 Project 38
 Simple Calculator v1 - Calculator v1 - Switch & While
 
 Decision Making in C (if , if..else, Nested if, if-else-if, switch )
  
 Redo Project 36, now inserting a new option in the MENU called EXIT. 
 The program will end when the user enters any other value
 outside the MENU options (5, actually:)
 
****************************************************
Output:

Calculator v1 - Welcome!
Please, Enter the first number: 12.12
Now, the second number: 12.12

        Menu
1 - Addition
2 - Subtraction
3 - Multiplication
4 - Division
5 - Enter 5 to Exit

Please, choose the required option: 1
The result of Addition is: 24.24

Again? please, Enter the first number: 12.13
Now, the second number: 12.13

        Menu
1 - Addition
2 - Subtraction
3 - Multiplication
4 - Division
5 - Enter 5 to Exit

Please, choose the required option: 3
The result of Multiplication is: 147.14

Again? please, Enter the first number: 1
Now, the second number: 1

        Menu
1 - Addition
2 - Subtraction
3 - Multiplication
4 - Division
5 - Enter 5 to Exit

Please, choose the required option: 5
Finishing The System...Bye o/

**************************************************** 
 Author: Borin (https://br.linkedin.com/in/borinvini) 
 Edited by j3
 
 Date: First Day, 07/2020 

*/

#include <stdio.h>
#define TRUE 1

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
	printf("4 - Division\n");
	printf("5 - Enter 5 to Exit\n\n");
	
	printf("Please, choose the required option: ");
	scanf("%i", &opr);
	while ((c = getchar())!= '\n' && c != EOF) { }
	
	while(TRUE)
	{
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
		
			case 5:
				printf("Finishing The System...Bye o/");
				return 0;
				break;
			
			default:
				printf("Invalid Operation:/ \nTry again :) ");
				break;
		}
		
		/*
			How not to get stuck in an infinite loop? 
			I replicate an important part of my code, and interact again with the user
			
		*/
		
		printf("\n\nAgain? please, Enter the first number: ");
		scanf("%f", &x);
		while ((c = getchar())!= '\n' && c != EOF) { }	
	
		printf("Now, the second number: ");
		scanf("%f", &y);
		while ((c = getchar())!= '\n' && c != EOF) { }
	
		printf("\n\tMenu\n");
		printf("1 - Addition\n");	
 		printf("2 - Subtraction\n");	
		printf("3 - Multiplication\n");	
		printf("4 - Division\n");
		printf("5 - Enter 5 to Exit\n\n");
	
		printf("Please, choose the required option: ");
		scanf("%i", &opr);
		while ((c = getchar())!= '\n' && c != EOF) { }
	
	}
	
	//system("pause");
	return 0;
	
}
