#include <bits/stdc++.h>
#define MAXN 100
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, K;
long long m;

long long f[2][MAXN * MAXN + 5], g[MAXN + 5][MAXN + 5][2], C[MAXN + 5][MAXN + 5];

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    scanf("%d%lld%d", &n, &m, &K);
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    for (int i = 0; i <= n; i++) for (int j = 0; j <= i; j++) {
        g[i][j][0] = power(C[i][j], m / n);
        g[i][j][1] = g[i][j][0] * C[i][j] % MOD;
    }

    f[0][0] = 1;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= K && j <= n * i; j++) {
        f[i & 1][j] = 0;
        for (int k = 0; k <= j && k <= n; k++)
            f[i & 1][j] = (f[i & 1][j] + f[i & 1 ^ 1][j - k] * g[n][k][i <= m % n ? 1 : 0]) % MOD;
    }
    printf("%lld\n", f[n & 1][K]);
    return 0;
}
