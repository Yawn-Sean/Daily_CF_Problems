#include <bits/stdc++.h>
#define LIM (1 << 7)
using namespace std;
typedef long double ldb;

struct Matrix {
    int n, m;
    ldb v[LIM][LIM];

    Matrix(int n, int m): n(n), m(m) {
        memset(v, 0, sizeof(v));
    }

    Matrix operator*(const Matrix &o) const {
        Matrix ret(n, o.m);
        for (int k = 0; k < m; k++) for (int i = 0; i < n; i++) for (int j = 0; j < o.m; j++)
            ret.v[i][j] += v[i][k] * o.v[k][j];
        return ret;
    }
};

Matrix power(Matrix a, long long b) {
    Matrix y(a.n, a.m);
    for (int i = 0; i < y.n; i++) y.v[i][i] = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a;
        a = a * a;
    }
    return y;
}

int n, X;
ldb A[LIM];

int main() {
    scanf("%d%d", &n, &X);
    for (int i = 0; i <= X; i++) scanf("%Lf", &A[i]);
    Matrix k(LIM, LIM);
    for (int i = 0; i < LIM; i++) for (int j = 0; j < LIM; j++) k.v[i][j] += A[i ^ j];
    k = power(k, n);
    Matrix a(1, LIM);
    a.v[0][0] = 1;
    a = a * k;
    printf("%.12Lf\n", 1 - a.v[0][0]);
    return 0;
}
