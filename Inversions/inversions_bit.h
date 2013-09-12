/*
 * Counting Inversions using cool data structure,
 * called Binary Indexed Tree (Fenwick Tree).
 * For more, http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binaryIndexedTrees
 *
 */
#include <vector>
#include <stdint.h>

typedef uint64_t ull;

ull count_inversions(const std::vector<int>& A) {
    std::size_t N = A.size();
    std::vector<int> Sum(N+1, 0);

    ull res = (ull)N * (N - 1) / 2;

    for (std::vector<int>::const_iterator it = A.begin(); it != A.end(); it++) {
        int x = *it;
        while (x > 0) res -= Sum[x], x -= x & -x;
        x = *it;
        while (x <= N) Sum[x]++, x += x & -x;
    }

    return res;
}
