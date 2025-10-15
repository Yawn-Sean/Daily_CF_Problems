#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MOD 998244353
using namespace std;

int n, K;
long long ans;

long long f[MAXN + 5];
long long fac[MAXN + 5], ifac[MAXN + 5];

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    scanf("%d%d", &n, &K);

    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= n; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= n; i++) ifac[i] = ifac[i - 1] * ifac[i] % MOD;

    for (int i = 0; i <= n; i++) {
        if (i <= K) f[i] = fac[i] * power(i + 1, K - i + 1) % MOD;
        else f[i] = fac[K + 1];
    }
    ans = 1;
    for (int i = 1; i <= n; i++) {
        long long t = fac[n] * ifac[n - i] % MOD;
        ans = (ans + (f[i] - f[i - 1] + MOD) * t) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
