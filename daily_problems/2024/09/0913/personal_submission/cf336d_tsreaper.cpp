#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, m, K;
long long ans;

long long fac[MAXN * 2 + 10], ifac[MAXN * 2 + 10];

long long C(int a, int b) {
    if (a < b) return 0;
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    if (m == 0) {
        if (n % 2 == K) printf("0\n");
        else printf("1\n");
        return 0;
    }

    fac[0] = 1;
    for (int i = 1; i <= n + m; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= n + m; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= n + m; i++) ifac[i] = ifac[i - 1] * ifac[i] % MOD;

    for (int i = 0; i <= n; i++) {
        int rem = n - i + m - 1;
        if (rem > 0) {
            if (i % 2 == K) ans = (ans + C(rem, m - 1)) % MOD;
        } else {
            if (i % 2 != K) ans = (ans + 1) % MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
