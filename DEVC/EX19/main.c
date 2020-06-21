/*
   How to Align The Struct
   
   Description:
   Demo of How to align the struct.
   Use #pragma pack(1) precompilation directive!
   
   Please see notes below.

**********************
Output:
Uart consumes 5 Bytes
**********************

  Author: microgenios.com.br
  Edited by j3
  
  Date Jun, 21/2020

*/

#include <stdio.h>
#include <stdlib.h>

/*
  If you comment '#pragma pack(1)'
  The struct will consumes 8 bytes
  
  The '#pragma pack(1)' forces the compilator to align the struct
  
  If you run with '#pragma pack(1)' 
  The struct will consumes 5 Bytes
  
  Try it for yourself!
  
  Note: when you align the structure you gain in bytes :)
  		but lose in access time :/
*/

#pragma pack(1)

typedef struct Serial {
	unsigned char ComPort; // X B B B 	
	unsigned int BaudRate; // X X X X
}Serial_t;


int main()
{
	Serial_t Uart = 
	{
		.BaudRate = 9600,
		.ComPort = 0
	};
	
	printf("Uart consumes %d Bytes", sizeof(Uart));

	
	//system("pause");
	return 0;
}
