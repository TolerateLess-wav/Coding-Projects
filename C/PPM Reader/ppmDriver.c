/**************************/
/*Damon Milford *
*CPSC 2310 Spring 23 *
*UserName: dlmilfo@clemson.edu *
*Instructor: Dr. Yvon Feaster */
/*************************/

#include "ppmUtil.h"

int main(int argc, char* argv[]) {

    char *fileInput = argv[1];
    char *fileOutput = argv[2];

    FILE *input = NULL;
    FILE *output = NULL;

    input = fopen(fileInput, "r");
    output = fopen(fileOutput, "w");

    //Checks if files opened correctly
    assert(input != NULL);
    assert(output != NULL);

    //Created both header and pixels pointers
    //Reads from an input, writes to an output
    header_t header;
    pixel_t *pixels = read(input, &header);
    write(output, header, pixels);

    //Frees memory
    //Closes both files
    freeMemory(pixels);

    fclose(input);
    fclose(output);

    return 0;
}