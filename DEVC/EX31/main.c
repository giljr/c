/*
  Project 31
  
  Programming Logic and Algorithms - Computer Enginner Course 2020
  Practical Activity 2020
  Prof. Borin, Me.

  Exercise 1:
  Make a C language algorithm to calculate how much each customer has spent on
  orders placed in a snack bar. The snack bar sells the following products:

  Item Product 		Code 	Price Unit
  1 Hot Dog 		100 	5.00
  2 X-salad 		101 	8.79
  3 X-bacon 		102 	9.99
  4 Mixed 		103 	6.89
  5 Salad 		104 	4.80
  6 Water 		105 	3.49
  7 Soda	 	106 	4.99

  Requirements:
  
  When starting the program, a menu with all items sold must appear on the screen  
  and their respective prices. The user must choose by typing from 1-7 which item
  want to buy.
  Note that the user can purchase the same item several times and can also
  buy several different items (example: 2 waters and a hot dog, in the same
  request).
  To end the purchase process, the user must enter a value other than 1-7. 
  At the end of the purchase, you must list all the items purchased, their individual prices
  and the total to be paid.
  
***********************************************************
Output:

     JayThree Snack Bar:
-----------------------------
           Welcome!!
-------------MENU-------------
Product:                Price:
--------------------    ------
1 - Hot Dog             5,00
2 - X-Salad             8,99
3 - X-Bacon             9,99
4 - Mix                 6,89
5 - Salad               4,80
6 - Water               3,49
7 - Soda                4,99
------------------------------

Please Choose your Combo (Enter the number required):1

Entre a Quantidade desse produto:12

You chose: 12 x Hot Dog

***********************************************************

  Author j3
  
  Date Jun, 27/2020
  
  This is my First try:)
*/

#include <stdio.h>

int choseProduct = 0;
int quantityOfProduct = 0;	    

int main()
{

	char ch;
	int num1, num2, c;

	printf("\n     JayThree Snack Bar:");
	printf("\n-----------------------------");
	printf("\n           Welcome!!");
	
	printf("\n-------------MENU-------------");
    
	printf("\n\tProduct:\tPrice:");
	printf("\n--------------------\t------");	
	printf("\n1 - Hot Dog\t\t5,00");
	printf("\n2 - X-Salad\t\t8,99");
	printf("\n3 - X-Bacon\t\t9,99");
	printf("\n4 - Mix \t\t6,89");
	printf("\n5 - Salad\t\t4,80");
	printf("\n6 - Water\t\t3,49");
	printf("\n7 - Soda\t\t4,99");
	
	printf("\n------------------------------");
	
    	printf("\n\nPlease Choose your Combo (Enter the number required):");
    	scanf("%d", &choseProduct);
    	while((c = getchar()) != '\n' && c != EOF) { }

	printf("\nEnter the quantity requested:");
	scanf("%d", &quantityOfProduct);
	while((c = getchar()) != '\n' && c != EOF) { }

	switch (choseProduct) 
	   {
    	
		case 1:
        		printf("\nYou chose: %d x Hot Dog", quantityOfProduct);        	
        		break;

    		case 2:
        		printf("\nYou chose: %d x X-Salad", quantityOfProduct);        	
        		break;

    		case 3:
        		printf("\nYou chose: %d x X-Bacon ", quantityOfProduct);        	
        		break;
	
	   	 case 4:
        		printf("\nYou chose: %d x Mix", quantityOfProduct );        	
        		break;
        	
    		case 5:
        		printf ("\nYou chose: %d x Salad", quantityOfProduct);
        		break;
        	
    		case 6:
        		printf ("\nYou chose: %d x Water ", quantityOfProduct);
        		break;
        	
        	case 7:
        		printf ("\nYou chose: %d x Soda", quantityOfProduct);
        		break;
        	
    		default:
        		printf("\nInvalid Product! Please, Try again:)");
            		break;
           }

	//system("pause");
	return 0;

}
