/*
   Project 54 - More advanced topics about Pointer & Array
   
   Description:
   We'll understand the basics behind pointers and how to dereference 
   a pointer and we also learned a little bit more about arrays    :)
   
   Please, refer to the below comments :)

******************************************************************
Output:

6487552
Star Wars Episode V:
The string modified bt strcpy(): String copied to movie1
1
Star Wars: Episode VII
Star Wars: Episode VII - The Force Awakens

******************************************************************
     
   Inspiration & Credits to:   
   thenewboston
   C Programming Tutorial - 45 - Strings and Pointers
   https://youtu.be/-9fqo94G6YU
   
   Edited by J3
   Date: Jul, 19/2020 

*/

#include <stdio.h>
#include <string.h>

int main()
{
	//char movie1[] = "Star War : The Return!";
	char movie1[] ="Star Wars Episode V:";
	/* 
	   Movie1 was essentially a special type of variable; 
	   in other words it acted like a pointer.
	   
	   it's not exactly a variable; it's actually a constant!
	   See its address:
	*/
	
	printf("%d\n", &movie1);
	
	/* A constant we can't change it!
	
	   // Like this:	   
	   movie1 = "Star Wars Episode V: The Empire";
	
	   // Or like this:
	   movie1[21] = "The Empire"; 
	   puts(movie1);
	   
	   Those commands above will not work:/ 
	*/
	  

	/*
	  This pointer Movie1 is basically going
	  to point to the first elements address;
	  
	  We're trying to change the pointer; 
	  
	  The pointer is actually a constant and
	  we can't change those so even if we
	  added those brackets afterward and try
	  to change your movie1... 
	  this again... uh-uh not happening :/
	  
	  We need to use a special function like
	  strcpy function (String Copy) or 
	  what access each element individually one 
	  by one as below:
	*/
	
	char newstrig[] = "String copied to movie1";
	// strcpy(destination, source)
    	strcpy(movie1, newstrig);
	printf("The string modified by strcpy(): %s\n", movie1);
	
	printf("%c\n", movie1[22]); // This will print '1', the last char of movie1
		
 	/*
 	  However it's kind of a tedious way to work with strings.	  
	*/
	
	/*	  
	  Would be awesome if we could just work
     	  with these strings like a normal variable?
      
      	  Check it out!
	*/
	
	char * movie2 = "Star Wars: Episode VII";
	
	/* 
	  Now Movie2 is not a constant!
	  What we did is we made this a pointer variable; 
	  so whenever something is a variable we can indeed change it; 
	  in other words we can print this out or put on 
	  the left-hand side of the equal sign.
	  And it woks ;)
	*/
	
	puts(movie2);
	movie2 = "Star Wars: Episode VII - The Force Awakens";
	puts(movie2);
	
	/*
	  So whenever you make a pointer to a string 
	  this pointer is a variable 
	  so you can easily put it on the left hand side.
	*/
	
	//system("pause");
	return 0;
	
	/*
	  So the key concept takeaway from this
	  code is whenever you just make a
	  very simple array of characters it's
          hard to change because that name of the
          array is a constant and we can't easily
          change constants; 
      
	  However whenever we make a pointer to 
	  a string, this pointer is a variable, 
	  so you can easily put it on the left hand 
	  side since all this is doing is its storing
          the address of something so then we can
          treat it like a string :)	
      
          thenewboston, Thanks you!!!!!!!!!!!!!!!!!!
	*/	
}
