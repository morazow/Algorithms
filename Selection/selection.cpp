#include <vector>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <algorithm>

using namespace std;

int Partition(vector<int>& A, int L, int R) {
    int pivot = L + rand() % (R - L + 1);
    swap(A[L], A[pivot]);

    int i = L+1;
    for (int j = L+1; j <= R; j++)
        if (A[j] <= A[L]) swap(A[j], A[i++]);
    swap(A[L], A[i-1]);

    return i-1;
}

int Randomized(vector<int>& A, int L, int R, int K) {
    if (L == R)
        return A[L];

    int P = Partition(A, L, R);
    int Q = P - L + 1; // rank of P

    if (Q == K)
        return A[P];
    if (Q < K)
        return Randomized(A, P+1, R, K-Q);
    else
        return Randomized(A, L, P-1, K);
}

int main() {
    srand(time(NULL));

    int N = 10000;
    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
        numbers[i] = rand();

    int K, res, Tcases = 1000;
    while (Tcases--) {
        random_shuffle(numbers.begin(), numbers.end());
        K = rand()%N + 1;

        res = Randomized(numbers, 0, N-1, K);

        nth_element(numbers.begin(), numbers.begin()+K-1, numbers.end());

        assert(res == numbers[K-1]);
    }
}
