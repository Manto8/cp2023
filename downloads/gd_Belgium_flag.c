#include <stdio.h>
#include <gd.h>

#define WIDTH 600
#define HEIGHT 400
#define BLACK 0x000000  // Black color
#define YELLOW 0xFFD100 // Yellow color
#define RED 0xED2939    // Red color

void drawBelgiumFlag() {
    gdImagePtr im;
    FILE *output;

    im = gdImageCreateTrueColor(WIDTH, HEIGHT);
    output = fopen("belgium_flag.png", "wb");

    // Allocate black, yellow, and red colors
    int blackIndex = gdImageColorAllocate(im, (BLACK >> 16) & 0xFF, (BLACK >> 8) & 0xFF, BLACK & 0xFF);
    int yellowIndex = gdImageColorAllocate(im, (YELLOW >> 16) & 0xFF, (YELLOW >> 8) & 0xFF, YELLOW & 0xFF);
    int redIndex = gdImageColorAllocate(im, (RED >> 16) & 0xFF, (RED >> 8) & 0xFF, RED & 0xFF);

    // Draw black left third
    gdImageFilledRectangle(im, 0, 0, WIDTH / 3 - 1, HEIGHT - 1, blackIndex);

    // Draw yellow middle third
    gdImageFilledRectangle(im, WIDTH / 3, 0, 2 * WIDTH / 3 - 1, HEIGHT - 1, yellowIndex);

    // Draw red right third
    gdImageFilledRectangle(im, 2 * WIDTH / 3, 0, WIDTH - 1, HEIGHT - 1, redIndex);

    // Save the image
    gdImagePng(im, output);
    fclose(output);
    gdImageDestroy(im);
}

int main() {
    drawBelgiumFlag();
    return 0;
}