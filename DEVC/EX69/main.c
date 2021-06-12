/* Project 69
 Title:  A Pointer to a Pointer Exercise

 This program show:
 
 How to use pointer of pointer in C Language.

 Error Compiling the code o Dev ++?

 How to resolve  this error: 


 ‘for’ loop initial declarations are only allowed in C99 or C11 mode) ?


 Configure Dev C++ to use the ansi iso c99 standard (recommended to avoid further compatibility issues with the exercises in the book)
	
  1- On the dev c++ toolbar click on Tools, 
  2- then click on Compiler Options , it will open a little window;
  3- Click on the Code Generation tab, where it says Language Default (-std) select for ISO C99 and click Ok

 Now your code will work, and this error message will no longer appear;

 ***************************** 
  Output:
  
 words = 4225568, words[0] = 4210688, words[1] = 4210693, words[2] = 4210697
 multiple indirection example
 zero
 one
 two
 ppc = 4225568

 Looping
 z pc = 4210689
 e pc = 4210690
 r pc = 4210691
 o pc = 4210692

 o pc = 4210694
 n pc = 4210695
 e pc = 4210696

 t pc = 4210698
 w pc = 4210699
 o pc = 4210700

 Loop End
 ppc = 4225584
 ***************************** 

  	Author: Huw Collingbourne
  	Edited: j3
	 Udemy: Advanced C Programming: Pointers
	  link: https://www.udemy.com/course/advanced-c-programming-pointers
  	  date: jun, 11/2021	
 
*/

#include <stdio.h>

#define LENGTH 3

char *words[LENGTH];		        // some strings

int main(int argc, char **argv) {
	char *pc;			// a pointer to a character
	
	char **ppc;			// a pointer to a pointer to a character
                                        // The asterisk(*), which is sometimes called the  
					// deferencing operator or the indirection operator, 
					// gives me access to the data it is stored at that address
	                                // Remember: (&) gives me reference to an address
                                        //           (*) gives me access    to the data  									
	/* initialize our string array  */
	words[0] = "zero";
	words[1] = "one";
	words[2] = "two";
	
	printf("words = %d, words[0] = %d, words[1] = %d, words[2] = %d\n", words, words[0], words[1] , words[2]);
	
	printf("multiple indirection example\n");
	int i = 0;
	for (i; i < LENGTH; i++) {
		printf("%s\n", words[i]);
	}


	/*
	* B: a pointer to an array of strings
	*    - the same as a pointer to a pointer to a character
	*
	*/
	ppc = words;
	printf("ppc = %d\n\n", ppc);	// initialize the pointer to a pointer to a character
	printf("Looping\n");
	for ( i = 0; i < LENGTH; i++) {	// loop over each string
		ppc = words + i;
		pc = *ppc;		
		while (*pc != 0) {	// process each character in a string
		printf("%c ", *pc);	// print out each character of the string individually
		pc += 1;
		printf("pc = %d\n", pc);			
	        }
		
		//printf("\n");
	}
	printf("Loop End\n");
	
        printf("ppc = %d\n", ppc);
	return 0;
}
