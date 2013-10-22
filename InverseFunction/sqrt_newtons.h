#ifndef _NEWTONS_H_
#define _NEWTONS_H_

// C
#include <stdio.h>
#include <math.h>

const double EPS = 1e-15;

double sqrt_newtons(double x, double guess = 1.0) {
    // assert( x > 0 );
    /*
     * if (fabs(x - guess * guess) < EPS)
     * This check is problematic; for very very small
     * numbers it will result in wrong answer, and for
     * very large numbers it will go into infinite loop.
     * So we need to normalize it by number (x) itself
     * before checking.
     *
     */
    if (fabs(x - guess * guess) / x < EPS)
        return guess;
    return sqrt_newtons(x, (guess + x / guess) / 2);
}
#endif
