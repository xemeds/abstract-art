#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define BYTES_PER_PIXEL 3

typedef uint8_t BYTE;

typedef struct {
    BYTE Red;
    BYTE Green;
    BYTE Blue;
} Pixel_t;

// Prototypes
void color(int width, int height, Pixel_t image[width][height], int x, int y, int r, int g, int b);
void drawLine(int width, int height, Pixel_t image[width][height], int x1, int y1, int x2, int y2, int r, int g, int b);
void colorCircle(int width, int height, Pixel_t image[width][height], int xc, int yc, int x, int y, int r, int g, int b);
void drawCircle(int width, int height, Pixel_t image[width][height], int xc, int yc, int radius, int r, int g, int b);
void saveImage(int width, int height, Pixel_t image[width][height], char* filename);

#endif // IMAGE_H
