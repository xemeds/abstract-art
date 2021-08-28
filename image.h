#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>

#define BYTES_PER_PIXEL 3

typedef uint8_t BYTE;

typedef struct {
    BYTE Red;
    BYTE Green;
    BYTE Blue;
} Pixel_t;

// Prototypes
void saveImage(int width, int height, Pixel_t image[width][height], char* filename);

#endif // IMAGE_H
