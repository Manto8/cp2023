#include <stdio.h>
#include <gd.h>
#include <math.h>

#define WIDTH 600
#define HEIGHT 400
#define WHITE 0xFFFFFF  // White color
#define BLUE 0x0033A0   // Blue color
#define RED 0xD52B1E    // Red color

void drawRussiaFlag() {
    gdImagePtr im;
    FILE *output;

    im = gdImageCreateTrueColor(WIDTH, HEIGHT);
    output = fopen("russia_flag.png", "wb");

    // Draw white rectangle (top part)
    int whiteRectWidth = WIDTH;
    int whiteRectHeight = HEIGHT / 3;
    int whiteRectX = 0;
    int whiteRectY = 0;

    gdImageFilledRectangle(im, whiteRectX, whiteRectY, whiteRectX + whiteRectWidth, whiteRectY + whiteRectHeight, WHITE);

    // Draw blue rectangle (middle part)
    int blueRectWidth = WIDTH;
    int blueRectHeight = HEIGHT / 3;
    int blueRectX = 0;
    int blueRectY = HEIGHT / 3;

    gdImageFilledRectangle(im, blueRectX, blueRectY, blueRectX + blueRectWidth, blueRectY + blueRectHeight, BLUE);

    // Draw red rectangle (bottom part)
    int redRectWidth = WIDTH;
    int redRectHeight = HEIGHT / 3;
    int redRectX = 0;
    int redRectY = 2 * HEIGHT / 3;

    gdImageFilledRectangle(im, redRectX, redRectY, redRectX + redRectWidth, redRectY + redRectHeight, RED);

    gdImagePng(im, output);
    fclose(output);
    gdImageDestroy(im);
}

int main() {
    drawRussiaFlag();
    return 0;
}