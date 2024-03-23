#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXK ((int) 2e5)
#define MOD 998244353
using namespace std;

int n, K, sa[MAXN + 10];

int rnk[MAXN + 10];
long long fac[MAXN + MAXK + 10], ifac[MAXN + MAXK + 10];

long long C(int a, int b) {
    if (a < b) return 0;
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

int main() {
    scanf("%d%d", &n, &K);
    fac[0] = 1;
    for (int i = 1; i <= n + K; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= n + K; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= n + K; i++) ifac[i] = ifac[i] * ifac[i - 1] % MOD;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &sa[i]);
        sa[i]++; rnk[sa[i]] = i;
    }

    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int x = sa[i] + 1, y = sa[i + 1] + 1;
        if (rnk[x] < rnk[y]) cnt++;
    }
    printf("%lld\n", C(K + cnt, n));
    return 0;
}
