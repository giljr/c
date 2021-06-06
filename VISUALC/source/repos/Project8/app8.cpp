/*
  Simple calculator v1 (addition & subtration)

  Demo for the use of functions

  Description:
  The system will accept 1 input floats from the user
  and store these numbers in 2 variables.
  It will ask for operations (+ or -)
  Then will return the result. Simple like that!

  We will make 2 functions:  called 
  add(float, float)  and sub(float, float)
  
  note: To halt the syste simply type 
		a number different of 1 or 2:)

  Author: Borin (https://br.linkedin.com/in/borinvini) 
  Edited by j3
  date: jun, 13/2020
*/
#include<stdio.h>
#include<stdlib.h>

// Declaring the prototype -  it is a good habit to declare it!
void menu();
float add(float a, float b);
float sub(float a, float b);

int main()
{
	int operation;
	float x, y, result, c;

	printf("Please, enter the first number: ");
	scanf_s("%f", &x);
	// How to clear input buffer in C?
	// this is How can you flush pending input so that
	// a user's typeahead isn't read at the next prompt. From:
	// https://stackoverflow.com/questions/7898215/how-to-clear-input-buffer-in-c
	while ((c = getchar()) != '\n' && c != EOF) {}

	printf("Please, enter the second number: ");
	scanf_s("%f", &y);
	while ((c = getchar()) != '\n' && c != EOF) {}

	
	menu();
	scanf_s("%d", &operation);
	while ((c = getchar()) != '\n' && c != EOF) {}

	while ((operation >= 1) && (operation <= 2))
	{
		switch (operation)
		{
		case 1: // Addition
			result = add(x, y);
			printf("x plus y is: %.2f\n", result);
			break;
		case 2: // subtration
			result = sub(x, y);
			printf("x minus y is: %.2f\n", result);
			break;
		default:
			printf("Operation not supported!");
			break;
		}
		printf("Please, enter the first number: ");
		scanf_s("%f", &x);
		while ((c = getchar()) != '\n' && c != EOF) {}

		printf("Please, enter the second number: ");
		scanf_s("%f", &y);
		while ((c = getchar()) != '\n' && c != EOF) {}

		
		menu();
		scanf_s("%d", &operation);
		while ((c = getchar()) != '\n' && c != EOF) {}
	}

	//system("pause");
	return 0;
} // end of main

void menu()
{
	printf("1 - Addition \n");
	printf("2 - Subtration \n");
	printf("Please, choose an operation:");
}

float add(float a, float b)
{
	return a + b;
}

float sub(float a, float b)
{
	return a - b;
}
