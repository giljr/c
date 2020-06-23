/*
 Project 05
  Multi-file programs - How to Use it!
  
  Multi-file programs. A large C or C++ program should be divided into multiple files. 
  This makes each file short enough to conveniently edit, print, etc. 
  It also allows some of the code, e.g. utility functions such as linked list 
  handlers or array allocation code, to be shared with other programs.
  
  Description  
  The system is a demo for how to split your project into especifics function sheets.
  This is a Good Programming Practice to follow!
  
  Please see how to encapsulate each .h file, by using precompilation directives:
  		
		#ifndef __NAME__OF__THE SHEET___
		#define __NAME__OF__THE SHEET___
		(...)
		#endif
		
   Structure:
	       ----  sys.h ------          High level sheet
	     |                    |
	    v                    |
	main.c                  |
	    |                  v
	     ------------> lcd.c & lcd.h
	   |-----------> calc.c & calc.h
	   
************************
Output
	lcd_init()
	lcd = 45
	LCD COUNT = 0
************************
	   
	Author: microgenios.com.br
	Edited by j3
	
	Date: Jun, 18/2020
*/
#include "sys.h "
#include "lcd.h"


main(void)
{
	Add();
	lcd_init();
	lcd_write(45);
	printf("LCD COUNT = %d\n", lcd_read_count());
	//system("pause");
	return 0;
}
