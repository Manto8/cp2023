#include <stdio.h>
#include <gd.h>

#define WIDTH 600
#define HEIGHT 400
#define RED 0xD50A0A   // Red color
#define WHITE 0xFFFFFF // White color

void drawMonacoFlag() {
    gdImagePtr im;
    FILE *output;

    im = gdImageCreateTrueColor(WIDTH, HEIGHT);
    output = fopen("monaco_flag.png", "wb");

    // Draw red upper half
    gdImageFilledRectangle(im, 0, 0, WIDTH - 1, HEIGHT / 2 - 1, RED);

    // Draw white lower half
    gdImageFilledRectangle(im, 0, HEIGHT / 2, WIDTH - 1, HEIGHT - 1, WHITE);

    // Save the image
    gdImagePng(im, output);
    fclose(output);
    gdImageDestroy(im);
}

int main() {
    drawMonacoFlag();
    return 0;
}