#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXL 1000001

void getNumber(char *, int &, vector<int> &);
vector<int> karatsuba(const vector<int> &, const vector<int> &);
void carry_result(vector<int> &);
void print_result(const vector<int> &, int);

int main() {
    char *pos, buffer[MAXL];
    int sign = 0;
    vector<int> X, Y;

    scanf("%s", buffer);
    getNumber(buffer, sign, X);

    scanf("%s", buffer);
    getNumber(buffer, sign, Y);

    // make length of number power of two
    int size = 1, max_len = X.size() > Y.size() ? X.size() : Y.size();
    for (; size < max_len; size <<= 1) ;

    // better for doing carry
    reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());

    // pad some zeros to front
    while (X.size() < size) X.push_back(0);
    while (Y.size() < size) Y.push_back(0);

    vector<int> result = karatsuba(X, Y);
    carry_result(result);
    print_result(result, sign);

    return 0;
}

void getNumber(char *pos, int &sign, vector<int> &number) {
    if (*pos=='-') {
        sign = !sign;
        pos++;
    }
    while (pos && *pos != 0)
        number.push_back(*pos++ - '0');
}

vector<int> karatsuba(const vector<int> &X, const vector<int> &Y) {
    int N = X.size();
    int M = N >> 1;
    vector<int> res(N << 1, 0);

    if (N <= 128) {
        // do simple grade school mult
        for (int i = 0; i < X.size(); i++) {
            if (!X[i]) continue;
            for (int j = 0; j < Y.size(); j++)
                if (Y[j]) res[i + j] += X[i] * Y[j];
        }
        return res;
    }

    // Since we reversed the numbers
    // pay attention to order when dividing into half

    // X = 10^N/2 * a + b
    vector<int> a(X.begin()+M, X.end());
    vector<int> b(X.begin(), X.begin()+M);

    // Y = 10^N/2 * c + d
    vector<int> c(Y.begin()+M, Y.end());
    vector<int> d(Y.begin(), Y.begin()+M);

    // term1 = a * c
    vector<int> term1 = karatsuba(a, c);

    // term2 = b * d
    vector<int> term2 = karatsuba(b, d);

    // term3 = (a + b) * (b + d) - b*d - a*c
    for (int i = 0; i < M; i++) {
        a[i] += b[i];
        c[i] += d[i];
    }

    vector<int> term3 = karatsuba(a, c);

    for (int i = 0; i < term3.size(); i++) {
        term3[i] -= term1[i] + term2[i];
    }

    // X * Y = 10^N * term1 + 10*N/2 * term3 + term2
    for (int i = 0; i < N; i++) {
        res[i + N] += term1[i];
        res[i + M] += term3[i];
        res[i] += term2[i];
    }

    return res;
}

void carry_result(vector<int> &res) {
    int carry = 0;
    for (int i = 0; i < res.size(); i++) {
        res[i] += carry;
        if (res[i])
            carry = res[i] / 10;
        res[i] -= carry * 10;
    }
}

void print_result(const vector<int> &res, int sign) {
    int size = res.size();
    while (res[size] == 0) size--;
    if (sign) printf("-");
    for (int i = size; i >= 0; i--) printf("%d", res[i]);
}
