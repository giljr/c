/*
  Project 22:
  How to make a union of two char as int?
  Second Approach - Using UNION \o/
  
  UNION is address memory sharing!   
  There is no conversion. quick access!
  
  Description:
  Demo how to make a union of 2 char into int using UNION. 
  
  Please take a look at the next Project 21!
  There we will use BITWISE OPERATIONS \o/
  
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

union{
	unsigned char buf[2];
	unsigned short int result;
} data;

unsigned char high = 0XAA;
unsigned char low  = 0XBB;


int main()
{
	
	data.buf[0] = low;
	data.buf[1] = high;
	
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
	printf("%X", data.result);
	
	
	//system("pause");
	return 0;
	
}
