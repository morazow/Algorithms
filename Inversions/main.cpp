#include "inversions_merge.h"
#include "inversions_bit.h"

// C
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    int N = 100000, n;
    std::vector<int> A;
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        A.push_back(n);
    }
    // count_inversions does not change input array A.
    assert( count_inversions(A) == merge_sort(0, N-1, A) );
    return 0;
}
