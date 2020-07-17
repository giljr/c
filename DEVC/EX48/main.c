/*
  Project 48 - Pluviometric Controller
  
  Description
  
  Make an algorithm in c that receives as input the maximum amount 
  in millimeters that a water reservoir supports. 
  Enter the amount of rain in your region monthly and also 
  the consumption during those months. 
  If the reservoir is full, notify; If empty, let me know too.
  Use the RU to take the final test:)
  
  Here is the essence of the algorithm:
  ---------------------------------------------------------
  Rain | Reservoir | Reservoir |  Consumption | Reservoir
  (mm) |   Init    |   Partial |     (mm)     |    Final
  (m1) |   (m2)    |     (m3)  |     (m4)     |     (r)   <---Matrices
  ----------------------------------------------------------
   m1   +   m2      =     m3    -      m4     =       r 
   
***********************************************************
Output:  (RU 3336662)

What is the capacity of the reservoir? (suggestion: 10):
10
Please, enter the of rain (mm) in your region, amount:
Suggestion: 5 6 4 10 3 5 4 4 3 3 3 12
5 6 4 10 3 5 4 4 3 3 3 12
Here is the first matrix:
5       6       4       10      3       5       4       4       3       3       3       12
Please, enter the water consumption (mm), monthly:
Suggestion: 3 3 3 6 6 6 2 3 3 3 6 6
3 3 3 6 6 6 2 3 3 3 6 6
Here is the second matrix:
3       3       3       6       6       6       2       3       3       3       6       6

Here is the resultant pluviometric matrix: MAX = 10
------------------------------------------------------
Mount   Init    Rain    Partial Drain   Status  Final
______________________________________________________
jan     0 +     5 =     5 -     3 =             2
fev     2 +     6 =     8 -     3 =             5
mar     5 +     4 =     9 -     3 =             6
apr     6 +     10 =    10 -    6 =     Full!   4
may     4 +     3 =     7 -     6 =             1
jun     1 +     5 =     6 -     6 =     Empty!  0
jul     0 +     4 =     4 -     2 =             2
aug     2 +     4 =     6 -     3 =             3
sept    3 +     3 =     6 -     3 =             3
oct     3 +     3 =     6 -     3 =             3
nov     3 +     3 =     6 -     6 =     Empty!  0
dez     0 +     12 =    10 -    6 =     Full!   4
______________________________________________________

***********************************************************
  Edited by J3
  Date: Jul, 16/2020
*/
#include <stdio.h>

int main()
{
	int r1 = 1, c1 = 12, r2 = 1, c2 = 12;
	char mounth[12][12] = { "jan", "fev", "mar", "apr",  "may", "jun", "jul", "aug", "sept", "oct", "nov", "dez"};
    int MAX_CAP = 150;
    
	printf("What is the capacity of the reservoir? (suggestion: 10): \n");
	scanf("%d", &MAX_CAP);

	/* Inside if scope, declaring the matrices */
	int m1[1][12];
	int m4[1][12];
	 
    int m2[1][12] = {0};
    int m3[1][12] = {0};	    
    int r[1][12] = {0};
	int i, j, k;
	
	int total_rain = 0;
	int total_drain = 0;
		    
	printf("Please, enter the of rain (mm) in your region, amount: \n");
	printf("Suggestion: 5 6 4 10 3 5 4 4 3 3 3 12\n");
	for(int i = 0; i < r1; i++ )
	{			
		for(j = 0; j < c1; j++)
		{
			scanf("%d", &m1[i][j]);		
		}
		
	}
	printf("Here is the first matrix:\n");		
    for(i = 0; i < r1; i++ )
	{
		for(j = 0; j < c1; j++)
		{
			printf("%d\t", m1[i][j]);
		}
		printf("\n");
	}
	
	printf("Please, enter the water consumption (mm), monthly: \n");
	printf("Suggestion: 3 3 3 6 6 6 2 3 3 3 6 6\n");
	for(i = 0; i < r2; i++ )
	{			
		for(j = 0; j < c2; j++)
		{
			scanf("%d", &m4[i][j]);		
		}
		
	}
	printf("Here is the second matrix:\n");		
    for(i = 0; i < r2; i++ )
	{
		for(j = 0; j < c2; j++)
		{
			printf("%d\t", m4[i][j]);
		}
		printf("\n");
	}
	
	/* Testing if there is sufficient rain */
	for(i = 0; i < r2; i++ )
	{
		for(j = 0; j < c2; j++)
		{
		  for (k = 0; k < c2; k++)
		  {
		  	total_rain += m1[i][j];
		  }
		  							
		}
	}
	for(i = 0; i < r2; i++ )
	{
		for(j = 0; j < c2; j++)
		{
		  for (k = 0; k < c2; k++)
		  {
		  	total_drain += m4[i][j];
		  }
		  							
		}
	}
	
	/* If Drain is greater then Rain, interrupts the system :/ */
	if (total_rain - total_drain <= 0 )
	{
		
	   printf("Error: Drain is more than Rain :/\n");
	   return 0;
		
	}
	
	/* Proceeding to all operations */
    for(i = 0; i < r2; i++ )
	{
		for(j = 0; j < c2; j++)
		{
			m3[i][j] = m1[i][j] + m2[i][j];
			if(m3[i][j] > MAX_CAP)
			{
				//printf("Full!");
				m3[i][j] = MAX_CAP;
			
			}
			r[i][j] = m3[i][j] - m4[i][j];	
			if(j<11)
			{
				m2[i][j+1] += r[i][j];
			}

		}
		printf("\n");
	}		
	printf("Here is the resultant pluviometric matrix: MAX = %d\n", MAX_CAP);	
	printf("------------------------------------------------------\n");
	printf("Mount\tInit\tRain\tPartial\tDrain\tStatus\tFinal\n");
    printf("______________________________________________________\n");
	for(i = 0; i < r2; i++ )
	{
		for(j = 0; j < c2; j++)
		{
			printf("%s\t", mounth[j] );
			printf("%d +\t", m2[i][j]);												
			printf("%d =\t", m1[i][j]);
			
			printf("%d -\t", m3[i][j]);			
			printf("%d =\t", m4[i][j]);				
         	if(r[i][j] <= 0)
			{
				r[i][j] = 0;
				printf("Empty!\t");
									
			}
			else 
			if(m3[i][j] >= MAX_CAP)
			{
				printf("Full!\t");
			}
			else 
			{
				printf("\t");
			}
			printf("%d\t\n", r[i][j]);
		}
		printf("______________________________________________________\n");
		printf("\t");
	
	}	
	printf("\t");		
   
	//system("pause");
	return 0;
}

