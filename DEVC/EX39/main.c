/*
  Project 39
  This program use alloc to storage the operations entered by the user
  ( It is for Project 38 improvement - Calculator v2 )

  It tries to implementing a memory function in the Calculator v1 (Project 38)
  For this, we use structs to store all values entered and all the results, 
  as well as which operation was performed. 
  We then write all these vectors on the screen at the time of closing the program.
  
  Description
  
  In this program I will try to store the information entered by the user 
  using dynamic memory allocation (malloc). 
  
  Please, at prompt, enter 5 informations:
         (1) - How many operations you want to store?
		 Then, for each operation: 
  		 (2) operation --> 1-Add 2-Sub 3-Mult 4-Div,
		 (3) number1,
		 (4) number2 &
		 (5) the result ot the arithmetic operation, respectively.
		  
  This is my first try :)
  
  Inspiration: 
  https://www.programiz.com/c-programming/examples/structure-dynamic-memory-allocation
  C Program to Store Data in Structures Dynamically 
  
*******************************************************************
Output:

Enter the number of records for for memory allocation (malloc): 2
Enter:
(a) operation --> 1-Add 2-Sub 3-Mult 4-Div,
(b) number1,
(c) number2 &
(d) the result ot the arithmetic operation, respectively:
1                       <--meaning Addition
10                      <--First Number entered                     
10                      <--Second Number entered
20                      <--Arithmetic Result: 10 + 10 = 20
Enter:
(a) operation --> 1-Add 2-Sub 3-Mult 4-Div,
(b) number1,
(c) number2 &
(d) the result ot the arithmetic operation, respectively:
2                       <--meaning Subtration
10                      <--First Number entered
5                       <--Second Number entered
5                       <--A
rithmetic Result: 10 - 5 = 5
Displaying Information:
Op      Number_1        Number_2        Result
--      --------        --------        ------
1       10.000000       10.000000       20.000000
2       10.000000       5.000000        5.000000


Enter the number of records for for memory allocation (malloc): 2
Enter the operation required and 2 numbers and the result, respectively:
1                  <--meaning Addition
12                 <--First Number entered
12                 <--Second Number entered
24                 <--Result from the operation 12 + 12 = 24
Enter the operation required and 2 numbers and the result, respectively:
2                  <--meaning Subtration
12                 <--First Number entered
2                  <--Second Number entered
10                 <--Result from the operation 12 - 2 = 10
Displaying Information:
Op      Number_1        Number_2        Result
--      --------        --------        ------
1       12.000000       12.000000       24.000000
2       12.000000       2.000000        10.000000

*******************************************************************

  Tutor: Borin (https://br.linkedin.com/in/borinvini) 
  Edited by j3
  
  Date: First, 07/2020  
*/

#include <stdio.h>
#include <stdlib.h>

/* Declaring the struct to hold all Calcs for each operation */

struct operation {
    int opr;
	float fnumber1;
	float fnumber2;
	float fnumber3;
};

int main() {
    struct operation *ptr;
    int i, noOfRecords, opr;
    float fnumber1, fnumber2, fnumber3;
    
    printf("Enter the number of records for for memory allocation (malloc): ");
    scanf("%d", &noOfRecords);

    /* Memory allocation for noOfRecords structures */
    
	ptr = (struct operation *)malloc(noOfRecords * sizeof(struct operation));
    
    /* Iterate over each record to populate the struct object 'operation' */
	
	for (i = 0; i < noOfRecords; ++i) {
        printf("Enter: \n(a) operation --> 1-Add 2-Sub 3-Mult 4-Div,\n(b) number1,\n(c) number2 &\n(d) the result ot the arithmetic operation, respectively:\n");
        scanf("%i %f %f %f", &(ptr + i)->opr, &(ptr + i)->fnumber1, &(ptr + i)->fnumber2, &(ptr + i)->fnumber3);
    }
    
    /* Display all the information entering by the user */
   
    printf("Displaying Information:\n");
    printf("Op\tNumber_1\tNumber_2\tResult\n");
    printf("--\t--------\t--------\t------\n");
    for (i = 0; i < noOfRecords; ++i)
        printf("%i\t%f\t%f\t%f\n", (ptr + i)->opr, (ptr + i)->fnumber1,  (ptr + i)->fnumber2,  (ptr + i)->fnumber3) ;
    
	
	/* deallocating the memory */
    
	free(ptr);
    
    //system("pause");
	return 0;
}
