/* 
   Project 26 
   Declaring Floats
   Calculating the Circumference and Area  of a Circular Table:
   
   Description
   
   The system will asks you what the diameter of the table is.
   Then calculate Circumference & Area of the table :)
   
   Explaning it All
   
   This time you will have a go at calculating the circumference and area 
   of a circular table from an input value for its  diameter.
   You may remember from elementary math the equations to calculate 
   the area and circumference of a circle using p or pi 
   (circumference = 2pr and area = pr^2 , where r is the radius). 
   If you do not, do not worry. This is not a math book, 
   so just look at how the program works.
   
************************************
Output:

Input the diameter of the table: 2

The circumference is 6.28
The area is 3.14
************************************
   From: Beginning_c_5th_edition, pg 51
   Edited by j3
   
   Date: Jun, 22/2020

*/

#include <stdio.h>

int main(void) {
	
 float radius = 0.0f; 				// The radius of the table
 float diameter = 0.0f; 			// The diameter of the table
 float circumference = 0.0f; 			// The circumference of the table
 float area = 0.0f; 				// The area of the table
 float Pi = 3.14159265f;
 
 printf("Input the diameter of the table: ");
 scanf("%f", &diameter); 			// Read the diameter from the keyboard
 
 radius = diameter/2.0f; 			// Calculate the radius
 circumference = 2.0f*Pi*radius; 		// Calculate the circumference
 area = Pi*radius*radius; 			// Calculate the area
 
 printf("\nThe circumference is %.2f", circumference);
 printf("\nThe area is %.2f\n", area);
 
 return 0;
}
