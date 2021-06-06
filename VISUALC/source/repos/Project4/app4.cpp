/*
  Using for statement

  Description:
  You enter any number and the system tells you if it is even or odd number.
  To halt the process type 0 or any negative number;)
  This is implemented by using for loop. Simple like that

  Iteration statements
  The iteration statements repeatedly execute a statement
  for ( init_clause ; expression(optional) ; expression(optional) ) statement	(3)

  Author: Borin (https://br.linkedin.com/in/borinvini)
  Edited by j3
  date: jun, 12/2020
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, times = 5;
    printf("Please enter any number (To exit, type 0 or any negative number): ");
    scanf_s("%d", &number);

    for (int i = 0; i < times - 1; i++)
    {
        if (number % 2 == 0)
        {
            printf("Even number!\n");
        }
        else
        {
            printf("Odd number!\n");
        }
        printf("Please enter any number (To exit, type 0 or any negative number): ");
        scanf_s("%d", &number);
    }

    //system("pause");
    return 0;

}
