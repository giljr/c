/*
  Struct - 3 ways to declare it!
  
  Description:
  Demo how to declaring struct in C.
  
  Note: uncomment the other methods:)
  
************************
Output:  
COM3; BaudRate=115200
************************
 Author: microgenios.co.br
 Edited by j3
 
 Date: Jun, 21/2020
*/
#include <stdio.h>

typedef struct Serial{
	unsigned char ComPort;
	unsigned int BaudRate;		
}Serial_t;
	
main()
{
	//Three ways to declare structs:
	
	/*
	Serial_t Uart;
	Uart.ComPort = 1;
	Uart.BaudRate = 9600;	
    */
	
	/*
	Serial_t Uart = {2, 57600}; 
	*/
	
	Serial_t Uart =
	{
		.ComPort = 3,
		.BaudRate = 115200
	};
	
	
	printf("COM%d; BaudRate=%d\n", Uart.ComPort, Uart.BaudRate);
	
    //system("pause"); 
	return 0;
	
}


