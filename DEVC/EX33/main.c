/*
  Project 33
  
  Using Switch Case Statements. 
  
  In the next Project 34 we will use functions pointers. It it out too:)
  
  Context
  
  There are some situations in which user has to decide
  which function has to be called at a particular point in time there are
  definitely some situations in which the user has to decide which function has to
  be called right. 
  
  I will demo two of them. The first one, this Project 32!
  
  Description
  
  Let's say if you want to design a calculator which has the capability to
  perform addition subtraction multiplication and division; we want to design 
  a calculator program which has the capability to perform all these operations 
  and here the user will decide which operation he or she wants to perform.

  
  A switch statement allows a variable to be tested for equality against a list 
  of values. Each value is called a case, and the variable being switched on is 
  checked for each switch case. Here is syntax of it:

		switch (variable or an integer expression)
		{
     		case constant:
     			//C Statements;
     		case constant:
     			//C Statements;
     		default:
     			//C Statements;
		}
		
  Note: This command below is preventing buffers overflows:
  		while((c = getchar())!= '\n' && c != EOF){}
  		For details, please see this:
		   Project 15: https://github.com/giljr/c/tree/master/DEVC/EX15
		
*****************************
Output:

Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for mult and 4 for divi: 0
Enter the two numbers:
10
2
12.000000

or 

Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for divi: 4
Invalid Operation:/
Try again :)

*****************************
  Author Neso Academy (https://youtu.be/wQ-gWwKKeP4)
  Edited by j3
  
  Date: Jun. 28/2020

*/

#include <stdio.h>

#define opr

float sum(float a, float b){ return (a+b); } 

float sub(float a, float b){ return (a-b); }

float mult(float a, float b){ return (a*b); }

float divi(float a, float b){ return (a/b); }

int main()
{
    int choice;
	
    float a, b, result, c;
	
    printf("Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for divi: ");
    scanf("%d", &choice);
    while((c = getchar())!= '\n' && c != EOF){}
	
    // filters out values greater than 
    if (choice < 4)	
	{
    		printf("Enter the two numbers:\n");
		
    		scanf("%f %f", &a, &b);
    		while((c = getchar())!= '\n' && c != EOF){}
    	
		switch(choice)
			{
				case 0: result = sum(a, b); break;
				case 1: result = sub(a, b); break;
				case 2: result = mult(a, b); break;
				case 3: result = divi(a, b); break;				
			}				
			
		printf("%f", result);
				
	}  else
	
		printf("Invalid Operation:/ \nTry again :)");

	//system("pause");
	return 0;
	
}
