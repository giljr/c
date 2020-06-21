/*
  How to Use ARROWS - More elegant solution to Point to a element of the struct
   
  Description:
  Demo of How to Use ARROWS!
   
  Please see notes below.
**********************
Output:

Uart Address = 6487568
BaudRate = 9600; ComPort = 0
**********************
  Author: microgenios.com.br
  Edited by j3
  
  Date Jun, 21/2020
*/

#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

typedef struct Serial {
	unsigned char ComPort; // X B B B 	
	unsigned int BaudRate; // X X X X
}Serial_t;


void CopyStruct(Serial_t * Uart)

{
	// First point to Uart, then access the elements inside
	//printf("BaudRate = %d; ComPort = %d\n", (*Uart).BaudRate,(*Uart).ComPort );
	
	// Using ARROWS - More elegant solution, right?	
	printf("BaudRate = %d; ComPort = %d\n", Uart->BaudRate, Uart->ComPort );
}

int main()
{
	Serial_t Uart = 
	{
		.BaudRate = 9600,
		.ComPort = 0
	};
	
	printf("Uart Address = %d\n", &Uart);
	
	CopyStruct( &Uart);

    
	
	//system("pause");
	return 0;
}
