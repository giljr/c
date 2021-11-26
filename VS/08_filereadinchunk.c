/*
Project #08 (CSeries)

08_FILEREADINCHUNK.C
------------------

It shows HOW TO SAVE INTO A FILE (FOPEN).
This code aims to test solutions for the final project.

Please, see this project ahead:

10_MUSICALBUM_V2.C
------------------

Edited By: J3
Date: Nov, 2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#define  MAX_LEN  49
int main(void)
{
   FILE *stream;
   char s[MAX_LEN + 1];
   stream = fopen("musicalbum_v0.csv", "r");
 
   /* Read The fisrt line */
 
   fscanf(stream, "%s", &s [0]);

 
   printf("%s\n", s);
}