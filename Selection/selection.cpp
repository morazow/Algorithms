#include <vector>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <algorithm>

using namespace std;

int Partition(vector<int>& A, int L, int R) {
    int pivot = L + rand() % (R - L);
    swap(A[L], A[pivot]);

    int i = L+1;
    for (int j = L+1; j < R; j++)
        if (A[j] <= A[L]) swap(A[j], A[i++]);
    swap(A[L], A[i-1]);

    return i-1;
}

int Randomized(vector<int>& A, int L, int R, int K) {
    if (R - L <= 1)
        return A[L];

    int P = Partition(A, L, R);
    if (P == K)
        return A[P];
    if (P < K)
        return Randomized(A, P+1, R, K-P);
    else
        return Randomized(A, L, P, K);
}

int main() {
    int N = 100;
    vector<int> numbers(N);

    srand(time(NULL));
    for (int i = 0; i < N; i++)
        numbers[i] = rand();

    int K = 0;
    int res = Randomized(numbers, 0, N, K);

    sort(numbers.begin(), numbers.end());
    assert(res == numbers[K]);
}
