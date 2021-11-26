/*
Project #09 (CSeries)

09_FILEREADPLUSPARSING.C
------------------

It shows HOW TO PARSE INTO A FILE BY CREATING A METHOD.
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
#define MAX_LEN 20
char filename[MAX_LEN] = "musicalbum_v0.csv";
FILE *file;

void loadFile(char[]);

int main(void)
{
   loadFile(filename);
   return 0;
}

void loadFile(char filename[])
{

   file = fopen(filename, "r"); /* should check the result */
   char line[500];

   while (fgets(line, sizeof(line), file))
   {
      int track;
      char artist[50] = {0};
      char music[50] = {0};
      int duration;

      /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
      sscanf(line, "%i,%[^,], %[^,], %i", &track, artist, music, &duration);
      printf("track=%i Artist=%s Music=%s Duration=%i\n", track, artist, music, duration);
      //insertLast(track, artist, music, duration);
   }
   /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */
   fclose(file);
}