/*
  Project 34
  
  This Project will demonstrate the use of function pointers!
  
  Context
  
  There are some situations in which user has to decide
  which function has to be called at a particular point in time there are
  definitely some situations in which the user has to decide which function has to
  be called right. 
  
  I will demo two method odf doing so... This is Second one, this Project 34!
   
  In the privious: 
  	Project 33 we will use Switch Expressions Statement. 
	  It it out too:)
  
  Description
  
  Let's say if you want to design a calculator which has the capability to
  perform addition subtraction multiplication and division; we want to design 
  a calculator program which has the capability to perform all these operations 
  and here the user will decide which operation he or she wants to perform.
  
  Here we will use Fuction Pointers. The function will be called at runtime:)

  
  What is Fuctions Pointers
  
  Are like normal pointers but they have the capability to point to a function. 
  Functions are stored as instructions in memory.
  This program is more concise and easy to read and undenstand.
  We can eliminate a lot of redundance. See how for yourself...
  The decision are made at runtime.
  Here we eliminate the use of switch expressions.  
  
		
*****************************
Output:

Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for divi: 1
Enter the two numbers:
2
2
0.000000

or 

Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for divi: 4
Invalid Operation:/
Try again :)

*****************************

  Note: If you run it in MS Visual C ++ 2019 or newer:
  use scanf_s() function instead.
  
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
	
	/* 
	 This is how to assign the address of a function to a function pointer
	
	 int result;
	 int (*ptr)(int, int) = &add;
	 result = *ptr(10,20);
	 printf("%d", result);
	
	 or like this:
	 int(*ptr)(int, int);
	
	 Here is the array of pointer; it points to functions, that consists of two arguments;
	 And we are passing the addresses of the functions to the array 
	 (the name of the functions indicates the address of them)	
	*/
	
	float(*ptr2func[opr])(float, float) = {sum, sub, mult, divi};
	
	printf("Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for divi: ");
	scanf("%d", &choice);
    	while((c = getchar())!= '\n' && c != EOF){}
	
	// filters out values greater than 
	if (choice < 4)	
	{
		printf("Enter the two numbers:\n");
		
		scanf("%f %f", &a, &b);
    		while((c = getchar())!= '\n' && c != EOF){}
    	
    		/*
    		// Eliminating the switch statements;
    		// Here we have a lot of redundance, here:/
		switch(choice)
			{
				case 0: result = sum(a, b); break;
				case 1: result = sub(a, b); break;
				case 2: result = mult(a, b); break;
				case 3: result = divi(a, b); break;				
			}				
			
			printf("%f", result);		
		*/
		
		// Here we are simply calling the specific chose function at runtime; 
		// Awesome, isn't it? One single line!
		printf("%f", ptr2func[choice](a,b));
				
		} else
	
			printf("Invalid Operation:/ \nTry again :)");

	//system("pause");
	return 0;
	
}
