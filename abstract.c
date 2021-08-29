#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "image.h"

#define WIDTH 800
#define HEIGHT 800
#define FILENAME "image.png"

int main() {
    Pixel_t image[WIDTH][HEIGHT];

    for (int h = 0; h < HEIGHT; h++) {
        for (int w = 0; w < WIDTH; w++) {
            color(WIDTH, HEIGHT, image, h, w, 255, 255, 255);
        }
    }

    time_t t;
    srand((unsigned) time(&t));
    // (rand() % (upper - lower + 1)) + lower

    for (int i = 0; i < (rand() % (51 - 10 + 1)) + 10; i++) {
        int x = (rand() % (701 - 100 + 1)) + 100;
        int y = (rand() % (701 - 100 + 1)) + 100;
        int r = (rand() % (101 - 1 + 1)) + 1;
        drawCircle(WIDTH, HEIGHT, image, x, y, r, rand() % 256, rand() % 256, rand() % 256);
    }

    saveImage(WIDTH, HEIGHT, image, FILENAME);

    return 0;
}
