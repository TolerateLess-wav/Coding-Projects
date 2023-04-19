/**************************/
/*Damon Milford *
*CPSC 2310 Spring 23 *
*UserName: dlmilfo@clemson.edu *
*Instructor: Dr. Yvon Feaster */
/*************************/


#include "ppm_utils.h"


int main(int argc, char** argv) {

    FILE* output = fopen(argv[2], "w");
    FILE* input[TEN];
    FILE* fileAvg[TEN];
    FILE* fileMed[NINE];
    image_t* imageAvg[TEN];
    image_t* imageMed[NINE];
    image_t* imageFinal;

    openInputFiles(argv[1], input);

    //Checks which string is used ("average" or "median")
    if (strcmp(argv[1], "average") == 0) {

        for (int i = 0; i < TEN; i++) {
            imageAvg[i] = read_ppm(input[i]);
        }
        imageFinal = removeNoiseAverage(imageAvg);

    } 
    else if (strcmp(argv[1], "median") == 0) {

        //openInputFiles(argv[1], fileMed);
        for (int i = 0; i < NINE; i++) {
            imageMed[i] = read_ppm(input[i]);
        }
        imageFinal = removeNoiseMedian(imageMed);

    }
    else {
        printf("Error, string incorrect, exiting program");
        exit(0);
    }

    //Writes to an output ppm file
    write_p6(output, imageFinal);

    //Frees the allocated memory and Closes every set of files
    freeMemory(imageFinal);
    
    if (strcmp(argv[1], "average") == 0) {
        closeAllFiles(input, TEN);
    }
    else {
        closeAllFiles(input, NINE);
    }

    return 0;
}