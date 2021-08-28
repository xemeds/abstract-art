#include "image.h"

#define WIDTH 800
#define HEIGHT 800
#define FILENAME "image.png"

int main() {
    Pixel_t image[WIDTH][HEIGHT];

    for (int h = 0; h < HEIGHT; h++) {
        for (int w = 0; w < WIDTH; w++) {
            color(WIDTH, HEIGHT, image, h, w, 255);
        }
    }

    drawCircle(WIDTH, HEIGHT, image, 400, 400, 100);
    // drawLine(WIDTH, HEIGHT, image, 400, 0, 400, 800);

    saveImage(WIDTH, HEIGHT, image, FILENAME);

    return 0;
}
