/*
   Memory invasion
   https://stackoverflow.com/questions/778334/memory-invasion
   
   	 Buffer Overflow:
	 or buffer overrun, is an anomaly where a program, 
	 while writing data to a buffer, overruns the buffer's 
	 boundary and overwrites adjacent memory locations.
	 
	 Below you see that the reserved buffer was only 5 bytes;
	 But the word ""HELLO!"  needs 7 BYTES:
	 1.[H]
	 2.[E]
	 3.[L]
	 4.[L]
	 5.[O]
	 6.[!]
	 7.[\0] // terminator byte!
	 
	 So the buffer overflow affect the next memory location, which 
	 where located the variable 'count' :/
	 
	 Some anotation about C:
     .The vector name is a number (txt1 is a number);
     .In c variables cannot be declared mixed with methods;
   
*****************************************************************************
Output

HELLO!6487564
See the number is != 5555 -> wrong:/
what happened here was invasion of adjacent memory

HELLO5555
Now the number is = 5555 - > correct:)
Using snprintf we reserve an exact space in memory to store the word HELLO.
*******************************************************************************
 Author : microgenios.com.br
 Edited by j3

 Date: Jun, 20/2020

*/

#include <stdio.h>
//#include <stdlib.h>

int main()
{
	char txt1[6];
	unsigned int count1 = 5555;
    // Here I make a copy of the vector into the variable txt1.
    // But we do not reserve the space to terminator '\0'...
    // This cause the code to overflow, because it doesn't find the final zero to stop...
	sprintf(txt1, "%s", "HELLO!");	
	printf("%s", &txt1);
	printf("%d", &count1);
	printf("\nSee the number is != 5555 -> wrong:/\n");	
	printf("what happened here was invasion of adjacent memory\n\n");
	
	/* To solve this problem you can use snprintf() */
	char txt2[7];
	unsigned int count2 = 5555; 
	snprintf(txt2,sizeof(txt2),"%s", "HELLO!");
	printf("%.*s",sizeof(txt2), txt2);
	printf("%d", count2);
	printf("\nNow the number is = 5555 - > correct:)\n");
	printf("Using snprintf we reserve an exact space in memory to store the word HELLO! plus 'zero'.\n");
	// For terminator '\0',  we add 1 byte and everything is ok!
		
	//system("pause");
	return 0;
	
}
