#include "inverse_function.h"
#include "sqrt_newtons.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

double square(double x) {
    return x * x;
}

double cube(double x) {
    return square(x) * x;
}

int main(int argc, char* argv[]) {
    func_t inv = inverse(square);
    printf("%f\n", inv(10)); // 100 + 10

    func_t inv3 = inverse(cube);
    printf("%f\n", inv3(2)); // 8 + 2

    func_t inv10 = inverse(log10);
    printf("%f\n", inv10(1000));// 3 + 1000
    return 0;
}
