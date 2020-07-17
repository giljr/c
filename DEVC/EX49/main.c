
/*
  Project 49 - Doing Math With Letter:)
  
  Description
  
  This program simply gets 2 input integer (between 33-127) 
  from the user and   make math operations with this 2 number.
  Presents the result in the console.
  
  ASCII is a 7-bit code, meaning that 128 characters (2^7) are 
  defined. The code consists of 33 non-printable and 95 printable 
  characters and includes both letters, punctuation marks, 
  numbers and control character.
  
******************************************************************
Output:

Please, enter 1 integers between 33-127:
65
65 is character A
Please, enter 1 integers between 33-127:
35
35 is character #

65(A) + 35(#) = 100(W)

******************************************************************
  Edited by J3
  Date Jul, 17/2020
*/
#include <stdio.h>

char letter1;
char letter2;
int res;

int main()
{
	printf("Please, enter 1 integers between 33-127:\n");
	scanf("%i", &letter1);
	printf("%d is character %c\n", letter1, letter1);
	
	printf("Please, enter 1 integers between 33-127:\n");
	scanf("%i", &letter2);	
	printf("%d is character %c\n", letter2, letter2);
	
	char mathz = 'A' + '#' + '\0';
	res = letter1 + letter2;
	printf("\n%i(%c) + %i(%c) = %i(%c)", letter1, letter1, letter2, letter2, res, res);

	//system("pause");
	return 0;
	
}
