/*
   Description
   A Simple Table demo for How To Declare a Variable in C
   
   The use of Type Names for Un/signed Integer Types (U, L, UL, LL, ULL)
  
********************************************************
Output:

DEMO DECLARING BIG NUMBERS:
-----------------------------------------------------
Type (Variable name)            Value           Bytes
--------------------            -----           -----
integer (salary)                100             4
long (Big_Number)               1287600         4
long (below_sea_level)          -100000         4
unsigned long (uvalue)          999999999       4
long long (really_big_number)   123456789       8
unsigned long long (LightYear)  429496700       8
-----------------------------------------------------
*********************************************************

 Author: j3
 Date: Jun, 22/2020
 
*/

#include <stdio.h> // Include the header file for input and output

int main(void)
{
	printf("DEMO DECLARING BIG NUMBERS:\n");
	printf("-----------------------------------------------------\n");
	printf("Type (Variable name)\t\tValue\t\tBytes\n");
	printf("--------------------\t\t-----\t\t-----\n");
	
	int salary = 100;
	printf("integer (salary)%\t\t");
	printf("%d\t\t", salary);
	printf("%d\t\t\n", sizeof(salary));
	
	
	long Big_Number = 1287600L;
	printf("long (Big_Number)\t\t");
	printf("%d\t\t", Big_Number);
	printf("%d\t\t\n", sizeof(Big_Number));
	
	long below_sea_level = -100000L;
	printf("long (below_sea_level)\t\t");
	printf("%d\t\t", below_sea_level);
	printf("%d\t\t\n", sizeof(below_sea_level));
	
		
	unsigned long uvalue = 999999999UL;
	printf("unsigned long (uvalue)\t\t");
	printf("%d\t", uvalue);
	printf("%d\t\t\n", sizeof(uvalue));
	
	long long really_big_number = 123456789LL;
	printf("long long (really_big_number)\t");
	printf("%d\t", really_big_number);
	printf("%d\t\t\n", sizeof(really_big_number));

	
	unsigned long long LightYear = 429496700ULL;
	printf("unsigned long long (LightYear)\t");
	printf("%d\t", LightYear);
	printf("%d\t\t\n", sizeof(LightYear));
	
	printf("-----------------------------------------------------\n");
	
	return 0;
}
