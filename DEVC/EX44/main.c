/*
  Project 44 - Initializing 3 Matrices & Multyply it all
  
  Description
  This program initialize 3 matrices:
  p[1][7] - Price of the Snack bar Products
  g[7][1] - Quantity of each item asked 
  t[1][7] - Total price to pay, then:
  
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
   
 It is for the solution of Project 31:)
 
***********************
Output:
_______Receipt:________
10      Hot_Dog 50.00
10      X_Salad 87.90
10      X_Bacon 99.90
10      Mix     68.90
10      Salad   48.00
10      Water   34.90
10      Soda    49.90
-----------------------
        Total = 439.50
-----------------------
***********************
  Editor J3
  Date: Jul, 13/2020

*/
#include <stdio.h>

int main()
{
	char menu[7][10] = { "Hot_Dog", "X_Salad", "X_Bacon", "Mix",  "Salad", "Water", "Soda" };
	float p[1][7] = {5.00, 8.79, 9.99, 6.89, 4.80, 3.49, 4.99}, t[1][7] = {0}, debit;
	int q[7][1] = {10,10,10,10,10,10,10};
	int prows = 1, pcolumns = 7, qrows = 7, qcolumns = 1, trows = 1, tcolumns = 7;
	int i,j,k;
	float res = 0, sum = 0;

	//printf("\n");
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
		
	/* printing the receipt */
	printf("_______Receipt:________\n");
	for( i=0; i<trows; i++ )
	{
		for(j=0; j<tcolumns; j++)
		{
			printf("%d\t", q[i][j]);
			printf("%s\t", menu[j] );
			printf("%.2f\t\n", t[i][j]);
		}
		printf("-----------------------\n");
		printf("\tTotal = %.2f\t\t", debit);
		printf("\t\t\n-----------------------");
		printf("\t\t\n");
	}
	//system("pause");
	return 0;
}
