#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, K;
long long ans;

long long fac[MAXN + 5], ifac[MAXN + 5];

long long C(int a, int b) {
    if (a < b) return 0;
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

void solve() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= K; i++) {
        int x, y; scanf("%d%d", &x, &y);
        if (x == y) n--;
        else n -= 2;
    }

    ans = 0;
    for (int i = n & 1; i <= n; i += 2)
        ans = (ans + C(n, i) * C(n - i, (n - i) / 2) % MOD * fac[(n - i) / 2]) % MOD;
    printf("%lld\n", ans);
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= MAXN; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= MAXN; i++) ifac[i] = ifac[i - 1] * ifac[i] % MOD;

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
