/**************************/
/*Damon Milford *
*CPSC 2310 Spring 23 *
*UserName: dlmilfo@clemson.edu *
*Instructor: Dr. Yvon Feaster */
/*************************/

#ifndef PPMUTIL_H
#define PPMUTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

typedef struct Pixel
{
    unsigned char r, g, b;
}pixel_t;

typedef struct Header
{
    char type[3];
    unsigned int width;
    unsigned int height;
    unsigned int maxVal;
}header_t;

/*
Function: Reads in .ppm file to store the header
Parameters: Takes in two inputs:
    a file pointer
    a pointer of struct header_t
Returns: (no return/void function)
Other functionalities:
    Ignores comments w/ complimentary function
    Uses fscanf
*/
void readHeader(FILE*, header_t*);

/*
Function: Reads in .ppm file to store & allocated amount of pixels
Parameters: Takes in two inputs:
    a file pointer
    a header_t type pointer
Returns: a pointer of struct pixel_t
Other functionalities:
    Allocates amount of pixels
    Uses fread
*/
pixel_t* readPixels(FILE*, header_t);

/*
Function: Writes to a .ppm file to print stored header
Parameters: Takes in two inputs:
    a file pointer
    a variable of struct header_t
Returns: (no return/void function)
Other functionalities:
    Uses fprintf
*/
void writeHeader(FILE*, header_t);

/*
Function: Writes to a .ppm file to output stored pixels
Parameters: Takes in three inputs:
    a file pointer
    a pointer of struct pixel_t
    a variable of struct header_t
Returns: (no return/void function)
Other functionalities:
    Uses fwrite
*/
void writePixels(FILE*, pixel_t*, header_t);

/*
Function: Reads in a given file
Parameters: Takes in two inputs:
    a file pointer
    a pointer of struct header_t
Returns: a pointer of struct pixel_t
Other functionalities:
    Calls both readHeader() and readPixels() functions
*/
pixel_t* read(FILE*, header_t*);

/*
Function: Writes to a given file
Parameters: Takes in three inputs:
    a file pointer
    a variable of struct header_t
    a pointer of struct pixel_t
Returns: (no return/void function)
Other functionalities:
    Calls both writeHeader() and writePixels() functions
*/
void write(FILE*, header_t, pixel_t*);

/*
Function: Allocates the amount of pixels needed by memory
Parameters: Takes in one input:
    a variable of struct header_t
Returns: a pointer of struct pixel_t
Other functionalities: N/A
*/
pixel_t* allocatePixMemory(header_t);

/*
Function: Frees the allocated memory for OS
Parameters: Takes in one input:
    a pointer of struct pixel_t
Returns: (no return/void function)
Other functionalities: N/A
*/
void freeMemory(pixel_t*);

/*
Function: Checks and Ignores comments in a given file
Parameters: Takes in one input:
    a file pointer
Returns: (no return/void function)
Other functionalities: N/A
*/
void ckComment(FILE*);

#endif
