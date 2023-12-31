#include <stdio.h>
#include <gd.h>
#include <math.h>

#define WIDTH 600
#define HEIGHT 400
#define RED 0xCE1126    // Red color
#define WHITE 0xFFFFFF  // White color
#define BLUE 0x0033A0   // Blue color

void drawLaosFlag() {
    gdImagePtr im;
    FILE *output;

    im = gdImageCreateTrueColor(WIDTH, HEIGHT);
    output = fopen("laos_flag.png", "wb");

    // Draw red background
    gdImageFilledRectangle(im, 0, 0, WIDTH - 1, HEIGHT - 1, RED);

    // Draw blue rectangle (symbolizing the Mekong River)
    int blueRectWidth = WIDTH;
    int blueRectHeight = HEIGHT / 2;  // Increase the height
    int blueRectX = 0;
    int blueRectY = HEIGHT / 2 - blueRectHeight / 2;

    gdImageFilledRectangle(im, blueRectX, blueRectY, blueRectX + blueRectWidth, blueRectY + blueRectHeight, BLUE);

    // Draw white circle
    int centerX = WIDTH / 2;
    int centerY = HEIGHT / 2;
    int circleRadius = HEIGHT / 8;  // Adjusted radius

    gdImageFilledEllipse(im, centerX, centerY, circleRadius * 2, circleRadius * 2, WHITE);

    gdImagePng(im, output);
    fclose(output);
    gdImageDestroy(im);
}

int main() {
    drawLaosFlag();
    return 0;
}