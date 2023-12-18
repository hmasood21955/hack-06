#include "colorUtils.h"
#include <math.h>
int rgbToCmyk(int r, int g, int b, double* c, double* m, double* y, double* k) {
    if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255) {
        return 1;
    }

    if (r == 0 && g == 0 && b == 0) {
        *c = 0;
        *m = 0;
        *y = 0;
        *k = 1;
    } else {
        *c = 1 - (double)r / 255;
        *m = 1 - (double)g / 255;
        *y = 1 - (double)b / 255;

        double minCMY = fmin(fmin(*c, *m), *y);
        *c = (*c - minCMY) / (1 - minCMY);
        *m = (*m - minCMY) / (1 - minCMY);
        *y = (*y - minCMY) / (1 - minCMY);
        *k = minCMY;
    }

    return 0; 
}
int cmykToRgb(double c, double m, double y, double k, int* r, int* g, int* b) {
    if (c < 0 || m < 0 || y < 0 || k < 0 || c > 1 || m > 1 || y > 1 || k > 1) {
        return 1; // Error: CMYK values out of range
    }
    *r = round(255 * (1 - c) * (1 - k));
    *g = round(255 * (1 - m) * (1 - k));
    *b = round(255 * (1 - y) * (1 - k));

    return 0; // No error
}
