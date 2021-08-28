#include "image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

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
