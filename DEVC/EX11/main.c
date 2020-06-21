/*
  Studing C
  Pointer - #HowToUse
  
  Description
  The program simple scan the array 'txt' variable
  and prints it out:)
  
  Pointers in C language is a variable that stores/points 
  the address of another variable. A Pointer in C is used 
  to allocate memory dynamically i.e. at run time.
  
  Pointer in C is an array of characters with '\0' as terminator.
  
  ***********************
  Output:
  ABC
  ***********************
  
  Author: microgenios.com.br
  Edited by j3
  
  Date: Jun, 20/2020  
*/
#include <stdio.h>

void print(char * txt )
{
	while(*txt != 0)
	{
		printf("%c", *txt); 		 // c = character
		txt++;
	}
}

int main()
{
	char txt[] = {'A', 'B', 'C', 0}; // the same as "ABC"
	/*
	  txt[0] -> 120 -> 'A'
	  txt[1] -> 120 -> 'B'
	  txt[2] -> 120 -> 'C'
	  txt[3] -> 120 -> '\0'
	*/
	  
	print(&txt); 					 // or txt, or &txt[0]
	
	//system("pause");
	return 0;
}
