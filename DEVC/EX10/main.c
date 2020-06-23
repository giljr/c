/*
 Project 10
 #HowToConvertFromLittleToBigEndian
 
 Description
 The program converts an integer from one to another system
 (Big Endian <-> Little Endian) using bitwise operations.
 
 Big-endian systems store the Most Significant Byte (MSB)  
 of a word First. 
 
 A little-endian system, in contrast, stores the Least Significant 
 Byte (LSB) First.
 
 For Easy reference:
 
  BIG ENDIAN (Most First)            LITTLE ENDIAN (Least First)            
         0A 0B 0C 0D                 0A 0B 0C 0D
  0A  _ _|  |  |  |                  |  |  |  |_ _ 0D
  0B  _ _ _|  |  |                   |  |  |_ _ _  0C
  0C _ _ _ _ |  |                    |  | _ _ _ _  0B
  0D _ _ _ _ _ |      		     | _ _ _ _ _   0A

*****************************
 Output
 	little_endian = a0b0c0d
	big_endian =    d0c0b0a
*****************************

 Author: #TechVedasLearn #EmbeddedSystem #EndiannessInC
 			https://youtu.be/a9lVoThjV7o
 Edited by j3
 
 Date: Jun, 20/2020
*/



#include <stdio.h>
#define uint32_t int
/* Prototype */
uint32_t ChangeEndianness(uint32_t value);

int main()
{
	
	uint32_t little_endian = 0x0A0B0C0D;
	uint32_t big_endian = 0;
	
	big_endian = ChangeEndianness(little_endian);
	
	printf("little_endian = %x\n", little_endian);
	printf("big_endian =    %x\n", big_endian);
	//system("pause");
	return 0;
	
}

uint32_t ChangeEndianness(uint32_t value)
{
	uint32_t result = 0;
	result |= (value & 0x000000FF) << 24;
	result |= (value & 0x0000FF00) << 8;
	result |= (value & 0x00FF0000) >> 8;
	result |= (value & 0xFF000000) >> 24;
	return result;	
} 
