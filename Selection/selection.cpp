#include <vector>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <algorithm>

using namespace std;


// return Median of Median of A in interval [L..R)
int Median(vector<int>& A, int L, int R) {
    if (R - L <= 5) {
        sort(A.begin()+L, A.begin()+R);
        return A[(R - L) / 2];
    }

    int size = (R - L) / 5;

    vector<int> tempA;
    tempA.reserve(size);
    for (int i = 0; i < size; i++) {
        tempA[i] = Median(A, L + i * 5, L + (i + 1) * 5);
    }

    return Median(tempA, 0, size);
}

// flag = true  for Randomized selection
// flag = false for Deterministic
int Partition(vector<int>& A, int L, int R, bool flag) {
    int pivot;
    if (flag)
        pivot = A[L + rand() % (R - L)];
    else
        pivot = Median(A, L, R);

    //swap(A[L], pivot);
    printf("pivot = %d\n", pivot);

    int i = L, pos = -1;
    for (int j = L; j < R; j++)
        if (A[j] <= pivot) {
            if (A[j] == pivot && pos < 0)
                pos = j;
            swap(A[j], A[i]);
            i++;
        }
    assert(pos >= 0);
    swap(A[pos], A[i-1]);

    return i-1;
}

int Randomized(vector<int>& A, int L, int R, int K, bool flag) {
    if (R - L <= 1)
        return A[L];

    int P = Partition(A, L, R, flag);
    int Q = P - L + 1; // rank of P

    if (Q == K)
        return A[P];
    if (Q < K)
        return Randomized(A, P+1, R, K-Q, flag);
    else
        return Randomized(A, L, P, K, flag);
}

int main() {

    int N = 10;
    vector<int> numbers(N);

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % 100;
    }
    for (int i = 0; i < N; i++) printf("%d ",numbers[i]); printf("\n");

    int K, res, Tcases = 1;
    while (Tcases--) {
        K = rand()%N + 1;
        printf("K = %d\n", K);

        random_shuffle(numbers.begin(), numbers.end());
        res = Randomized(numbers, 0, N, K, false);
        printf("res = %d\n", res);
        //for (int i = 0; i < N; i++) printf("%d ",numbers[i]); printf("\n\n");

        random_shuffle(numbers.begin(), numbers.end());
        nth_element(numbers.begin(), numbers.begin()+K-1, numbers.end());
        printf("num = %d\n", numbers[K-1]);
        for (int i = 0; i < N; i++) printf("%d ",numbers[i]); printf("\n\n");

        assert(res == numbers[K-1]);
    }
}
