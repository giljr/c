/*
  
  Chained Struct - How To Declared Nested Struct
  
  Description
  This system create another struct and 
  chained struct together.
   

************************
Output:  
 Serial Communication Port
************************
 Author: microgenios.co.br
 Edited by j3
 
 Date: Jun, 21/2020
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Buf {
	char buffer[200]; 
}Buf_t;

typedef struct Serial{
	const char * ComPort;
	unsigned int BaudRate;
	Buf_t Config;		
}Serial_t;
	
main()
{
	Serial_t Uart = 
	
	{
		.ComPort = "COM5",
		.BaudRate = 9600,
		.Config = 
		{
			.buffer = " Serial Communication Port "
			
		}	
		
	};
	
	/*
	Serial_t Uart;
	// Copy to buffer variable the string 'HELLO'
	sprintf(Uart.Config.buffer, "%s", "HELLO");
	*/
	
	// Now print the variable buffer
	printf("%s", Uart.Config.buffer);
	
	//printf("COM%d; BaudRate=%d\n", Uart.ComPort, Uart.BaudRate);
	
    //system("pause"); 
	return 0;
	
}



