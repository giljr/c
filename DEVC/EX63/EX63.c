/*   Project 63 
  
  Struct in C - Initiate objects by Copy
  
  Here we will need to create a method that initializes an object that guarantees 
  an initial condition of date object since the compiler only guarantees 
  allocation of the address. In the allocated address there may be garbage 
  in the memory and therefore we must guarantee a safe initialization 
  for our object.
  We will create a method date_modify() with that responsibility.
  Then we make a method to securely initialize each member: date_init(struct Date dt)
  Then if we want to print the date we must first modify the date security by calling this function:
  void date_print(const struct Date dt)
  When you pass a largestruct, the compiler generates code to make a copy of that struct if you pass 
  it by value. This wastes CPU cycles and may create a situation when your program runs out of 
  stack space, especially on hardware with scarce resources, such as embedded microcontrollers.
  
  Please, see the next Project 64!
  			
********************
Output
Date:
Day=28
Month=11
Year=2020
Status=0
********************
	
  GitHub Repo:
  https://github.com/giljr/c
  Webpage:
  https://medium.com/jungletronics/data-structure-struct-in-c-caf48ae3c1b2		
  
  Inspired by: microgenios.com.br
  Edited by j3
	
  Date: Nov, 28/2020
*/



#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

struct Date
{
     unsigned int day;
     unsigned int month;
     unsigned int year;
     unsigned int status;		
};

struct Date date_modify(struct Date dt, int day, int month, int year, int status)
{
     dt.day = day;
     dt.month = month;
     dt.year = year;
     dt.status = status;
     
     if(validateUART())
         {
            dt.status = 1;
         } else {
            dt.status = 0;
         }  
     return dt;
}

struct Date date_init(struct Date dt)
{
     dt.day = 28;
     dt.month = 11;
     dt.year = 2020;
     dt.status = 1;
     return dt;
}

void date_print(const struct Date dt)
{
	printf("Date:\nDay=%d\nMonth=%d\nYear=%d\nStatus=%d", dt.day, dt.month, dt.year,dt.status);
}

int validateUART() 
{
	// Hardware Serial initialization stake goes here!
	return TRUE;
}
	
main()
{
	struct Date clock;
	//UART_Init(9600);
	
    clock = date_init(clock);
     
    clock = date_modify(clock, 28, 11, 2020, TRUE);
    
	//clock.day = 28;
    //clock.month = 11;
    //clock.year = 2020;
    //clock.status = 0;
    
    date_print(clock);
    
	//printf("Date:\nDay=%d\nMonth=%d\nYear=%d\nStatus=%d", dt.day, dt.month, dt.year,dt.status);
	
	return 0;
	
}
