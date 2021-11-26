/*
Project #07 (CSeries)

07_SSCAN_PARSING.C
------------------

Description:

This shows how to parse a line.
It's purpose is for the academic work.
Please, see Project #10 - MUSIC ALBUM - A PLAYLIST SIMULATION:)

Deque_v1 or Double Ended Queue is a generalized version of Queue data structure 
that allows insert and delete at both ends.

******************************************************************************
OUTPUT:

track=2 Artist=Caetano Veloso Music=Anjos Tronxos Duration=647

******************************************************************************
UNINTER - ESCOLA SUPERIOR POLITECNICA 
Edited By: J3
Date: Nov, 2021
*/
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    char str[] = "2,Caetano Veloso,Anjos Tronxos,647";

    int track;
    char artist[50] = {0};
    char music[50] = {0};
    int duration;

    sscanf(str, "%i,%[^,], %[^,], %i", &track, artist, music, &duration);
    printf("track=%i Artist=%s Music=%s Duration=%i\n",track, artist, music, duration );
    return 0;
}