/*
  Functions in C


  A function is a set of statements that take inputs, do some specific 
  computation and produces output. The idea is to put some commonly or 
  repeatedly done task together and make a function so that instead of 
  writing the same code again and again for different inputs, 
  we can call the function.


  Description:
  The system will accept 3 input integers from the user
  and store these numbers in 3 variables.
  Then it will show all the biggest one! Simple like that!

  We will make a function called bigNumber()

  Author: Borin (https://br.linkedin.com/in/borinvini) 
  Edited by j3
  date: jun, 13/2020
*/
#include<stdio.h>
#include<stdlib.h>

// Declaring the prototype -  it is a good habit to declare it!
int bigNumber(int x, int y, int z);

int main()
{
	int num1, num2, num3, c;
	printf("Please, enter the firt number: ");
	scanf_s("%d",&num1);
	// How to clear input buffer in C?
	// this is How can you flush pending input so that
	// a user's typeahead isn't read at the next prompt. From:
	// https://stackoverflow.com/questions/7898215/how-to-clear-input-buffer-in-c
	while ((c = getchar()) != '\n' && c != EOF) {}
	
	printf("Please, enter the second number: ");
	scanf_s("%d", &num2);
	while ((c = getchar()) != '\n' && c != EOF) {}

	printf("Please, enter the third number: ");
	scanf_s("%d", &num3);
	while ((c = getchar()) != '\n' && c != EOF) {}

	printf("The biggest value is: %d\n", bigNumber(num1, num2, num3));
	//system("pause");
	return 0;
} // end of main

int bigNumber(int x, int y, int z)
{

	// lets test what is the biggest number.
	if (x >= y && x >= z)
	{
		return x;
	}
	else if (y >= x && y >= z)
	{
		return y;
	}
	else
	{
		return z;
	}

}
