#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

long long fac[MAXN + 5], ifac[MAXN + 5];

long long C(int a, int b) {
    if (a < b) return 0;
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

void solve() {
    int n, m; scanf("%d%d", &m, &n);
    if (n == 1) { printf("1\n"); return; }
    if (m > n / 2) { printf("0\n"); return; }

    long long ans = (C(n - m - 1, m - 1) + C(n - m, m)) % MOD;
    ans = ans * fac[m] % MOD;
    printf("%lld\n", ans);
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= MAXN; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= MAXN; i++) ifac[i] = ifac[i] * ifac[i - 1] % MOD;

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
