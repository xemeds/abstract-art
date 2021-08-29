#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "image.h"

#define WIDTH 1600
#define HEIGHT 1600
#define FILENAME "image.png"

int main() {
    Pixel_t image[WIDTH][HEIGHT];

    for (int h = 0; h < HEIGHT; h++) {
        for (int w = 0; w < WIDTH; w++) {
            color(WIDTH, HEIGHT, image, h, w, 255, 255, 255);
        }
    }

    int amount_of_dots_lower = 3000;
    int amount_of_dots_higher = 5000;
    int dot_radius_lower = 1;
    int dot_radius_higher = 25;

    char option;
    do {
        printf("Use default option values? [Y\\n]: ");
        scanf("%c", &option);

        // Clear the input buffer
        int c;
        while((c = fgetc(stdin)) != EOF && c != '\n');
    } while (option != 'Y' && option != 'y' && option != 'N' && option != 'n');

    if (option == 'N' || option == 'n') {
        printf("Lower bound for the amount of dots (default %i): ", amount_of_dots_lower);
        scanf("%d", &amount_of_dots_lower);
        printf("Higher bound for the amount of dots (default %i): ", amount_of_dots_higher);
        scanf("%d", &amount_of_dots_higher);
        printf("Lower bound for the dots radius (default %i): ", dot_radius_lower);
        scanf("%d", &dot_radius_lower);
        printf("Higher bound for the dots radius (default %i): ", dot_radius_higher);
        scanf("%d", &dot_radius_higher);
    }

    time_t t;
    srand((unsigned) time(&t));

    int padding_x = (WIDTH / 16);
    int padding_y = (HEIGHT / 16);
    // (rand() % (upper - lower + 1)) + lower
    for (int i = 0; i < (rand() % ((amount_of_dots_higher + 1) - amount_of_dots_lower + 1)) + amount_of_dots_lower; i++) {
        int x = (rand() % ((WIDTH - padding_x + 1) - padding_x + 1)) + padding_x;
        int y = (rand() % ((HEIGHT - padding_y + 1) - padding_y + 1)) + padding_y;
        int r = (rand() % ((dot_radius_higher + 1) - dot_radius_lower + 1)) + dot_radius_lower;
        drawCircle(WIDTH, HEIGHT, image, x, y, r, rand() % 256, rand() % 256, rand() % 256);
    }

    saveImage(WIDTH, HEIGHT, image, FILENAME);

    printf("Image generated and saved as \"%s\".\n", FILENAME);

    return 0;
}
