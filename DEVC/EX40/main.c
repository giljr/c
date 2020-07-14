/*
  Project 40 - Reading & Displaying Strings in C
      
  Description
  This Program asks the user to enter until 10 names;
 Then it presents it in the console.
      
    
************************************
Output

Enter the number of names (<10): 5
Enter 5 names:
john
maccarthy
malcomx
Bill
Keil

Entered names are:
john
maccarthy
malcomx
Bill
Keil
************************************

  Edited by J3
  Date: Jul, 13/2020
*/
	#include <stdio.h>
    #include <stdlib.h>
    
    int main()	
	{
		char name[10][20];
     	int i,n;

     	printf("Enter the number of names (<10): ");
     	scanf("%d",&n);

     	/* reading string from user */
     	/* Watch out! scanf("%s[^\n]",name[i]) */
     	printf("Enter %d names:\n",n);
     	for(i=0; i<n; i++)
     	scanf("%s[^\n]",name[i]);

     	/* Displaying strings */
     	printf("\nEntered names are:\n");
     	for(i=0;i<n;i++)
     	puts(name[i]);

     	return 0;	
    	
	}
	
	 
