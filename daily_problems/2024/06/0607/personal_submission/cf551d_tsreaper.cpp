#include <bits/stdc++.h>
using namespace std;

long long n, K, L, MOD, ans;

struct Matrix {
    int n, m;
    long long v[2][2];

    Matrix(int n, int m): n(n), m(m) { memset(v, 0, sizeof(v)); }

    Matrix operator*(const Matrix &o) const {
        Matrix r(n, o.m);
        for (int k = 0; k < m; k++) for (int i = 0; i < n; i++) for (int j = 0; j < o.m; j++)
            r.v[i][j] = (r.v[i][j] + v[i][k] * o.v[k][j]) % MOD;
        return r;
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

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    scanf("%lld%lld%lld%lld", &n, &K, &L, &MOD);
    if (MOD == 1) { printf("0\n"); return 0; }
    if (L <= 60 && K >= (1LL << L)) { printf("0\n"); return 0; }

    Matrix k(2, 2);
    k.v[0][0] = 1; k.v[1][0] = 1;
    k.v[0][1] = 1;
    k = power(k, n - 1);
    Matrix a(1, 2);
    a.v[0][0] = 1; a.v[0][1] = 1;
    a = a * k;

    long long tmp[2];
    tmp[0] = (a.v[0][0] + a.v[0][1]) % MOD;
    tmp[1] = (power(2, n) - tmp[0] + MOD) % MOD;

    ans = 1;
    for (int p = 0; p < L; p++) ans = ans * tmp[K >> p & 1] % MOD;
    printf("%lld\n", ans);
    return 0;
}
