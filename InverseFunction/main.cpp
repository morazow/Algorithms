#include "inverse_function.h"
//#include "sqrt_newtons.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

double square(double x) {
    return x * x;
}

double cube(double x) {
    return square(x) * x;
}

double power10(double x) {
    return pow(10.0, x);
}

int main(int argc, char* argv[]) {

    func_t invsqrt = inverse(square);
    func_t inv3 = inverse(cube);
    func_t inv10 = inverse(power10);

    // check with std library math functions,
    // sqrt, log10 and pow(x, 1/3) for cube root.
    for (int i = 1; i < 1000; i++) {
        double x = (double)i;

        assert ( invsqrt(x) - sqrt(x) < 0.0001 );
        assert ( inv3(x) - pow(x, 1/3.0) < 0.0001 );
        assert ( inv10(x) - log10(x) < 0.0001 );
    }
    printf("passed\n");
    double x = 10e30;
    assert ( invsqrt(x) - sqrt(x) < 0.0001 );
    assert ( inv3(x) - pow(x, 1/3.0) < 0.0001 );
    assert ( inv10(x) - log10(x) < 0.0001 );
    printf("passed\n");
    x = 10e-50;
    assert ( invsqrt(x) - sqrt(x) < 0.0001 );
    assert ( inv3(x) - pow(x, 1/3.0) < 0.0001 );
    //assert ( inv10(x) - log10(x) < 0.0001 );
    printf("passed");
    return 0;
}
