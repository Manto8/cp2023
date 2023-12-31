#include <stdio.h>
#include <gd.h>

#define WIDTH 600
#define HEIGHT 400
#define YELLOW 0xFFD100  // Yellow color
#define BLUE 0x0057A6    // Blue color

void drawUkraineFlag() {
    gdImagePtr im;
    FILE *output;

    im = gdImageCreateTrueColor(WIDTH, HEIGHT);
    output = fopen("ukraine_flag.png", "wb");

    // Allocate yellow and blue colors
    int yellowIndex = gdImageColorAllocate(im, (YELLOW >> 16) & 0xFF, (YELLOW >> 8) & 0xFF, YELLOW & 0xFF);
    int blueIndex = gdImageColorAllocate(im, (BLUE >> 16) & 0xFF, (BLUE >> 8) & 0xFF, BLUE & 0xFF);

    // Draw blue upper half
    gdImageFilledRectangle(im, 0, 0, WIDTH - 1, HEIGHT / 2 - 1, blueIndex);

    // Draw yellow lower half
    gdImageFilledRectangle(im, 0, HEIGHT / 2, WIDTH - 1, HEIGHT - 1, yellowIndex);

    // Save the image
    gdImagePng(im, output);
    fclose(output);
    gdImageDestroy(im);
}

int main() {
    drawUkraineFlag();
    return 0;
}