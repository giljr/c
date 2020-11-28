/*
  Struct in C
  
  Struct serves to collect correlated variables;
  
  The C programming language provides a keyword called typedef, 
  which you can use to give a type a new name. 
  
  Description
  Following is an example to define a struct (Date).
  
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
Date:
Day=28
Month=11
Year=2020
Status=0
********************
			
	Author: microgenios.com.br
	Edited by j3
	
	Date: Nov, 28/2020
*/

#include <stdio.h>
#include <stdlib.h>


struct Date
{
     unsigned int day;
     unsigned int month;
     unsigned int year;
     unsigned int status;		
};
	
main()
{
	struct Date dt;
	
    dt.day = 28;
    dt.month = 11;
    dt.year = 2020;
    dt.status = 0;
    
	printf("Date:\nDay=%d\nMonth=%d\nYear=%d\nStatus=%d", dt.day, dt.month, dt.year,dt.status);
	
	return 0;
	
}
