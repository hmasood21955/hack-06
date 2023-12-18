#ifndef COLORUTILS_H
#define COLORUTILS_H

int rgbToCmyk(int r, int g, int b, double* c, double* m, double* y, double* k);
int cmykToRgb(double c, double m, double y, double k, int* r, int* g, int* b);
