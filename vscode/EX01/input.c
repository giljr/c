/*
  Project 90
   
   Conditions With Multiple Booleans Expression in C
   
   Description:
   This code shows 3 ways to receive user data, using fgets, scanf,
   Note that we have to worry about the buffer :?
    
   Software: Vscode(Version: 1.68.1)

   Links:
   How do I get fgets to receive user input?
   https://stackoverflow.com/questions/61637299/how-do-i-get-fgets-to-receive-user-input
   What does %[^\n] mean in C?
   https://stackoverflow.com/questions/39431924/what-does-n-mean-in-c
   C - scanf,printf name and age program [closed]
   https://stackoverflow.com/questions/26790111/c-scanf-printf-name-and-age-program
   VS Code — How to Run C Right Away!
   https://medium.com/jungletronics/vs-code-how-to-run-it-right-away-6fc9e569099a

   
*****************************************************************************************
Output:

Whats your name?        j3
How old are you?        50
You are 50 years old and your name is j3

*****************************************************************************************

Date: 01/07/2022
Editor: j3
*/

#include <stdio.h>

int main () {
   char yourname[20];
   int yourage;
   int c;

   printf("Whats your name?\t");
   fgets(yourname, 50, stdin);

    /* Others 2 forms to get input from user */
    /*First - using a crypt form :/*/    
    
    //scanf("%18[^\n]s", yourname);
    
    
    /*Second - using a line to clears input buffer */
    
    //scanf("%s", yourname);
    //while ((c = getchar()) != '\n' && c != EOF) { } 	

   /* Third - using gets */
   //gets(yourname);
    
    //yourname[19] = '\0';
    //fflush(stdin);

    printf("How old are you?\t");
    scanf(" %d",&yourage);


    printf("You are %d years old and your name is %s\n\n\n", yourage, yourname);

    //system("pause");
    
    return(0);
}