#include <bits/stdc++.h>
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, m, G, X, cnt[10];

struct Matrix {
    int n, m;
    long long V[100][100];

    Matrix(int n, int m): n(n), m(m) {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) V[i][j] = 0;
    }

    Matrix operator*(const Matrix &A) const {
        Matrix B(n, A.m);
        for (int i = 0; i < n; i++) for (int j = 0; j < A.m; j++) for (int k = 0; k < m; k++)
            B.V[i][j] = (B.V[i][j] + V[i][k] * A.V[k][j]) % MOD;
        return B;
    }
};

Matrix power(Matrix &A, long long b) {
    Matrix Y(A.n, A.n);
    for (int i = 0; i < Y.n; i++) Y.V[i][i] = 1;
    for (; b; b >>= 1) {
        if (b & 1) Y = Y * A;
        A = A * A;
    }
    return Y;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &G, &X);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }

    Matrix K(X, X);
    for (int i = 0; i < X; i++) for (int j = 1; j <= 9; j++) {
        int ii = (i * 10 + j) % X;
        K.V[i][ii] = (K.V[i][ii] + cnt[j]) % MOD;
    }
    K = power(K, m);

    Matrix A(1, X);
    A.V[0][0] = 1;
    A = A * K;
    printf("%lld\n", A.V[0][G]);
    return 0;
}
