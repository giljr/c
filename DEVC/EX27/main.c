/*
  Project 27

  How To Declare Floats & Doubles
  
Table 1
--------------------------------------------------------
Format Specifiers for Reading Data
--------------------------------------------------------
Action 							Required control string
To read a value of type short 	%hd
To read a value of type int 	%d
To read a value of type long 	%ld
To read a value of type float 	%f or %e
To read a value of type double 	%lf or %le
----------------------------------------------------------
 
******************************************************
Output:

Float consumes 4 Bytes
The circumference is 6.28. The area is 3.14

Double consumes 8 Bytes
The circumference is 6.28. The area is 3.14

*******************************************************

 Author: j3
 
 Date: Jun, 22/2020  
*/

#include <stdio.h>

#define Pi 3.1415926

int main(void)
{
	
	float diameter = 2.0f;
	float radius1 = diameter/2.0f; 				// Calculate the radius
	float circumference1 = 2.0f*Pi*radius1; 	// Calculate the circumference
	float area1 = Pi*radius1*radius1; 			// Calculate the area
	printf("\nFloat consumes %d Bytes\n", sizeof(area1));
	
	
	printf("The circumference is %.2f. ", circumference1);
	printf("The area is %.2f\n", area1);
	
	double radius2 = diameter/2.0f; 			// Calculate the radius
	double circumference2 = 2.0*Pi*radius2; 	// Calculate the circumference
	double area2 = Pi*radius2*radius2; 			// Calculate the area
	printf("\nDouble consumes %d Bytes\n", sizeof(area2));
	
	printf("The circumference is %.2lf. ", circumference2);
	printf("The area is %.2lf\n", area2);
	
	//system("pause");
	return 0;
	
}
