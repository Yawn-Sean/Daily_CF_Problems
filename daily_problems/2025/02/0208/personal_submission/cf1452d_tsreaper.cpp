#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MOD 998244353
using namespace std;

int n;
long long ans;

long long f[MAXN + 5], g[2];

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    scanf("%d", &n);

    f[0] = f[1] = 1;
    g[0] = g[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = g[i & 1 ^ 1];
        g[i & 1] = (g[i & 1] + f[i]) % MOD;
    }

    long long inv = power(2, MOD - 2);
    ans = f[n];
    for (int i = 1; i <= n; i++) ans = ans * inv % MOD;
    printf("%lld\n", ans);
    return 0;
}
