#include <stdio.h>
#include <gd.h>
#include <math.h>

#define WIDTH 600
#define HEIGHT 400
#define GREEN 0x138808  // Green color
#define RED 0xE30A17     // Red color

void drawBangladeshFlag() {
    gdImagePtr im;
    FILE *output;

    im = gdImageCreateTrueColor(WIDTH, HEIGHT);
    output = fopen("bangladesh_flag.png", "wb");

    // Draw green background
    gdImageFilledRectangle(im, 0, 0, WIDTH - 1, HEIGHT - 1, GREEN);

    // Draw red circle
    int centerX = WIDTH / 2;
    int centerY = HEIGHT / 2;
    int circleRadius = 100;

    gdImageFilledEllipse(im, centerX, centerY, circleRadius * 2, circleRadius * 2, RED);

    gdImagePng(im, output);
    fclose(output);
    gdImageDestroy(im);
}

int main() {
    drawBangladeshFlag();
    return 0;
}