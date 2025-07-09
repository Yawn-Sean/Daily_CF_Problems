#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
#define MAXC ((int) 2e5)
#define MOD ((int) 1e6 + 3)
using namespace std;

long long fac[MAXN + MAXC + 5], ifac[MAXN + MAXC + 5];

long long C(int a, int b) {
    if (a < b) return 0;
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

int main() {
    int n, K; scanf("%d%d", &n, &K);

    fac[0] = 1;
    for (int i = 1; i <= n + K; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= n + K; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= n + K; i++) ifac[i] = ifac[i - 1] * ifac[i] % MOD;

    long long ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + C(i + K - 1, K - 1)) % MOD;
    printf("%lld\n", ans);
    return 0;
}