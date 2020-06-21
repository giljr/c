/*
  Struct in C
  
  Struct serves to collect correlated variables;
  
  The C programming language provides a keyword called typedef, 
  which you can use to give a type a new name. 
  
  Description
  Following is an example to define a struct (Serial).
  
  Typedef is a keyword that is used to give a new symbolic name 
  for the existing name in a C program. 
  This is same like defining alias for the commands.
  
  Variable for the structure can be declared in two ways.
	1st way  (First the typedef, then the struct):

			typedef struct Serial Serial_t;
			
			struct Serial{
			unsigned char ComPort;
			unsigned int BaudRate;		
			};
	
			
	2nd way (all-in-one-step):

			typedef struct Serial{
			unsigned char ComPort;
			unsigned int BaudRate;		
			}Serial_t;
			
********************
Output
COM1; BaudRate=9600
********************
			
	Author: microgenios.com.br
	Edited by j3
	
	Date: Jun, 21/2020
*/

#include <stdio.h>
#include <stdlib.h>

/*
typedef struct Serial Serial_t;

struct Serial{
	unsigned char ComPort;
	unsigned int BaudRate;		
};
*/


typedef struct Serial{
	unsigned char ComPort;
	unsigned int BaudRate;		
}Serial_t;
	
main()
{
	/* 
	 struct Serial Uart;
	 //Using typedef above:) 
	*/
	Serial_t Uart;
	Uart.ComPort = 1;
	Uart.BaudRate = 9600;
	printf("COM%d; BaudRate=%d\n", Uart.ComPort, Uart.BaudRate);
     
    //system("pause"); 
	return 0;
	
}
