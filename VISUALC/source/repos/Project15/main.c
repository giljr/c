/* Project 78

	PRACTICE 3

	Make a C program to calculate the number of 60 watt lamps needed for a 	particular room.

	The program should read a set of information, such as: type, width and 	length of room.
	The program ends when the room type equals -1.
	The table below shows, for each type of room, the amount of watts per square meter:

	kind of room  - Power (w)
		   0      -   12
		   1      -   15
		   2      -   18
		   3      -   20
		   4      -   22

	Use a struct structure to logically group information.

	Here's the prototyping functions proposed:

	room(int type of room, float width and float length).

	Use a function with the prototype:

	void Calc_area(float *area, float *length, float *width);

	to calculate the area of the room.

	The input attributes will be the room's width and length. Use a function with the prototype:

	float Lamp(int type, float area);

	to calculate the number of lamps needed for the room.
	The input attributes will be the type of room and the size (in m2) of the room.

	At the end, show the user the number of lamps in rounded integer values up.

	To demonstrate the operation, use the first two digits of the room as the width of the room.
	its RU and for height the last two digits of its RU.

	************************************************************
	Output:

	Please, enter the width of your area: 33.0
	Please, enter the height of your area: 62.0
	Please, enter the type of your room: 0
	171 lamps will be necessary for 2046.00 m^2 of area of type 0

	************************************************************
	Output /: invalid type entered :/

	Please, enter the width of your area: 33.0
	Please, enter the height of your area: 62.0
	Please, enter the type of your room: 8
	Invalid Type entered :/
	Type range (0-4) :)
	Please, try again...
	************************************************************

	Author: Gilberto Jr RU 3326662
	UNINTER - Escola Superior Politécnica
	Curso : Engenharia da Computação
	Date: Jun, 2021
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* Variables Declarations */
//int type = -1;
//float width = 0.0;
//float height = 0.0;
//float area = 0.0;

/* Struct Declaration */
typedef struct Room
{
	int type;
	float width;
	float height;
	float area;

} Room_t;

double result = 0.0;
int c;

/* Prototypes */
void calc_area(float, float);
float mult(float, float);
float divide(float, float);

/* Variable of typedef struct Room named Room_t and alias sroom */
Room_t sroom;

/* The room object */
void room(int _type, float _width, float _height)
{
	sroom.type = _type;
	sroom.width = _width;
	sroom.height = _height;

}

/* Calculation of the area of the room */
void calc_area(float width, float height)
{
	sroom.area = mult(width, height);
}


/* Operations */
float mult(float a, float b) { return (a * b); };
float divide(float a, float b) { return (a / b); };

float lamp(int type, float _area)
{
	/* Choose one of the types of the room, rounding values up and returning double */
	switch (type)
	{
	case 0: result = (double)ceil(divide(_area, 12)); break;
	case 1: result = (double)ceil(divide(_area, 15)); break;
	case 2: result = (double)ceil(divide(_area, 18)); break;
	case 3: result = (double)ceil(divide(_area, 20)); break;
	case 4: result = (double)ceil(divide(_area, 22)); break;
	default: return sroom.type = -1; break;
	}

	return result;
}


int main(int argc, char* argv[]) {


	//room(1, 33.0, 62.0);
	/* Asks for the width of the room */
	printf("Please, enter the width of your area: ");
	scanf_s("%f", &sroom.width);
	while ((c = getchar()) != '\n' && c != EOF) {} 	// clears input buffer

	/* Asks for the height of the room */
	printf("Please, enter the height of your area: ");
	scanf_s("%f", &sroom.height);
	while ((c = getchar()) != '\n' && c != EOF) {} 	// clears input buffer

	/* Asks for the type of the room */
	printf("Please, enter the type of your room: ");
	scanf_s("%d", &sroom.type);
	while ((c = getchar()) != '\n' && c != EOF) {} 	// clears input buffer

	/* Calculationg the area */
	calc_area(sroom.width, sroom.height);
	//printf("area= %f\n", area);
	result = lamp(sroom.type, sroom.area);
	//printf("result= %f\n", result);
	//printf("type= %d\n", type);

	/* Printing the output to the user to console */
	if (sroom.type > -1 ? (printf("%.0lf lamps will be necessary for %.2f m^2 of area of type %d", result, sroom.area, sroom.type)) : (printf("Invalid Type entered :/\nType range (0-4) :)\nPlease, try again...")));

	return 0;
}