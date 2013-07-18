#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

string removeZeros(string);
string shift(string, size_t);
string add(string, string);
string sub(string, string);
string simpleMult(string, string);
string karatsuba(string, string);


int main() {
    char buffer[1000001];

    scanf("%s", buffer);
    string X = string(buffer);
    scanf("%s", buffer);
    string Y = string(buffer);

    printf("%s\n", karatsuba(X, Y).c_str());

    return 0;
}

string removeZeros(string s) {
    size_t pos;
    for (pos = 0; pos < s.size(); pos++)
        if (s[pos] != '0') break;
    if (pos == s.size())
        return "0";
    return s.substr(pos);
}

string shift(string s, size_t n) {
    for (int i = 0; i < n; i++)
        s += "0";
    return s;
}

string add(string a, string b) {
    size_t n = a.size();
    size_t m = b.size();
    if (!n || !m) {
        printf("One of strings is NULL");
        exit(0);
    }
    size_t len = n < m ? m : n;
    for (size_t i = n; i < len; i++) a = "0" + a;
    for (size_t i = m; i < len; i++) b = "0" + b;

    string res(len, '0');
    int i, val, carry = 0;
    for (i = len-1; i >= 0; i--) {
        val = (carry + (a[i]-'0') + (b[i]-'0'));
        carry = val / 10;
        res[i] = '0' + (val % 10);
    }
    if (carry)
        res = "1" + res;

    return removeZeros(res);
}


string sub(string a, string b) {
    size_t n = a.size();
    size_t m = b.size();
    if (!n || !m) {
        printf("One of strings is NULL");
        exit(0);
    }
    size_t len = n < m ? m : n;
    for (size_t i = n; i < len; i++) a = "0" + a;
    for (size_t i = m; i < len; i++) b = "0" + b;

    string res(len, '0');
    int carry = 0;
    for (int i = len-1; i >= 0; i--) {
        int val = (carry + (a[i]-'0') - (b[i]-'0'));
        if (val < 0) {
            val += 10;
            carry = -1;
        }
        else
            carry = 0;
        res[i] = '0' + (val % 10);
    }
    // take care of minus ( should not happen here )

    return removeZeros(res);
}

string simpleMult(string X, string Y) {
    size_t n = X.size();
    size_t m = Y.size();
    if (!n || !m) {
        printf("One of strings is NULL");
        exit(0);
    }
    if (X == "0" || Y == "0") {
        return "0";
    }

    string res(n+m, '0');
    for (int i = m-1; i >= 0; i--) {
        int carry = 0;
        for (int val, j = n-1; j >= 0; j--) {
            val = (carry + (res[i+j+1] - '0') + (Y[i] - '0')*(X[j] - '0'));
            res[i+j+1] = '0' + (val % 10);
            carry = val / 10;
        }
        res[i] += carry;
    }
    return removeZeros(res);
}

string karatsuba(string X, string Y) {

    size_t n = X.size();
    size_t m = Y.size();
    size_t N = n < m ? m : n;

    if (N != 1 && N%2) {
        N = N+1;
    }

    if (N <= 4) {
        return simpleMult(X, Y);
    }

    for (int i = n; i < N; i++) X = "0" + X;
    for (int i = m; i < N; i++) Y = "0" + Y;

    string A = X.substr(0, N/2);
    string B = X.substr(N/2);
    string C = Y.substr(0, N/2);
    string D = Y.substr(N/2);

    string ac  = karatsuba(A, C);
    string bd  = karatsuba(B, D);
    string mid = karatsuba(add(A, B), add(C, D));

    string term1 = shift(ac, N);
    string term2 = shift(sub(mid, add(ac, bd)), N/2);
    string res   = add(add(term1, term2), bd);

    return res;
}
