#include <bits/stdc++.h>
#define MAXN 2000
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, A[MAXN + 10];
long long ans;

bool used[MAXN + 10];
long long fac[MAXN + 10], ifac[MAXN + 10];

long long C(int a, int b) {
    if (a < b) return 0;
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= n; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= n; i++) ifac[i] = ifac[i - 1] * ifac[i] % MOD;

    for (int i = 1; i <= n; i++) if (A[i] != -1) used[A[i]] = true;
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) if (A[i] == -1) {
        x++;
        if (!used[i]) y++;
    }

    ans = fac[x];
    for (int i = 1; i <= y; i++) {
        long long t = C(y, i) * fac[x - i] % MOD;
        ans = (ans + t * (i & 1 ? -1 : 1) % MOD + MOD) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
