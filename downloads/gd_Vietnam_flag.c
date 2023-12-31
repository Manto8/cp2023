#include <stdio.h>
#include <gd.h>
#include <math.h>

#define WIDTH 600
#define HEIGHT 400
#define RED 0xDC143C  // Crimson color
#define YELLOW 0xFFFF00

void drawStar(gdImagePtr im, int x, int y, int outerRadius, int innerRadius, int color) {
    double angle = -M_PI / 2.0;  // Starting angle for the star

    gdPoint starPoints[10];

    for (int i = 0; i < 10; i++) {
        int radius = i % 2 == 0 ? outerRadius : innerRadius;
        starPoints[i].x = x + radius * cos(angle);
        starPoints[i].y = y + radius * sin(angle);
        angle += M_PI / 5.0;  // Angle between two consecutive points
    }

    gdImageFilledPolygon(im, starPoints, 10, color);
}

void drawVietnamFlag() {
    gdImagePtr im;
    FILE *output;

    im = gdImageCreateTrueColor(WIDTH, HEIGHT);
    output = fopen("vietnam_flag.png", "wb");

    // Draw red background
    gdImageFilledRectangle(im, 0, 0, WIDTH - 1, HEIGHT - 1, RED);

    // Draw yellow star in the center
    int starSize = 60;
    int starX = WIDTH / 2;
    int starY = HEIGHT / 2;

    drawStar(im, starX, starY, starSize, starSize / 2, YELLOW);

    gdImagePng(im, output);
    fclose(output);
    gdImageDestroy(im);
}

int main() {
    drawVietnamFlag();
    return 0;
}