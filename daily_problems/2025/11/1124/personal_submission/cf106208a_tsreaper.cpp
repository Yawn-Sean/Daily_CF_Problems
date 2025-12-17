#include <bits/stdc++.h>
#define MAXN ((int) 2e6)
#define MOD 998244353
using namespace std;

long long f[MAXN + 5], g[MAXN + 5];

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

void solve() {
    int l, r; scanf("%d%d", &l, &r);
    int len = r - l + 1;
    long long ans = (g[len] + f[len] * (l - 1)) % MOD;
    printf("%lld\n", ans);
}

int main() {
    long long inv2 = power(2, MOD - 2);

    f[1] = g[1] = 1;
    long long sf0 = 0, sf1 = 0, sf2 = 0;
    long long sg0 = 0, sg1 = 0;
    for (int i = 2; i <= MAXN; i++) {
        sf0 = (sf0 + f[i - 1]) % MOD;
        sf1 = (sf1 + f[i - 1] * (i - 1)) % MOD;
        sf2 = (sf2 + f[i - 1] * (i - 1) % MOD * (i - 1)) % MOD;
        sg0 = (sg0 + g[i - 1]) % MOD;
        sg1 = (sg1 + g[i - 1] * (i - 1)) % MOD;

        long long u = ((i + 1) * sf0 - sf1 + MOD) % MOD;
        long long v = 1LL * i * (i + 1) / 2 - 1;
        v = power(v % MOD, MOD - 2);
        f[i] = (u * v + 1) % MOD;

        u = ((i + 1) * sg0 - sg1 + MOD) % MOD;
        long long t0 = (1LL * i * i + i) % MOD * sf0 % MOD;
        long long t1 = (-(2 * i + 1) * sf1 % MOD + MOD) % MOD;
        long long t2 = sf2;
        u = (u + (t0 + t1 + t2) * inv2) % MOD;
        g[i] = (u * v + (1 + i) * inv2) % MOD;
    }

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
