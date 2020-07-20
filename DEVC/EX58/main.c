/*
   Project 58 - Finding the Frequency of Characters in a String
   
   Description:
   The program symple asks for a string of characters, ie "aaabbb";
   Then it counts the frequency of each letters in that string;
   The input must be in the range of 'a' to 'z'(97 to 122 ASCII);
   All others letter are ignorated :/
   
   Here is the essence of the algorithm:
   
   1)Create c = 0 (letters iterator); load string array;
   2)while loop string[c] != 0 (as every string have its '\0' terminator);
   3)Create a counter[c];
   4)This counter has 26 slots and it is zero based, matching 
     the the number of letters; how to iterate through each letter?
   5)Create an x number, load it with the number returned by string[c] 
     and subtract that by 'a' (which value is 97).
     So, if string[c] returns is 97, then 97 - 97 = 0 which result
	 is saved in count; Now, count is indexed like this:
	 
   letters['a','b','c' ... 'x', 'y', 'z' ]   --> 26 letters
	 count[ 0 , 0,  0  ...  0,   0,   0  ]   --> 26 counters
     index[[0],[1] [2] ... [23],[24],[25]]   --> 26 indexes
    string[[0],[1] [2] ... [23],[24],[25]]   --> 26 characters
    
    6)Now each loop update the counter until the '/0' occurs.
    
	  And That's it!
***************************************************************
Output:
Enter a string
abbcccddddzzzzz
a occurs 1 times in the string.
b occurs 2 times in the string.
c occurs 3 times in the string.
d occurs 4 times in the string.
z occurs 5 times in the string.

***************************************************************
   Credits: 
   https://www.programmingsimplified.com/c-program-find-characters-frequency
   
   Edited by J3
   Date: Jul, 20/2020
*/

#include <stdio.h>
#include <string.h>

int b;
char string[100];
int i, j;

int main()
{

   	int c = 0, count[26] = {0}, x;
   	printf("Enter a string\n");
   	gets(string);
   
   	while (string[c] != '\0') 
   	{
   	/** Considering characters from 'a' to 'z' and ignoring others. */

		if (string[c] >= 'a' && string[c] <= 'z') 
		{
		 	x = string[c] - 'a';
         	count[x]++;
    	}
        c++;
   	}

   	for (c = 0; c < 26; c++)
		
		if(count[c] != 0)
     	{
     		printf("%c occurs %d times in the string.\n", c + 'a', count[c]);
	 	}
	 
   	return 0;
}
