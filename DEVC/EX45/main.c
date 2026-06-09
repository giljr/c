/*
Project 45 - Solution for J3 Snack Bar
  
Description
  
This program calculates how much each customer spends in a snack bar.
In essence, this program initializes 3 matrices:
  
p[1][7] - Price of the Snack bar Products
q[7][1] - Quantity of each item asked 
t[1][7] - Total price to pay
  
Then, Make the math matrices multiplication:
  
     p[1][7]        *    q[7][1]        =    t[1][1]
  
     Prices (p)     *   Quantities (q)  =   Totals (t)

[ 5.00  8.79 ...]   *      [ 2 ]        =  [ 10.00  8.79 ...] => Grand Total = $18.79
                           [ 1 ]          
                            ...    
                        
 Additional matrices such as 'seq', 'code', and 'menu' are used only for menu 
presentation and receipt printing.

Ordering Process

The user enters a product code followed by a quantity.
Multiple orders of the same product are accumulated.
When finished, the user types 'q' to print the receipt.
The receipt shows the quantity, unit price, item total, and grand total.

This solution was designed as an elegant matrix-based implementation of Project 31,
combining arrays, matrices, loops, and basic data processing concepts.

Example Test

This produces the demonstration receipt shown below.
 
*****************************************************

-------------------------------
:::::::JayThree Snack Bar::::::
          Welcome!!
-------------------------------
--------------MENU-------------
Code    Product         Price
-------------------------------
1       Hot_Dog         5.00
2       X_Salad         8.79
3       X_Bacon         9.99
4       Mix             6.89
5       Salad           4.80
6       Water           3.49
7       Soda            4.99
-------------------------------

Please Choose your Combo:)
Type:Code>Space>Quant>Enter:
To Quit, type 'q':)
3 6
You chose: 6 x X-Bacon
3 6
You chose: 6 x X-Bacon
3 2
You chose: 2 x X-Bacon
q
        Good Choice!

 Here you have the ticket:

___________Receipt:____________
Quant   Price   Product Total
-------------------------------
14 x    9.99    X_Bacon 139.86
-------------------------------
                Total = 139.86
-------------------------------

Thank you for your visit
and have a good appetite!
***********************
  Editor J3
  Date:    Jul, 15/2020
  Updated: Jun, 09/2026
  
  I'd like to thank Prof. Borin, Me.(https://br.linkedin.com/in/borinvini)  
  o/
*/
#include <stdio.h>

int main()
{
    int seq[1][7] = {1, 2, 3, 4, 5, 6, 7};
    int code[1][7] = {100, 101, 102, 103, 104, 105, 106};

    char menu[7][10] =
    {
        "Hot_Dog",
        "X_Salad",
        "X_Bacon",
        "Mix",
        "Salad",
        "Water",
        "Soda"
    };

    float p[1][7] = {5.00, 8.79, 9.99, 6.89, 4.80, 3.49, 4.99};
    float t[1][7] = {0};
    float debit = 0;

    int q[7][1] = {0};

    int trows = 1;
    int tcolumns = 7;

    int i, j, k;
    int prod = 0;
    int quant = 0;

    /* Menu on screen splash */
    printf("\n-------------------------------");
    printf("\n:::::::JayThree Snack Bar::::::");
    printf("\n\t  Welcome!!");
    printf("\n-------------------------------");
    printf("\n--------------MENU-------------\n");
    printf("Code\tProduct\t\tPrice\n");
    printf("-------------------------------\n");

    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("%i\t", seq[i][j]);
            printf("%s\t\t", menu[j]);
            printf("%.2f\t\n", p[i][j]);
        }
        printf("-------------------------------");
    }

    printf("\n\nPlease Choose your Combo:)\n");
    printf("Type: Code<space>Quantity<Enter>\n");
    printf("To Quit, type 'q'\n");

    scanf("%i %i", &prod, &quant);

    /* Populating q matrix - quantity of each product indexed */
    while (getchar() != 'q')
    {
        switch (prod)
        {
            case 1:
                printf("You chose: %d x Hot Dog\n", quant);
                q[0][0] += quant;
                break;

            case 2:
                printf("You chose: %d x X-Salad\n", quant);
                q[1][0] += quant;
                break;

            case 3:
                printf("You chose: %d x X-Bacon\n", quant);
                q[2][0] += quant;
                break;

            case 4:
                printf("You chose: %d x Mix\n", quant);
                q[3][0] += quant;
                break;

            case 5:
                printf("You chose: %d x Salad\n", quant);
                q[4][0] += quant;
                break;

            case 6:
                printf("You chose: %d x Water\n", quant);
                q[5][0] += quant;
                break;

            case 7:
                printf("You chose: %d x Soda\n", quant);
                q[6][0] += quant;
                break;

            default:
                printf("Invalid Product :/\n");
                break;
        }

        scanf("%i %i", &prod, &quant);
    }

    printf("\tGood Choice!\n");

    /* Element-by-element multiplication:
       t[0][k] = p[0][k] * q[k][0]
    */
    debit = 0;

    for (k = 0; k < 7; k++)
    {
        t[0][k] = p[0][k] * q[k][0];
        debit += t[0][k];
    }

    /* Printing the receipt */
    printf("\nHere you have the ticket:\n\n");
    printf("___________Receipt:____________\n");
    printf("Quant\tPrice\tProduct\t\tTotal\n");
    printf("----------------------------------------\n");

    for (i = 0; i < trows; i++)
    {
        for (j = 0; j < tcolumns; j++)
        {
            if (t[i][j] != 0)
            {
                printf("%d x\t", q[j][0]);
                printf("%.2f\t", p[i][j]);
                printf("%s\t\t", menu[j]);
                printf("%.2f\n", t[i][j]);
            }
        }
    }

    printf("----------------------------------------\n");
    printf("\t\tTotal = %.2f\n", debit);
    printf("----------------------------------------\n");

    printf("\nThank you for your visit\n");
    printf("and have a good appetite!\n");

    return 0;
}
