#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_roc_flag(gdImagePtr img);

// 函數原型
int lineCircleIntersection(int x1, int y1, int x2, int y2, int cx, int cy, int cr, int *x, int *y);

int main() {
    int width = 1200;
    int height = (int)(width * 2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_roc_flag(img);

    FILE *outputFile = fopen("roc_flag2.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}

void draw_roc_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, white, blue;
    int center_x = (int)(width / 4);
    int center_y = (int)(height / 4);

    red = gdImageColorAllocate(img, 255, 0, 0);
    white = gdImageColorAllocate(img, 255, 255, 255);
    blue = gdImageColorAllocate(img, 0, 0, 149);

    gdImageFilledRectangle(img, 0, 0, width, height, red);
    gdImageFilledRectangle(img, 0, 0, (int)(width / 2.0), (int)(height / 2.0), blue);

    int A_x = 429;
    int A_y = 125;
    int B_x = 279;
    int B_y = 165;
    int E_x = 170;
    int E_y = 274;
    int D_x = 319;
    int D_y = 234;

    // Draw lines
    gdImageLine(img, A_x, A_y, B_x, B_y, white);
    gdImageLine(img, B_x, B_y, E_x, E_y, white);
    gdImageLine(img, E_x, E_y, D_x, D_y, white);
    gdImageLine(img, D_x, D_y, A_x, A_y, white);

    // Coordinates of the sun's circle
    int sun_center_x = (int)(width / 4);
    int sun_center_y = (int)(height / 4);
    int sun_radius = (int)(width / 8);

    // Draw sun's circle with reduced radius
    int new_sun_radius = sun_radius / 2;
    gdImageFilledEllipse(img, sun_center_x, sun_center_y, new_sun_radius * 2, new_sun_radius * 2, white);

    int intersection1_x, intersection1_y;
    int intersection2_x, intersection2_y;
    int intersection3_x, intersection3_y;
    int intersection4_x, intersection4_y;

    // Calculate intersections
    lineCircleIntersection(A_x, A_y, B_x, B_y, sun_center_x, sun_center_y, new_sun_radius, &intersection1_x, &intersection1_y);
    lineCircleIntersection(B_x, B_y, E_x, E_y, sun_center_x, sun_center_y, new_sun_radius, &intersection2_x, &intersection2_y);
    lineCircleIntersection(E_x, E_y, D_x, D_y, sun_center_x, sun_center_y, new_sun_radius, &intersection3_x, &intersection3_y);
    lineCircleIntersection(D_x, D_y, A_x, A_y, sun_center_x, sun_center_y, new_sun_radius, &intersection4_x, &intersection4_y);

    printf("Intersection 1: (%d, %d)\n", intersection1_x, intersection1_y);
    printf("Intersection 2: (%d, %d)\n", intersection2_x, intersection2_y);
    printf("Intersection 3: (%d, %d)\n", intersection3_x, intersection3_y);
    printf("Intersection 4: (%d, %d)\n", intersection4_x, intersection4_y);
}

// 計算直線與圓相交的座標
int lineCircleIntersection(int x1, int y1, int x2, int y2, int cx, int cy, int cr, int *x, int *y) {
    float dx, dy, A, B, C, det, t;

    dx = x2 - x1;
    dy = y2 - y1;

    A = dx * dx + dy * dy;
    B = 2 * (dx * (x1 - cx) + dy * (y1 - cy));
    C = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) - cr * cr;

    det = B * B - 4 * A * C;

    if ((A <= 0.00001) || (det < 0)) {
        // No real solutions
        return 0;
    }

    t = (-B - sqrt(det)) / (2 * A);
    *x = x1 + t * dx;
    *y = y1 + t * dy;

    return 1;
}