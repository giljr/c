/* [TODO]Bug total to pay error
  Project 41 - Presenting a Menu for Snack Bar
  This program just presents a menu
  It is for the Project 31
    
***********************************
Output:

Menu:
-------
100     Hot_Dog 5.00
101     X_Salad 8.79
102     X_Bacon 9.99
103     Mix     6.89
104     Salad   4.80
105     Water   3.49
106     Soda    4.99
***********************************
  Edited by J3
  Date Jul, 13/2020
*/

#include <stdio.h>
#include<stdlib.h>

#define LINE	7
#define COLUMN	3

/*char string-array-name[row-size][column-size];*/

/*-----id-----Product*/

int main()
{
	int c;
	int product = 0;
	int quantity = 0;
	float total = 0.0;
	/* Declaring the menu matrix */
 	char menu[7][10] = { "Hot_Dog", "X_Salad", "X_Bacon", "Mix",  "Salad", "Water", "Soda" };

	/* Declaring the Code and Price of each Menu's product */
	float prices[7][4]={
		100, 5.00, 0, 0,    
    		101, 8.79, 0, 0,  
    		102, 9.99, 0, 0,			 
		103, 6.89, 0, 0,    
    		104, 4.80, 0, 0,  
    		105, 3.49, 0, 0,
		106, 4.99, 0, 0  
  	};
  	printf("Menu:\n");
  	printf("-------\n");
  	
	for(int i = 0; i < 7; i++)
  	{
  		 	printf("%.0f\t", prices[i][0]);
		    	printf("%s\t", menu[i]);
      	   		printf("%.2f\n", prices[i][1]);
  		 	
	}
	
	while(product != -1)
	{
		printf("\n\nPlease Choose your Combo (Enter the Code Product required):");
    		scanf("%i", &product);
    
		while((c = getchar()) != '\n' && c != EOF) { }


		printf("Enter the quantity requested:");
		scanf("%i", &quantity);
		while((c = getchar()) != '\n' && c != EOF) { }  	
   
   	switch (product) 
	   {
    	
		case 100:
        			//printf("\nYou chose: %d x Hot Dog\n", quantity); 
				prices[0][3] = quantity;
				prices[0][4] = prices[0][1]*quantity;
				break;

    		case 101:
        			//printf("\nYou chose: %d x X-Salad\n", quantity); 
				prices[1][3] = quantity;
				prices[1][4] = prices[1][1]*quantity;       	
        			break;

    		case 102:
        			//printf("\nYou chose: %d x X-Bacon\n ", quantity); 
				prices[2][3] = quantity;
				prices[2][4] = prices[2][1]*quantity;       	
        			break;
	
	   	case 103:
        			//printf("\nYou chose: %d x Mix\n", quantity);        	
        			prices[3][3] = quantity;
				prices[3][4] = prices[3][1]*quantity;	
				break;
        	
    		case 104:
        			//printf ("\nYou chose: %d x Salad\n", quantity);
        			prices[4][3] = quantity;
				prices[4][4] = prices[4][1]*quantity;
        			break;
        	
    		case 105:
        			//printf ("\nYou chose: %d x Water\n ", quantity);
        			prices[5][3] = quantity;
				prices[5][4] = prices[5][1]*quantity;
        			break;
        	
        	case 106:
        			//printf ("\nYou chose: %d x Soda\n", quantity);
        			prices[6][3] = quantity;
				prices[6][4] = prices[6][1]*quantity;
        			break;
        	
    		default:
        			printf("\nInvalid Product! Please, Try again:)\n");
            			break;
           }
           
   	printf("\n\nAnything else?(Enter the Code Product required):");
    	printf("Menu:\n");
  	printf("-------\n");
  	
	for(int i = 0; i < 7; i++)
  	{
  		 	printf("%.0f\t", prices[i][0]);
		    	printf("%s\t", menu[i]);
      	    		printf("%.2f\n", prices[i][1]);
  		 	
	}
    	switch (product) 
	   {
    	
		case 100:
        			//printf("\nYou chose: %d x Hot Dog\n", quantity); 
				prices[0][3] = quantity;
				prices[0][4] = prices[0][1]*quantity;
				break;

    		case 101:
        			//printf("\nYou chose: %d x X-Salad\n", quantity); 
				prices[1][3] = quantity;
				prices[1][4] = prices[1][1]*quantity;       	
        			break;

    		case 102:
        			//printf("\nYou chose: %d x X-Bacon\n ", quantity); 
				prices[2][3] = quantity;
				prices[2][4] = prices[2][1]*quantity;       	
        			break;
	
	   	case 103:
        			//printf("\nYou chose: %d x Mix\n", quantity);        	
        			prices[3][3] = quantity;
				prices[3][4] = prices[3][1]*quantity;	
				break;
        	
    		case 104:
        			//printf ("\nYou chose: %d x Salad\n", quantity);
        			prices[4][3] = quantity;
				prices[4][4] = prices[4][1]*quantity;
        			break;
        	
    		case 105:
        			//printf ("\nYou chose: %d x Water\n ", quantity);
        			prices[5][3] = quantity;
				prices[5][4] = prices[5][1]*quantity;
        			break;
        	
        	case 106:
        			//printf ("\nYou chose: %d x Soda\n", quantity);
        			prices[6][3] = quantity;
				prices[6][4] = prices[6][1]*quantity;
        			break;
        	
    		default:
        			printf("\nInvalid Product! Please, Try again:)\n");
            			break;
           }
           
    		
	}	
	
	printf ("\n\nHere you have the bill:\n\n");      
    	for(int i = 0; i < 7; i++)
  	{
		printf("%.0f\t", prices[i][3]);
		printf("%s", menu[i]);
		printf("\t\n");
      	
    }
 
   	total = prices[0][4]+prices[1][4]+prices[2][4]+prices[3][4]+prices[4][4]+prices[5][4]+prices[6][4];
    	printf("\nTotal To pay equal to $: %.2f", total);
		  
	//system("pause");
	return 0;
}

