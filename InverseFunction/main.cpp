#include "sqrt_newtons.h"
#include <assert.h>

int main(int argc, char* argv[]) {

    for (int i = 100000; i < 100000000; i++) {
        assert( sqrt_newtons((double)i) - sqrt((double)i) < 0.0001);
    }
    assert( sqrt_newtons(1e-50) - sqrt(1e-50) < 0.0001);
    assert( sqrt_newtons(1e60) - sqrt(1e60) < 0.0001);

    return 0;
}
