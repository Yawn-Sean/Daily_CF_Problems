#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, K, A[MAXN], B[MAXN];
long long ans;

struct Matrix {
    int n, m;
    vector<long long> val;

    Matrix(int n, int m): n(n), m(m) {
        val.resize(n * m);
    }

    long long get(int i, int j) const {
        return val[i * m + j];
    }

    void set(int i, int j, long long v) {
        val[i * m + j] = v;
    }

    Matrix operator*(const Matrix &o) const {
        Matrix res(n, o.m);
        for (int k = 0; k < m; k++) for (int i = 0; i < n; i++) for (int j = 0; j < o.m; j++)
            res.set(i, j, (res.get(i, j) + get(i, k) * o.get(k, j)) % MOD);
        return res;
    }
};

Matrix power(Matrix A, long long b) {
    Matrix Y(A.n, A.n);
    for (int i = 0; i < A.n; i++) Y.set(i, i, 1);
    for (; b; b >>= 1) {
        if (b & 1) Y = Y * A;
        A = A * A;
    }
    return Y;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < n; i++) scanf("%d", &B[i]);

    Matrix X(n, 2), Y(2, n);
    for (int i = 0; i < n; i++) {
        X.set(i, 0, A[i] + B[i]);
        X.set(i, 1, B[i]);
        Y.set(0, i, A[i] + B[i]);
        Y.set(1, i, -B[i]);
    }

    Matrix M(1, n);
    M.set(0, 0, 1);
    M = M * X * power(Y * X, K - 1) * Y;

    for (int i = 0; i < n; i++) ans = (ans + M.get(0, i)) % MOD;
    printf("%lld\n", ans);
    return 0;
}
