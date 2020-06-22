/*
 Studing C
 
 Description
 The system is a demo for +=, -=, *=, /=, %= operators
 
 Use of Simple Assignment Operator (=) and
 Compound assignment operators (+=, -=, *=, /=, %=) i C
 
************************************
Output:
Lin1 = Operator,  Value of c = 21
Lin2 += Operator, Value of c = 42
Lin1 -= Operator, Value of c = 42
Lin1 *= Operator, Value of c = 882
Lin1 /= Operator, Value of c = 42
Lin1 %= Operator, Value of c = 11
************************************
 Author: j3 
 Edited by j3
 
 Date: Jun, 20/2020

*/

#include <stdio.h>

int main()
{
	unsigned int a = 21;
	unsigned int c;
	
	/* Simple Assignment Operator */
	c = a;
	printf("Lin1 = Operator,  Value of c = %d\n", c);
	
	/* Add AND Assignment Operator */
	c += a;
	printf("Lin2 += Operator, Value of c = %d\n", c);
	
	/* 	Subtract AND Assignment Operator */
	c -+ a;
	printf("Lin1 -= Operator, Value of c = %d\n", c);
	
	/* Multiply AND Assignment Operator */
	c *= a;
	printf("Lin1 *= Operator, Value of c = %d\n", c);
	
	/* Divide AND Assignment Operator */
	c /= a;
	printf("Lin1 /= Operator, Value of c = %d\n", c);
	
	/* 	Modulus AND Assignment Operator.*/
	c = 200;
	c %= a;
	printf("Lin1 %%= Operator, Value of c = %d\n", c);
		
	//system("pause");
	return 0;
	
}
