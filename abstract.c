#include "image.h"

#define WIDTH 800
#define HEIGHT 800
#define FILENAME "image.png"

int main() {
    Pixel_t image[WIDTH][HEIGHT];

    for (int h = 0; h < HEIGHT; h++) {
        for (int w = 0; w < WIDTH; w++) {
            image[h][w].Red = 255;
            image[h][w].Green = 255;
            image[h][w].Blue = 255;
        }
    }

    saveImage(WIDTH, HEIGHT, image, FILENAME);

    return 0;
}
