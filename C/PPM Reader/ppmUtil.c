/**************************/
/*Damon Milford *
*CPSC 2310 Spring 23 *
*UserName: dlmilfo@clemson.edu *
*Instructor: Dr. Yvon Feaster */
/*************************/

#include "ppmUtil.h"

void readHeader(FILE* input, header_t* h) {

    fscanf(input, "%2s", h->type);
    ckComment(input);
    fscanf(input, "%u", &h->width);
    ckComment(input);
    fscanf(input, "%u", &h->height);
    ckComment(input);
    fscanf(input, "%u", &h->maxVal);
    ckComment(input);
}

pixel_t* readPixels(FILE* input, header_t h) {

    pixel_t* p = allocatePixMemory(h);
    fread(p, sizeof(pixel_t), h.width * h.height, input);
    return p;
}

void writeHeader(FILE* output, header_t h) {

    
    fprintf(output, "%s\n", h.type);
    fprintf(output, "%u %u %u\n", h.width, h.height, h.maxVal);
}

void writePixels(FILE* output, pixel_t* p, header_t h) {

    fwrite(p, sizeof(pixel_t), h.width * h.height, output);
}

pixel_t* read(FILE* input, header_t* h) {

    readHeader(input, h);
    pixel_t *p = readPixels(input, *h);
    return p;
}

void write(FILE* output, header_t h, pixel_t* p) {

    writeHeader(output, h);
    writePixels(output, p, h);
}

pixel_t* allocatePixMemory(header_t h) {

    pixel_t *p = (pixel_t*) malloc(h.width * h.height * sizeof(pixel_t));
    return p;
}

void freeMemory(pixel_t* p) {

    free(p);
}

void ckComment(FILE* input) {

    int c = fgetc(input);

    while (isspace(c))
    c = fgetc(input);
    
    if (c == '#') {
        while ((c = fgetc(input)) != '\n');
            ckComment(input);
        
    }
    else {
        fseek(input, -1, SEEK_CUR);
    }
}