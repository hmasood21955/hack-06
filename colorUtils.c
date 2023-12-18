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
