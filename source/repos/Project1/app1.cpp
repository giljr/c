/*
  Using if statement

  Description:
  You enter any number and the system tells you if it is even or odd number.

  Selection statements (if):    
  The selection statements choose between one of several statements depending on the value of an expression.
  
  if ( expression ) statement_1
  if ( expression ) statement_1 else statement_2

  Author: Borin (https://br.linkedin.com/in/borinvini) 
  Edited by j3
  date: jun, 12/2020
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Please enter any number: ");
    scanf_s("%d", &number);

    if (number % 2 == 0)
    {
        printf("Even number!\n");
    }
    else
    {
        printf("Odd number!\n");
    }

    //system("pause");
    return 0;

}
