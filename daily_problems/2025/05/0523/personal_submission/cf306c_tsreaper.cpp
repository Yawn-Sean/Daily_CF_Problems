#include <bits/stdc++.h>
#define MAXN 4000
#define MOD ((int) 1e9 + 9)
using namespace std;

int n, W, B;
long long ans;

long long fac[MAXN * 2 + 5], ifac[MAXN * 2 + 5];

long long C(int a, int b) {
    if (a < b) return 0;
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

int main() {
    scanf("%d%d%d", &n, &W, &B);

    fac[0] = 1;
    for (int i = 1; i <= W + B; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= W + B; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= W + B; i++) ifac[i] = ifac[i - 1] * ifac[i] % MOD;

    for (int i = 1; i < W; i++) {
        long long t = fac[W] * fac[B] % MOD;
        t = t * C(W + B - 3, n - 3) % MOD;
        ans = (ans + t) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
