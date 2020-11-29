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
	
  Date: Nov, 29/2020
*/



#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct Date
{
     unsigned int day;
     unsigned int month;
     unsigned int year;
     unsigned int status;		
};

struct Date date_init(struct Date dt)
{
     dt.day = 01;
     dt.month = 11;
     dt.year = 2020;
     dt.status = 1;
	 return dt;
}

struct Date date_modify(struct Date dt, int day, int month, int year)
{
     
	 dt.day = day;
     dt.month = month;
     dt.year = year;
     
     if (validate())
	 {
	 	dt.status = TRUE;
	 } 
	 else
	 {
	 	dt.status = FALSE;
	 }  
	 
     return dt;
}

int validate() 
{
	// Hardware Serial initialization stake goes here!
	return FALSE;
	//return TRUE;
}

void date_print(const struct Date dt)
{
	if(dt.status)
	{
        printf("Date:\nDay=%d\nMonth=%d\nYear=%d\nStatus=%d\n\n", dt.day, dt.month, dt.year,dt.status);
	} 
	else
	{
	  	printf("Error: Object initialization Problem:\\\nPlease, Verify your Serial Port of your Iot Hardware.\n");		
	}

}

main()
{
	struct Date clock;
	//UART_Init(9600);
	
    clock = date_init(clock);
    date_print(clock);
     
    clock = date_modify(clock, 28, 11, 2020);    
	//clock.day = 28;
    //clock.month = 11;
    //clock.year = 2020;
    //clock.status = 0;  
	  
    date_print(clock);    
	//printf("Date:\nDay=%d\nMonth=%d\nYear=%d\nStatus=%d", dt.day, dt.month, dt.year,dt.status);
	
	return 0;
	
}
