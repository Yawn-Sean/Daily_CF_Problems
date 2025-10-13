#include  <bits/stdc++.h>
#define MAXN ((int) 5e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, L, R, A[MAXN + 5];
long long ans;

long long P[MAXN + 5], fac[MAXN + 5], ifac[MAXN + 5];

long long C(int a, int b) {
    if (a < b) return 0;
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

void calc(int l, int r) {
    long long x = 0, y = 0;
    for (int i = 0; i <= r; i++) {
        if (i < l) x = (x + C(0, i)) % MOD;
        y = (y + C(0, i)) % MOD;
    }
    for (int i = n; i > 0; i--) {
        ans = (ans + A[i] * (y - x + MOD) % MOD * P[i - 1]) % MOD;
        if (l - 1 >= 0) x = (2 * x - C(n - i, l - 1) + MOD) % MOD;
        y = (2 * y - C(n - i, r) + MOD) % MOD;
    }
}

int main() {
    scanf("%d%d%d", &n, &L, &R);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 2 % MOD;
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= n; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= n; i++) ifac[i] = ifac[i - 1] * ifac[i] % MOD;

    calc(L - 1, R - 1);
    calc(n - R, n - L);
    printf("%lld\n", ans);
    return 0;
}
