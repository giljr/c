/*
  Project 57 - Strtok - How to Use It!
  Description:
  The C library function char *strtok(char *str, const char *delim) 
  breaks string str into a series of tokens using the delimiter delim.
  
  Stringtok tokenized strings that means it takes a string and splits 
  it up into individual chunks using some delimiter that you provide;
  
  Each call to strtok returns one token until there are no more 
  and then it returns null;
  
  char *strtok(char *str, const char *delim)
  Parameters:
   str -   The contents of this string are modified and broken 
           into smaller strings (tokens).	
   delim - This is the C string containing the delimiters. 
           These may vary from one call to another.
***************************************************************
Output:

This is
 www.medium.com\jungletronics
 website
This is what remains after the call strtok(): This is
***************************************************************
  
  Inspiration & Credits:
  Jacob Sorber
  Parsing C strings with strtok.
  ( https://youtu.be/a8l8PwCzw20 )
  
  Edited by J3
  Date: Jul, 19/2020  
*/
#include <stdio.h>
#include <string.h>

#define BUFLEN 64

int main()
{
   char str[BUFLEN] = "This is - www.medium.com\\jungletronics - website";
   const char s[2] = "-";
   char *token;
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
      printf( "%s\n", token );

      token = strtok(NULL, s);
      /* when I pass in NULL I am basically saying: hey remember
      where you left off on the last one and keep going 
	  till you see another comma, okay?
      */
   }
	
	/* One think to keep in mind is that strtok is destructive!*/
	printf("This is what remains after the call strtok(): %s\n", str);	
	
	/* 
	 If you're gonna use strtok you want to make sure that if you 
	 need that original string to be intact that you make a copy 
	 of it before you start calling strtok. That's one important thing!
	 */
	 
	 /*
	  Another important think is that strtok is not thread safe:/
	  There's strtok underscore R (strtok_r) and that's basically underscore 
	  R is the reentrant version and so that version if you look 
	  has an additional has an additional pointer which keeps track of
      where it left off.
	 */
	
	system("pause");
	return 0;
	
}

