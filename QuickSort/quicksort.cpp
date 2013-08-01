#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

void quicksort(int, int, vector<int>&);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage %s <number of elements>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    assert( N > 0 );

    vector<int> numbers(N);

    srand(time(NULL));
    for (int i = 0; i < N; i++)
        numbers[i] = rand();

    quicksort(0, N, numbers);

    for (int i = 1; i < N; i++)
        assert(numbers[i - 1] <= numbers[i]);

    return 0;
}

// Notice we are not sorting here the three elements, but
// it might better to do so. (no reasonable expalanation why yet)
int get_median(int l, int r, vector<int>& A) {
    int m = (l + r - 1) >> 1;
    if (A[l] < A[r - 1]) {
        return A[m] < A[l] ? l : A[m] < A[r - 1] ? m : r - 1;
    }
    else {
        return A[m] > A[l] ? l : A[m] > A[r - 1] ? m : r - 1;
    }
}

int choose_pivot(int l, int r, vector<int>& A) {
#ifdef LAST
    return r - 1;
#elif MEDIAN
    // median of first, last and mid elements
    return get_median(l, r, A);
#endif
    // by default FIRST
    return l;
}

int partition(int l, int r, vector<int>& A) {
    int pivot = choose_pivot(l, r, A);

    // We might use different methods to select the pivot
    // element, do not forget to swap it with the first element.
    swap(A[l], A[pivot]);

    // So now, our pivot element is located at the beginning of
    // the array.

    int i = l+1;
    for (int j = l+1; j < r; j++) {
        if (A[j] <= A[l])
            swap(A[j], A[i++]);
    }
    // put pivot to its place
    swap(A[l], A[i-1]);

    return i - 1;
}

void quicksort(int l, int r, vector<int>& A) {
    if (r - l <= 1)
        return ;

    int p = partition(l, r, A);
    quicksort(l, p, A);
    quicksort(p+1, r, A);
}
