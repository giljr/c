/*
  Project 21:
  How to make a union of two char as int?
  First Approach - Using Bitwise Operations
  
  Description:
  Demo how to make a union of 2 char into int using Bitwise Operations 
  
  Please take a look at the next Project 22!
  There we will use UNION \o/
  
*************
Output:
 
 AABB
*************
 Author: microgenios.com.br
 Edited by j3
 
 Date: Jun, 21/2020  
*/


#include <stdio.h>
#include <stdlib.h>


unsigned char high = 0XAA;
unsigned char low  = 0XBB;


int main()
{
	
	unsigned short int result;
	
	// How to make a union of these two char as int?
	// result = high + low ?? => 0XAABB;
	
	result = ((high<<8) | low);
	
	/*
	  How does the machine makes the operation?
	  (high << 8) | low
	  0XAA00      | OXBB
	  OXAA00      | AX00BB
	  -----------------------
	  RESULT = 0XAABB	
	*/
	printf("%X", result);
	
	
	//system("pause");
	return 0;
	
}
