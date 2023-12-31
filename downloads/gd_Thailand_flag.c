#include <stdio.h>
#include <gd.h>
#include <math.h>

#define WIDTH 600
#define HEIGHT 400

void drawThaiFlag(gdImagePtr im) {
    int white = gdImageColorAllocate(im, 255, 255, 255);
    int indigo = gdImageColorAllocate(im, 46, 49, 146);  // 較深的靛藍色
    int red = gdImageColorAllocate(im, 255, 0, 0);

    // Draw white background
    gdImageFilledRectangle(im, 0, 0, WIDTH, HEIGHT, white);

    // Calculate stripe heights based on the specified ratio
    int totalStripes = 5;
    int stripeHeights[5] = {1, 1, 2, 1, 1};
    int totalHeight = 0;
    for (int i = 0; i < totalStripes; ++i) {
        totalHeight += stripeHeights[i];
    }

    // Draw stripes
    int startY = 0;
    for (int i = 0; i < totalStripes; ++i) {
        int stripeHeight = stripeHeights[i] * HEIGHT / totalHeight;
        switch (i % 5) {
            case 0: // Red stripe
                gdImageFilledRectangle(im, 0, startY, WIDTH, startY + stripeHeight, red);
                break;
            case 1: // White stripe
                gdImageFilledRectangle(im, 0, startY, WIDTH, startY + stripeHeight, white);
                break;
            case 2: // Indigo stripe (靛藍色)
                gdImageFilledRectangle(im, 0, startY, WIDTH, startY + stripeHeight, indigo);
                break;
            case 3: // White stripe
                gdImageFilledRectangle(im, 0, startY, WIDTH, startY + stripeHeight, white);
                break;
            case 4: // Red stripe
                gdImageFilledRectangle(im, 0, startY, WIDTH, startY + stripeHeight, red);
                break;
        }
        startY += stripeHeight;
    }
}

int main() {
    gdImagePtr im;
    FILE *outputFile;

    // Create a new image with specified width and height
    im = gdImageCreate(WIDTH, HEIGHT);

    // Draw the Thai flag on the image
    drawThaiFlag(im);

    // Open a file for writing
    outputFile = fopen("thai_flag.png", "wb");

    // Write the image to the file in PNG format
    gdImagePng(im, outputFile);

    // Close the file
    fclose(outputFile);

    // Free the memory used for the image
    gdImageDestroy(im);

    return 0;
}