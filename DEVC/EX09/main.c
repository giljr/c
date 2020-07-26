/* 
 Project 09
 Is C Little and Big Endian?

 Description
 When this program is running on a little endian machine, 
 gives 67 45 23 01 as output , 
 while if it is running on a big endian machine, 
 gives 01 23 45 67 as output.

 ************************
 Output:
  67 45 23 01
 ************************
 
 Conclusion:
  C is Little Endian!
  
 For Easy reference:
 
  BIG ENDIAN (Most First)            LITTLE ENDIAN (Least First)            
         0A 0B 0C 0D                 0A 0B 0C 0D
  0A  _ _|  |  |  |                  |  |  |  |_ _ 0D
  0B  _ _ _|  |  |                   |  |  |_ _ _  0C
  0C _ _ _ _ |  |                    |  | _ _ _ _  0B
  0D _ _ _ _ _ |      		    | _ _ _ _ _   0A

 Author: https://www.geeksforgeeks.org/little-and-big-endian-mystery/
 Edited by j3

 Date: Jun, 20/2020
*/
#include <stdio.h> 
  
/* function to show bytes in memory, from location start to start+n */
void show_mem_rep(char *start, int n)  
{ 
    int i; 
    for (i = 0; i < n; i++) 
         printf(" %.2x", start[i]); 
    printf("\n"); 
} 
  
/* Main function to call above function for 0x01234567 */
int main() 
{ 
   int i = 0x01234567; 
   show_mem_rep((char *)&i, sizeof(i)); 
   getchar(); 
   
   return 0; 
} 
