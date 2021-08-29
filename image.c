#include "image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

// Sets the RGP value of the pixel at the given position on the image
void color(int width, int height, Pixel_t image[width][height], int x, int y, int r, int g, int b) {
    image[x][y].Red = r;
    image[x][y].Green = g;
    image[x][y].Blue = b;
}

// A naive function to draw either vertical or horizontal lines
void drawLine(int width, int height, Pixel_t image[width][height], int x1, int y1, int x2, int y2, int r, int g, int b) {
    // Vertical
    if (x1 - x2 == 0 && y1 - y2 != 0) {
        int min_y = MIN(y1, y2);
        int max_y = MAX(y1, y2);

        for (int y = min_y; y < max_y; y++) {
            color(width, height, image, x1, y, r, g, b);
        }
    }
    // Horizontal
    else if (x1 - x2 != 0 && y1 - y2 == 0) {
        int min_x = MIN(x1, x2);
        int max_x = MAX(x1, x2);

        for (int x = min_x; x < max_x; x++) {
            color(width, height, image, x, y1, r, g, b);
        }
    }
}

// Functions for circle-generation using Bresenham's algorithm
// https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/
void colorCircle(int width, int height, Pixel_t image[width][height], int xc, int yc, int x, int y, int r, int g, int b) {
    drawLine(width, height, image, xc+x, yc+y+1, xc+x, yc-y, r, g, b);
    drawLine(width, height, image, xc-x, yc+y+1, xc-x, yc-y, r, g, b);
    drawLine(width, height, image, xc+y+1, yc+x, xc-y, yc+x, r, g, b);
    drawLine(width, height, image, xc+y+1, yc-x, xc-y, yc-x, r, g, b);
}

void drawCircle(int width, int height, Pixel_t image[width][height], int xc, int yc, int radius, int r, int g, int b) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;
    
    colorCircle(width, height, image, xc, yc, x, y, r, g, b);
    while (y >= x) {
        x++;

        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else {
            d = d + 4 * x + 6;
        }
        colorCircle(width, height, image, xc, yc, x, y, r, g, b);
    }
}

// Saves the given image
void saveImage(int width, int height, Pixel_t image[width][height], char* filename) {
    BYTE* pure_byte_image = malloc(width * height * BYTES_PER_PIXEL);

    int i = -1;
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            pure_byte_image[++i] = image[w][h].Red;
            pure_byte_image[++i] = image[w][h].Green;
            pure_byte_image[++i] = image[w][h].Blue;
        }
    }

    stbi_write_png(filename, width, height, BYTES_PER_PIXEL, pure_byte_image, width * BYTES_PER_PIXEL);
    free(pure_byte_image);
}
