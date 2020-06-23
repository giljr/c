/*
 Project 12
 How to Compare 2 strings in C
 
 Description:
 This program accepts two strings and return
 if them are igual or not :)
 
 Using 'typedef'
 Please see: <stdint.h>
 https://pubs.opengroup.org/onlinepubs/009695399/basedefs/stdint.h.html
 
 There is no Boolean in C.
 We declare BOOL type as char.
 Define TRUE & FALSE as 1 and 0 :)
 
 *******************
 Output:
  Different
 *******************
 
 Author: microgenios.com.br
 Edited by j3  
 
 Date: Jun, 10/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef signed int int32_t;
typedef unsigned char BOOL;

#define TRUE 1
#define FALSE 0

BOOL compare (char * str1, char * str2)
{
	if (strcmp(str1, str2)==0)
		return TRUE;
	else
		return FALSE;
}

int32_t main(void)
{
	if(compare ("HELLO", "HI"/*"HELLO"*/)==TRUE)
		
		printf(" The Same " );
		
		else
			printf(" Different " );
	
	//system("pause");
	return 0;
}
