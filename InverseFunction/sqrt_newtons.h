#ifndef _NEWTONS_H_
#define _NEWTONS_H_

// C
#include <stdio.h>
#include <math.h>

const double EPS = 1e-9;

double sqrt_newtons(double x, double guess = 1.0) {
    if (fabs(x - guess * guess) < EPS)
        return guess;
    return sqrt_newtons(x, (guess + x / guess) / 2);
}
#endif
