/*
  Using do-while statement

  Iteration statements
  The iteration statements repeatedly execute a statement.

  do statement while ( expression ) ;	(2)
   
  author: j3
  date: jun, 12/2020
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int number;
    printf("Please enter any number (To exit, type 0 or any negative number): ");
    scanf_s("%d", &number);

    do
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
    } while (number > 0);

    //system("pause");
    return 0;

}