/*
Project #02 (CSeries)

02_FOPEN.C
----------

Description:
This demostrate the use of fopen in C.

Function:
    FILE *fopen( const char *filename, const char *mode );

Visit: https://en.cppreference.com/w/c/io/fopen

Edited By: J3
Date: Nov, 2021
*/

#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    int is_ok = EXIT_FAILURE;
    const char* fname = "unique_name.txt"; // or tmpnam(NULL);
    FILE* fp = fopen(fname, "w+");
    if(!fp) {
        perror("File opening failed");
        return is_ok;
    }
    fputs("Hello, world!\n", fp);
    rewind(fp);                            // sets the file position to the beginning of the file for the stream pointed to by stream. 
                                           // It also clears the error and end-of-file indicators for stream.
 
    int c;                                 // note: int, not char, required to handle EOF
    while ((c = fgetc(fp)) != EOF) {       // standard C I/O file reading loop
       putchar(c);
    }
 
    if (ferror(fp)) {
        puts("I/O error when reading");
    } else if (feof(fp)) {
        puts("End of file reached successfully");
        is_ok = EXIT_SUCCESS;
    }
 
    fclose(fp);
    remove(fname);
    return is_ok;
}