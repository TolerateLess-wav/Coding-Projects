/**************************/
/*Damon Milford *
*CPSC 2310 Spring 23 *
*UserName: dlmilfo@clemson.edu *
*Instructor: Dr. Yvon Feaster */
/*************************/

#include "ppm_utils.h"

void openInputFiles(char* name, FILE* input[]) {

    int num_files;
    char file_name[20];
    
    if (strcmp(name, "average") == 0) {
        num_files = TEN;
    } 
    else if (strcmp(name, "median") == 0) {
        num_files = NINE;
    } 
    else {
        printf("Invalid input file name\n");
        exit(1);
    }
    for (int i = 1; i <= num_files; i++) {
        sprintf(file_name, "%s_%03d.ppm", name, i);
        FILE* fp = fopen(file_name, "rb");
        //printf("%s\n", file_name);
        if (fp == NULL) {
            printf("Error: cannot open file %s\n", file_name);
            exit(1);
        }
        input[i-1] = fp;
    }

}
image_t* removeNoiseAverage(image_t* image[]) {

    assert(image != NULL);

    //Create a header from the image array's address and allocate it
    header_t* header = &(image[0]->header);
    image_t* output = allocateMemory(header);

    int height = header->HEIGHT;
    int width = header->WIDTH;

    //Loops through each pixel
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int avg_R = 0, avg_G = 0, avg_B = 0;
            //Calculates average of each RGB value
            for (int k = 0; k < TEN; k++) {
                avg_R += image[k]->pixels[i][j].R;
                avg_G += image[k]->pixels[i][j].G;
                avg_B += image[k]->pixels[i][j].B;
            }
            avg_R /= TEN;
            avg_G /= TEN;
            avg_B /= TEN;

            output->pixels[i][j].R = (unsigned char)avg_R;
            output->pixels[i][j].G = (unsigned char)avg_G;
            output->pixels[i][j].B = (unsigned char)avg_B;
        }
    }

  return output;
}

image_t* removeNoiseMedian(image_t* image[]) {

    //Create a header from the image array's address and allocate it
    header_t* header = (&image[0]->header);
    image_t* output = allocateMemory(header);

    int height = header->HEIGHT;
    int width = header->WIDTH;

    //Loop over each pixel, declaring RGB values
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned int RED[TEN];
            unsigned int GREEN[TEN];
            unsigned int BLUE[TEN];
            //Loop through each image for RGB values
            for (int k = 0; k < NINE; k++) {
                RED[k] = image[k]->pixels[i][j].R;
                GREEN[k] = image[k]->pixels[i][j].G;
                BLUE[k] = image[k]->pixels[i][j].B;
            }

            //Sorts each RGB value
            sort(RED, NINE);
            sort(GREEN, NINE);
            sort(BLUE, NINE);

            //Stores 4th element (middle) to output for removal
            output->pixels[i][j].R = (unsigned char)(RED[4]);
            output->pixels[i][j].G = (unsigned char)(GREEN[4]);
            output->pixels[i][j].B = (unsigned char)(BLUE[4]);
        }
    }
    return output;
}

pixel_t readPixel(FILE* in, image_t* image) {
    
    //Reads each individual RGB pixel value
    pixel_t pixel;
    pixel.R = fgetc(in);
    pixel.G = fgetc(in);
    pixel.B = fgetc(in);

    return pixel;
}

header_t read_header(FILE* image_file) {
    header_t header;
    
    fscanf(image_file, "%2s", header.MAGIC_NUMBER);
    fscanf(image_file, "%u", &header.HEIGHT);
    fscanf(image_file, "%u", &header.WIDTH);
    fscanf(image_file, "%u", &header.MAX_VAL);

    return header;
}

image_t* read_ppm(FILE* image_file) {

    //Reads the header
    header_t header = read_header(image_file);

    //Allocates memory
    image_t* image = allocateMemory(&header);

    //Reads each pixel
    for (int i = 0; i < header.HEIGHT; i++) {
        for (int j = 0; j < header.WIDTH; j++) {
            image->pixels[i][j] = readPixel(image_file, image);
        }
    }

    return image;
}

void write_header(FILE* out_file, header_t header) {

    fprintf(out_file, "%s\n", header.MAGIC_NUMBER);
    fprintf(out_file, "%u %u %u\n", header.HEIGHT, header.WIDTH, header.MAX_VAL);
}

void write_p6(FILE* out_file, image_t* image) {
    
    // Write the header
    write_header(out_file, image->header);

    //Write the pixels
    //Have to write each pixel individually, indicated by 1
    int i, j;
    for (i = 0; i < image->header.HEIGHT; i++) {
        for (j = 0; j < image->header.WIDTH; j++) {
            fwrite(&(image->pixels[i][j].R), sizeof(pixel_t), 1, out_file);
            fwrite(&(image->pixels[i][j].G), sizeof(pixel_t), 1, out_file);
            fwrite(&(image->pixels[i][j].B), sizeof(pixel_t), 1, out_file);
        }
    }
}

void sort(unsigned int* arr, int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[j]) {
                swap(&arr[j], &arr[j]);
            }
        }
    }
}

void swap(unsigned int* a, unsigned int* b) {
    unsigned int* temp = a;
    a = b;
    b = temp;
}

image_t* allocateMemory(header_t* header) {
    //assert(header != NULL);

  int height = header->HEIGHT;
  int width = header->WIDTH;

  //Allocate memory for the image_t struct
  image_t* image = (image_t*)malloc(sizeof(image_t));
  assert(image != NULL);

  //Set header
  memcpy(&(image->header), header, sizeof(header_t));

  //2D Allocate memory for the pixels 
  //(basically, allocate height to a pixel_t** then allocate the width to a pixel_t*)
  image->pixels = (pixel_t**)malloc(height * sizeof(pixel_t*));
  assert(image->pixels != NULL);

  for (int i = 0; i < height; i++) {
    image->pixels[i] = (pixel_t*)malloc(width * sizeof(pixel_t));
    assert(image->pixels[i] != NULL);
  }

  return image;
}

void freeMemory(image_t* image) {
    free(image);
}

void closeAllFiles(FILE* input[], int n) {

    for (int i = 0; i < n; i++) {
        fclose(input[i]);
    }
}