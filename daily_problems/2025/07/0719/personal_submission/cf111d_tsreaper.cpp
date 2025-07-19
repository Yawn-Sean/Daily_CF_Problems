#include <bits/stdc++.h>
#define MAXN 1000
#define MAXK ((int) 1e6)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, m, K;
long long ans;

long long f[MAXN + 5], fac[MAXK + 5], ifac[MAXK + 5];

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

long long C(int a, int b) {
    if (a < b) return 0;
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    if (m == 1) { printf("%lld\n", power(K, n)); return 0; }

    fac[0] = fac[1] = 1;
    for (int i = 2; i <= K; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= K; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= K; i++) ifac[i] = ifac[i - 1] * ifac[i] % MOD;

    for (int i = 1; i <= n && i <= K; i++) {
        f[i] = power(i, n);
        for (int j = 1; j < i; j++) f[i] = (f[i] - f[j] * C(i, j) % MOD + MOD) % MOD;
    }

    for (int i = 0; i <= n && i <= K; i++) {
        long long t;
        if (i == 0) {
            if (m == 2) t = 1;
            else t = 0;
        } else {
            t = power(i, n * (m - 2));
        }
        for (int j = 0; i + j <= n && i + j * 2 <= K; j++) if (i + j > 0) {
            long long w = t * C(K, i) % MOD * C(K - i, j) % MOD * C(K - i - j, j) % MOD;
            ans = (ans + f[i + j] * f[i + j] % MOD * w) % MOD;
        }        
    }

    printf("%lld\n", ans);
    return 0;
}
