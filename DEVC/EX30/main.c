/*
  Project 30
  Enumeration, Math & Trigonometry Examples in C
  
**********************************************
Output:

Enumerations:
------------
0
1
2
3
4
5
6

Math Functions:
--------------
less = 2.000000
more = 3.000000
root = 1.500000

Trig Functions:
--------------
sine = 0.866025
cosine = 0.500000
**********************************************
  Author j3
  Date Jun, 25/2020
*/

#include <stdio.h>
#include <math.h>

 
int main() 
{ 	
    	/*
	Enumeration:
	Here the example defines the enumeration type week, 
	so variables of this type can have one of the seven values
	between the braces
	*/
	
	printf("\nEnumerations:\n");
	printf("------------\n");
	enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun}; 
   	enum week day; 
   	day = Mon; 
    	int i= Mon;
    	for(i ; i <= Sun; i++)
	{
       	printf("%d\n", i );
    	}
   
    	/*
	Mathematical Functions:
		The math.h header file includes declarations for a wide range of mathematical functions. 
		To give you a feel here are some examples
	*/
    	
	printf("\nMath Functions:\n");
    	printf("--------------\n");
    
   	double x = 2.25;
	double less = 0.0;
	double more = 0.0;
	double root = 0.0;
	
	printf("less = %lf\n", floor(x));   				// Result is 2.0
	printf("more = %lf\n", ceil(x)); 				// Result is 3.0
	printf("root = %lf\n", sqrt(x)); 				// Result is 1.5
	
	/* 
	Trigonometry Functions:
	The use of these functions will be fairly self-evident. 
	Here are some examples
	*/	
	
	printf("\nTrig Functions:\n");
	printf("--------------\n");
	
	double angle = 60.0; 						// Angle in degrees
	double pi = 3.14159265;
	double sine = 0.0;
	double cosine = 0.0;
	printf("sine = %f\n",sin(pi*angle/180)); 			// Angle converted to radians
	printf("cosine = %f\n", cos(pi*angle/180.0)); 			// Angle converted to radians
   		
	//system("pause");
	return 0;
}  		


