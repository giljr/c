/*
  Project 23 - Demo for Scape sequences in C:
  
*******************************************************************
Output:

 DEMO FOR ESCAPE SEQUENCES IN C

-------------------------------

1 - The use of newline (\n) & scaping double quotes (\"):
"My formula for success?
Rise early, work late, strike oil."
J. Paul Getty

2 - Returning carriage with \r:
Right after it...


3 - The use of form-feed character \f...

Right after it...

4 - The use of horizontal tab \t...     Right after it...

5 - The use of vertical tab \v...Right after it...
This is getting awkward, isn't it?...

6 - Inserting a bell sound (alert):
Be careful!!

7 - Inserting a question mark (?):
The use of question mark \?
...For what?

8 - Inserting a double quote("):
"Sharing's carring!"

9 - Inserting a single quote('):
'That is amazing! That is so cool!'

10 -Inserting backslash(\):
Please see this link:
         \media.com\jungletronics
                 for more info:) Bye!
*******************************************************************
 
 Author j3
 
 Date: Jun, 21/2020
*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	printf("DEMO FOR ESCAPE SEQUENCES IN C\n\n");
	printf("-------------------------------\n\n");
	
	
	/* \n Represents a newline character & How to scape double quotes*/
	printf("1 - The use of newline \(\\n\) & scaping double quotes \(\\\"\):\n");
	printf("\"My formula for success?\nRise early, work late, strike oil.\"\nJ. Paul Getty\n\n");
	
		
	/* \r Represents a carriage return */
	printf("2 - Returning carriage with \\r:\r\n");	
	printf("Right after it...\n\n");
	
	/* \f Represents a form-feed character */
	/* Frankly I have never encountered its use whether in the classroom or in the wild */
	printf("\n3 - The use of form-feed character \\f...\f\n\n");
	printf("Right after it...\n\n");
	
	/* \t Represents a horizontal tab */
	printf("4 - The use of horizontal tab \\t...\t");
	printf("Right after it...\n\n");
	
	/* \v Represents a vertical tab */
	printf("5 - The use of vertical tab \\v...\v");
	printf("Right after it...\n");
	printf("This is getting awkward, isn't it?...\n");
	
	/* \a Inserts a bell (alert) character */
	printf("\n6 - Inserting a bell sound (alert):\n");
	printf("Be careful!!\n\a\n");

	/* \? Inserts a question mark (?) */
	printf("7 - Inserting a question mark (?):\n"); 
	printf("The use of question mark \\?\n...For what\?\n\n");
	
	
	/* \" Inserts a double quote (") */
	printf("8 - Inserting a double quote\(\"\):\n");
	printf("\"Sharing's carring!\"\n\n");
	
		/* \" Inserts a single quote (') */
	printf("9 - Inserting a single quote\(\'\):\n");
	printf("\'That is amazing! That is so cool!\'\n\n");
	
	/* \\ Inserts a backslash (\) */
	printf("10 -Inserting backslash\(\\\):\n");
	printf("Please see this link:\n\t \\media.com\\jungletronics\n\t\t for more info:) Bye!\n\n");
	
	
	
	return 0;
}
