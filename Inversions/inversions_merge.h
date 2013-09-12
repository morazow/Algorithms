#include <vector>
#include <stdint.h>

typedef uint64_t ull;

ull merge(int l, int m, int r, std::vector<int>& A) {
    std::vector<int> temp;
    int i, j;
    ull res = 0;

    for (i = l, j = m; i < m && j <= r; ) {
        if (A[i] <= A[j])
            temp.push_back(A[i++]);
        else
            temp.push_back(A[j++]), res += m - i;
    }
    while (i < m) temp.push_back(A[i++]);
    while (j <=r) temp.push_back(A[j++]);
    for (int k = 0, i = l; i <= r; i++) A[i] = temp[k++];

    return res;
}

ull merge_sort(int l, int r, std::vector<int>& A) {
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    return merge_sort(l, mid, A) +
           merge_sort(mid+1, r, A) +
           merge(l, mid+1, r, A);
}
