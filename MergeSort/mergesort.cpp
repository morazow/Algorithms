#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

void insertionSort(vector<int> &);
void merge(const vector<int> &, const vector<int> &, vector<int> &);
void mergeSort(vector<int> &);

bool isSorted(const vector<int> &A) {
    for (int i = 1; i < A.size(); i++)
        if (A[i-1] > A[i])
            return false;
    return true;
}

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    srand(time(NULL));
    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
        numbers[i] = rand();

    clock_t start = clock();
    mergeSort(numbers);
    start = clock() - start;
    assert(isSorted(numbers));
    fprintf(stderr, "%d %.2f\n", N, 1000 * (double)(start) / CLOCKS_PER_SEC);

    return 0;
}

void insertionSort(vector<int> &A) {
    for (int i = 0; i < A.size(); i++)
        for (int j = i; j > 0 && A[j] < A[j-1]; j--)
            swap(A[j], A[j-1]);
}

void merge(const vector<int> &L, const vector<int> &R, vector<int> &A) {
    int N = A.size(), k, i = 0, j = 0;
    for (k = 0; k < N; k++) {
        if (i == L.size() || j == R.size())
            break;
        if (L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
    while (i < L.size()) A[k++] = L[i++];
    while (j < R.size()) A[k++] = R[j++];
}

void mergeSort(vector<int> &A) {
    int size = A.size();
    if (size <= 4) {
        insertionSort(A);
        return ;
    }

    vector<int> left(A.begin(), A.begin()+(size>>1));
    vector<int> right(A.begin()+(size>>1), A.end());
    mergeSort(left);
    mergeSort(right);
    merge(left, right, A);
}
