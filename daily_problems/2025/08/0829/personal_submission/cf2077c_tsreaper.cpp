#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MOD 998244353
using namespace std;

int n, q;
char s[MAXN + 5];

long long inv4, f[MAXN + 5], g[MAXN + 5], h[MAXN + 5];

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

long long f0(int x) {
    return x > 0 ? f[x - 1] : 1;
}

long long f1(int x) {
    return x > 0 ? f[x - 1] : 0;
}

void solve() {
    scanf("%d%d%s", &n, &q, s + 1);

    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') a++;
        else b++;
    }

    while (q--) {
        int x; scanf("%d", &x);
        if (s[x] == '0') a--, b++;
        else a++, b--;
        s[x] ^= 1;

        long long ans = f[a] * h[b] % MOD;
        ans = (ans - 2LL * g[a] * g[b] % MOD + MOD) % MOD;
        ans = (ans + h[a] * f[b]) % MOD;
        ans = (ans - f0(a) * f1(b) % MOD + MOD) % MOD;
        ans = (ans - f1(a) * f0(b) % MOD + MOD) % MOD;
        printf("%lld\n", ans * inv4 % MOD);
    }
}

int main() {
    inv4 = power(4, MOD - 2);
    f[0] = 1;
    for (int i = 1; i <= MAXN; i++) f[i] = f[i - 1] * 2 % MOD;
    for (int i = 0; i < MAXN; i++) g[i + 1] = (2 * g[i] + f[i]) % MOD;
    for (int i = 0; i < MAXN; i++) h[i + 1] = (2 * h[i] + 2 * g[i] + f[i]) % MOD;

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
