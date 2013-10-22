#include "sqrt_newtons.h"

int main(int argc, char* argv[]) {

    for (int i = 0; i < 100; i++) {
        printf("%d %f\n", i, sqrt_newtons((double)i));
    }

    return 0;
}
