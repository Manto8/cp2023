#include <stdio.h>
#include <gd.h>

int main() {
    int width = 300;  // 宽度
    int height = 200; // 高度

    gdImagePtr image = gdImageCreateTrueColor(width, height);

    if (image == NULL) {
        printf("Failed to create image.\n");
        return 1;
    }

    // 确定颜色索引
    int green = gdImageColorAllocate(image, 0, 128, 0);
    int white = gdImageColorAllocate(image, 255, 255, 255);
    int red = gdImageColorAllocate(image, 255, 0, 0);

    // 填充颜色
    gdImageFilledRectangle(image, 0, 0, width / 3, height, green);
    gdImageFilledRectangle(image, width / 3, 0, (width / 3) * 2, height, white);
    gdImageFilledRectangle(image, (width / 3) * 2, 0, width, height, red);

    FILE *outputFile;
    outputFile = fopen("./../images/italian_flag.png", "wb");

    if (outputFile == NULL) {
        printf("Failed to open file for writing.\n");
        return 1;
    }

    gdImagePng(image, outputFile);
    fclose(outputFile);

    gdImageDestroy(image);

    return 0;
}
