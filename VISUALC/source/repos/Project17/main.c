#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/* Project 72

   This program solves this Practice exercise from my Computer Enginner's home work at:

   UNINTER - Engenharia da Computação - Escola Superior Politécnica - https://www.uninter.com

   PRACTICE 05
	Create a program, in C language, that receives 6 records containing, Product Name,
	Product code (numeric), product value. Request that all data for everyone be entered
	the records and at the end save them in a.csv file, use the ; (semicolon) for separator and
	field. The file name must be your RU number.
	Example:

   Some notes:
   pcount - used to accumulate the total number of structure entered;
   scanf() - Reads the char/int entered by the user;
   break - immediately exits from the loop if the response is negative;
   struct product My_prods[50] - This creates the potential for the program to read in data for up to 50 products
   How to clear input buffer in C? https://stackoverflow.com/questions/7898215/how-to-clear-input-buffer-in-c

   ************************************************************
   output:

	Do you want to enter details of a Product (Y or N)? y

	Enter the name of the product: Cereal

	What is the Cereal's code? 1001

	What is Cereal's value?: 1.35
	Do you want to enter details of another  Product (Y or N)? y

	Enter the name of the product: Bread

	What is the Bread's code? 1002

	What is Bread's value?: 0.93
	Do you want to enter details of another  Product (Y or N)? y

	Enter the name of the product: Fruits

	What is the Fruits's code? 1003

	What is Fruits's value?: 11.81
	Do you want to enter details of another  Product (Y or N)? y

	Enter the name of the product: Vegetables

	What is the Vegetables's code? 1004

	What is Vegetables's value?: 3.93
	Do you want to enter details of another  Product (Y or N)? y

	Enter the name of the product: Potatoes

	What is the Potatoes's code? 1005

	What is Potatoes's value?: 1.78
	Do you want to enter details of another  Product (Y or N)? y

	Enter the name of the product: Butter

	What is the Butter's code? 1006

	What is Butter's value?: 3.97
	Do you want to enter details of another  Product (Y or N)? n

	 3326662.csv file created!


	 You have Entered these Products:

	_______________Receipt:________________
			Cod     Price   Product
	---------------------------------------

			1001    1.35    Cereal
			1002    0.93    Bread
			1003    11.81   Fruits
			1004    3.93    Vegetables
			1005    1.78    Potatoes
			1006    3.97    Butter
	_______________________________________

	_______________________________________

	--------------------------------
	Process exited after 178.2 seconds with return value 0

   ************************************************************
	File (3326662.csv) content:

	Code;Price;Product
	1001;1.35;Cereal
	1002;0.93;Bread
	1003;11.81;Fruits
	1004;3.93;Vegetables
	1005;1.78;Potatoes
	1006;3.97;Butter

	************************************************************

   Author: Gilberto Jr RU 3326662
   Curso : Engenharia da Computação
   Date: Jun, 2021
*/

int main(int argc, char* argv[]) {

	/* The name of the file is my University Registration number plus .csv estention file*/

	char filename[] = "3326662.csv";

	/* Using Struct to represent the Product collection */
	struct product
	{
		char name[20];
		int code;
		float  value;
	};

	/* Initializing the variable named My_prod of type struct product */
	struct product My_prods[6];
	int pcount = 0;
	char test = '\0';

	/* This routine asks the user the name of 6 products populating the structure declared above */
	for (pcount = 0; pcount < 50; pcount++)
	{
		int c;
		printf("Do you want to enter details of a%s Product (Y or N)? ", pcount ? "nother " : "");
		scanf_s(" %c", &test, sizeof(&test));

		if (tolower(test) == 'n') break;                       // If negative, break the loop :/

		printf("\nEnter the name of the product: ");
		scanf_s("%s", &My_prods[pcount].name, sizeof(&My_prods[pcount].name));              	// Read the product's name
		while ((c = getchar()) != '\n' && c != EOF) {}    	// clears input buffer 

		printf("\nWhat is the %s's code? ", My_prods[pcount].name);
		scanf_s("%d", &My_prods[pcount].code);              	// Read the product's code
		while ((c = getchar()) != '\n' && c != EOF) {} 	// clears input buffer

		printf("\nWhat is %s's value?: ", My_prods[pcount].name);
		scanf_s("%f", &My_prods[pcount].value);          		// Read the product's value
		while ((c = getchar()) != '\n' && c != EOF) {}  	// clears input buffer		

	}

	/* Initialize the file to save all inside as .csv file */
	FILE * fpt;
	errno_t err;

	err = fopen_s(&fpt, filename, "w+");
	fprintf(fpt, "Code;Price;Product\n");

	/* Saving all Products to a File */
	for (int i = 0; i < pcount; i++)
	{
		fprintf(fpt, "%d;%.2f;%s\n", My_prods[i].code, My_prods[i].value, My_prods[i].name);
	}

	/* Closing the file to avoid memory leakage */
	fclose(fpt);
	printf("\n %s file created!\n\n", filename);

	/* Printing the receipt if everything is ok */
	printf("\n You have Entered these Products:\n\n");
	printf("_______________Receipt:________________\n");
	printf("\tCod\tPrice\tProduct\n");
	printf("---------------------------------------\n");

	for (int i = 0; i < pcount; i++)
	{

		printf("\n\t%d\t%.2f\t%s", My_prods[i].code, My_prods[i].value, My_prods[i].name);

	}

	printf("\n_______________________________________\n");
	printf("\n_______________________________________\n");

	return 0;
}