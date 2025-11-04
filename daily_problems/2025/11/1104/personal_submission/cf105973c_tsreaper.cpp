#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MOD 998244353
using namespace std;

long long fac[MAXN + 5], ifac[MAXN + 5], f[MAXN + 5];

long long C(int a, int b) {
    if (a < b) return 0;
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= MAXN; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= MAXN; i++) ifac[i] = ifac[i - 1] * ifac[i] % MOD;

    f[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        f[i] = f[i - 1] ^ 1;
        if (i % 2 == 0) f[i] ^= C(i, i / 2);
    }

    int tcase; scanf("%d", &tcase);
    while (tcase--) {
        int n; scanf("%d", &n);
        printf("%lld\n", f[n]);
    }
    return 0;
}
