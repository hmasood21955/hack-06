#include "colorUtils.h"
#include <math.h>
int rgbToCmyk(int r, int g, int b, double* c, double* m, double* y, double* k) {
    if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255) {
        return 1;
    }
