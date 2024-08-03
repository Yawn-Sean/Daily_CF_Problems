#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MAXM 100
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, L, m, A[MAXN + 10], B[MAXN + 10], C[MAXN + 10];
long long ans;

struct Matrix {
    int n, m;
    long long V[MAXM][MAXM];

    Matrix(int n, int m): n(n), m(m) {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) V[i][j] = 0;
    }

    Matrix operator *(const Matrix &o) const {
        Matrix ret(n, o.m);
        for (int i = 0; i < n; i++) for (int j = 0; j < o.m; j++) for (int k = 0; k < m; k++)
            ret.V[i][j] = (ret.V[i][j] + V[i][k] * o.V[k][j]) % MOD;
        return ret;
    }
};

Matrix power(Matrix a, int b) {
    Matrix y(a.n, a.n);
    for (int i = 0; i < a.n; i++) y.V[i][i] = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a;
        a = a * a;
    }
    return y;
}

int main() {
    scanf("%d%d%d", &n, &L, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &C[i]);

    int cnt[MAXM] = {0};
    for (int i = 1; i <= n; i++) cnt[B[i] % m]++;
    Matrix K(m, m);
    for (int i = 0; i < m; i++) for (int d = 0; d < m; d++) {
        int j = (i + d) % m;
        K.V[i][j] = (K.V[i][j] + cnt[d]) % MOD;
    }
    K = power(K, L - 2);

    Matrix M(1, m);
    for (int i = 1; i <= n; i++) M.V[0][A[i] % m]++;
    M = M * K;

    for (int i = 1; i <= n; i++) ans = (ans + M.V[0][(-B[i] % m - C[i] % m + m * 2) % m]) % MOD;
    printf("%lld\n", ans);
    return 0;
}
