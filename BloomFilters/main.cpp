#include "bloomfilter.h"
#include <stdio.h>
#include <string.h>

int a_hash(const char *str) {
    return strlen(str)+1;
}

int main() {
    BloomFilter *bf = new BloomFilter(100, 2, a_hash);

    delete bf;
    return 0;
}
