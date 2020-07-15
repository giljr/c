/*
  Project 45 - Solution for J3 Snack Bar
  
  Description
  
  This program calculates how much each customer spends in a snack bar.
  In essence, this program initialize 3 matrices:
  
  p[1][7] - Price of the Snack bar Products
  q[7][1] - Quantity of each item asked 
  t[1][7] - Total price to pay
  
  Then, Make the math matrices multiplication:
  
  p[1][7]    *   q[7][1]       =  t[1][7]
   _      _                       _      _
  |  5.00 |                      |  5.00 |
  |  8.79 |                      |  8.79 |
  |  9.99 |  * [1,1,1,1,1,1,1] = |  9.99 |
  |  6.89 |                      |  6.89 |
  |  4.80 |                      |  4.80 |
  |  3.49 |                      |  3.49 |
  |_ 4.99_|                      |_ 4.99_|
  
                        Total =  $ 43.95
                        
 Other matrices, like 'seq', 'code' and 'menu' serves only for presentation purpose;
 The user enter Code + Product + Space serially; The user can acummulate the products;
 When done, type 'q' to get the Receipt;
 It is for the academy's elegant solution of Project 31:)
 I'd like to thank Bonin, my tutor o/
 
 
 Printing on the screen a test of the program using 
 the first 3 digits for products and 
 the last 3 digits for quantity of the RU identifier:
 
***********************
Output: (RU 333 6 662)
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
  Date: Jul, 15/2020

*/
#include <stdio.h>

int main()
{
	int seq[1][7] = {1, 2, 3, 4, 5, 6, 7};
	int code[1][7] = {100, 101, 102, 103, 104, 105, 106};
	char menu[7][10] = { "Hot_Dog", "X_Salad", "X_Bacon", "Mix",  "Salad", "Water", "Soda" };
	float p[1][7] = {5.00, 8.79, 9.99, 6.89, 4.80, 3.49, 4.99}, t[1][7] = {0}, debit;
	int q[7][1] = {0,0,0,0,0,0,0};
	int prows = 1, pcolumns = 7, qrows = 7, qcolumns = 1, trows = 1, tcolumns = 7;
	int i,j,k;
	float res = 0, sum = 0;
	int prod = 0;
    int quant = 0;
	
	/*  */
	printf("\n-------------------------------");
	printf("\n:::::::JayThree Snack Bar::::::");	
	printf("\n\t  Welcome!!");
	printf("\n-------------------------------");	
	printf("\n--------------MENU-------------\n");
  	printf("Code\tProduct\t\tPrice\n");
  	printf("-------------------------------\n");
  	
	for(int i = 0; i < 1; i++)
  	{
  		for(int j=0; j < 7; j++)
  		{
			printf("%i\t", seq[i][j]);
			printf("%s\t\t", menu[j] );
			printf("%.2f\t\n", p[i][j] );
		}
  		printf("-------------------------------");	  		 	
	}
	printf("\n\nPlease Choose your Combo:)\nType:Code>Space>Quant>Enter:\n");
	printf("To Quit, type 'q':)\n");
	scanf("%i %i", &prod, &quant);
	
	/* Populating 'q' matrix - quantity of each product indexed */
	/* While loop exit by typing 'q' - Quit */
	/* Product can be acummulated in a single bid */
	while(getchar()!= 'q')
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
        		printf ("You chose: %d x Salad\n", quant);
        		q[4][0] += quant;
        		break;
        	
    	         case 6:
        		printf ("You chose: %d x Water\n", quant);
        		q[5][0] += quant;
        		break;
        	
                case 7:
        		printf ("You chose: %d x Soda\n", quant);
        		q[6][0] += quant;
        		break;
        	
    	        default:
		        printf("Invalid Product:/\n");
				break;
             }
         
	     scanf("%i %i", &prod, &quant);     
	}

    printf("\tGood Choice!\n");	

    /* Calculating all 't' matrix - total to pay = debit */
    int m = 0;	
    for (i=0; i<prows; i++)
		{	
		    for(j=0; j<qcolumns; j++)
			{
				
				for(k=0; k<qrows; k++)
				{
					res += p[i][k] * q[k][j];
					t[i][m] = res;
					m++;
					sum += res;
					res = 0;
					
				}
				debit = sum;
				sum = 0;
		}
	}
    /* Printing the receipt -  print when there is value on 't' index */
    printf ("\n Here you have the ticket:\n\n"); 
    printf("___________Receipt:____________\n");
    printf("Quant\tPrice\tProduct\tTotal\n");
    printf("-------------------------------\n");
    for( i=0; i<trows; i++ )
	{
		for(j=0; j<tcolumns; j++)
		{
			if( t[i][j] != 0)
			{
				printf("%d x\t", q[i][j]);
				printf("%.2f\t", p[i][j]);
				printf("%s\t", menu[j] );
				printf("%.2f\t\n", t[i][j]);
			}			

		}
		printf("-------------------------------\n");
		printf("\t\tTotal = %.2f\t", debit);
		printf("\t\t\n-------------------------------");
		printf("\t\t\n");
	}
    printf("\nThank you for your visit\nand have a good appetite!\n");
    //system("pause");
    return 0;
}
