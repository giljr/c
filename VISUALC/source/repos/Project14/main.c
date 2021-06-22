/* Project 76

 PRACTICE 2
 1) Make a program where the user enters 3 pieces of information about a person:

  1.1. Name,
  1.2. address and
  1.3. telephone number.

 2) Concatenate these three pieces of information into a single string and

 3) Count how many letters of the alphabet are present in this string (considering redundancies)
	and the numeric digits.

	Spaces and punctuation characters must be ignored (the functions of counting already do that).
   ************************************************************
   output:

	Hi, Please what is your name: Gilberto Oliveira Junior
	Fine, thanks, Gilberto Oliveira Junior!
	Now please enter your complete address: Rua Venezuela, 1875 Porto Velho - Rondonia
	We almost there Gilberto Oliveira Junior...
	Now please enter your phone number: 5569984486664
	Thanks Gilberto Oliveira Junior, You just have entered:

	Name: Gilberto Oliveira Junior;
	Address: Rua Venezuela, 1875 Porto Velho - Rondonia;
	Phone: 5569984486664

	Concatenation:
	Gilberto Oliveira Junior Rua Venezuela, 1875 Porto Velho - Rondonia 5569984486664

	Number of letters: 55

	Number of digits: 17

	--------------------------------
	Process exited after 103.1 seconds with return value 0

   ************************************************************

   Author: Gilberto Olibveira Junior  RU 3326662
   Edited: J3
   Date: Jun, 2021

*/


#include <string.h>
#include <stdio.h>
#include <ctype.h>



/* initialize letterCount to 0 so that doing letterCount++ does not add 1 to a garbage value */
int letterCount = 0; // counter for number of letters in the string input

/* initialize digitCount to 0 so that doing digitCount++ does not add 1 to a garbage value */
int digitCount = 0; // counter for number of digits in the string input


int main(void)
{
	/* Declaring the structure to hold the Person data */

	typedef struct Person
	{
		char name[50];
		char address[50];
		char phone[14];

	}Person_t;


	/* Populating the Struts to test the code */
	/*
	Person_t client1 =
	{
		.name = "Gilberto Oliveira Junior",
		.address = "Rua Venezuela, 1875 - Porto Velho RO",
		. phone  = "5569984486664"
	};
	*/
	
	Person_t client2;

	printf("Hi, Please what is your name: ");
	gets_s(client2.name, sizeof(client2.name));


	printf("Fine, thanks, %s!\n", client2.name);
	printf("Now please enter your complete address: ");
	gets_s(client2.address, sizeof(client2.address));


	printf("We almost there %s...\n", client2.name);
	printf("Now please enter your phone number: ");
	gets_s(client2.phone, sizeof(client2.phone));


	printf("Thanks %s, You just have entered:\n\n", client2.name);
	//printf("Name: %s;\nAddress: %s; \nPhone: %s", client1.name, client1.address, client1.phone);
	printf("Name: %s;\nAddress: %s; \nPhone: %s", client2.name, client2.address, client2.phone);
	//scanf("%d", person_t.name)

	char full_id[113];


	//strcpy(full_id, client1.name);
	strcpy_s(full_id, sizeof(full_id),client2.name);
	strcat_s(full_id,sizeof(full_id),  " ");       // Concatenating a space
	//strcat(full_id, client1.address);
	strcat_s(full_id, sizeof(full_id), client2.address);
	strcat_s(full_id, sizeof(full_id), " ");       // Concatenating a space
	//strcat(full_id, client1.phone);
	strcat_s(full_id, sizeof(full_id), client2.phone);
	printf("\n\nConcatenation:\n%s", full_id);


	//printf("\nwithout null character: %zu\n", strlen(full_id));
	//printf("\nwith null character:    %zu\n", sizeof full_id);

	/* Loop to count the letters in the input text */
	for (int i = 0; i < sizeof(full_id); i++)
	{
		if (iswalpha(full_id[i])) letterCount++;
	}

	printf("\n\nNumber of letters: %d\n", letterCount);

	/* Loop to count the digits in the input text */
	for (int i = 0; i < sizeof(full_id); i++)
	{
		if (iswdigit(full_id[i])) digitCount++;
	}

	printf("\nNumber of digits: %d\n", digitCount);

	return 0;
}