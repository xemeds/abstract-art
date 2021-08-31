// Author: Muhammed Ali Dilek (xemeds)

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "image.h"

#define WIDTH 1600
#define HEIGHT 1600
#define PADDING_MARGIN 16
#define FILENAME "image.png"

int main() {
    int amount_of_dots_lower = 3000;
    int amount_of_dots_higher = 5000;
    int dot_radius_lower = 1;
    int dot_radius_higher = 25;
    int bg_r = 255;
    int bg_g = 255;
    int bg_b = 255;

    char option;
    do {
        printf("Use default option values? [Y\\n]: ");
        scanf("%c", &option);

        // Clear the input buffer
        int c;
        while((c = fgetc(stdin)) != EOF && c != '\n');
    } while (option != 'Y' && option != 'y' && option != 'N' && option != 'n');

    if (option == 'N' || option == 'n') {
        printf("Backgound color red value 0 - 255 (default %i): ", bg_r);
        scanf("%d", &bg_r);
        printf("Backgound color green value 0 - 255 (default %i): ", bg_g);
        scanf("%d", &bg_g);
        printf("Backgound color blue value 0 - 255 (default %i): ", bg_b);
        scanf("%d", &bg_b);

        printf("Lower bound for the amount of dots (default %i): ", amount_of_dots_lower);
        scanf("%d", &amount_of_dots_lower);
        printf("Higher bound for the amount of dots (default %i): ", amount_of_dots_higher);
        scanf("%d", &amount_of_dots_higher);
        printf("Lower bound for the dots radius (default %i): ", dot_radius_lower);
        scanf("%d", &dot_radius_lower);
        printf("Higher bound for the dots radius (default %i): ", dot_radius_higher);
        scanf("%d", &dot_radius_higher);
    }

    Pixel_t image[WIDTH][HEIGHT];
    
    colorBackground(WIDTH, HEIGHT, image, bg_r, bg_g, bg_b);

    time_t t;
    srand((unsigned) time(&t));
    // (rand() % (upper - lower + 1)) + lower

    int padding_x = (WIDTH / PADDING_MARGIN);
    int padding_y = (HEIGHT / PADDING_MARGIN);
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
