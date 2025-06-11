#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXA ((int) 2e5)
#define MOD 998244353
using namespace std;

int n, m;
long long ans;

int cnt[MAXA + 10];
long long tree[MAXA + 10];
long long fac[MAXN + 10], ifac[MAXN + 10];

int lb(int x) { return x & (-x); }

void add(int pos, long long val) {
    val = (val % MOD + MOD) % MOD;
    for (; pos <= MAXA; pos += lb(pos)) tree[pos] = (tree[pos] + val) % MOD;
}

long long query(int pos) {
    long long ret = 0;
    for (; pos; pos -= lb(pos)) ret = (ret + tree[pos]) % MOD;
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= n; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= n; i++) ifac[i] = ifac[i - 1] * ifac[i] % MOD;

    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    long long base = 1;
    for (int i = 1; i <= MAXA; i++) if (cnt[i] > 0) {
        base = base * ifac[cnt[i]] % MOD;
        add(i, fac[cnt[i]] * ifac[cnt[i] - 1]);
    }

    for (int i = 1; i <= m && i <= n; i++) {
        int x; scanf("%d", &x);
        ans = (ans + query(x - 1) * base % MOD * fac[n - i]) % MOD;
        if (cnt[x] == 0) { printf("%lld\n", ans); return 0; }

        base = base * fac[cnt[x]] % MOD;
        add(x, -fac[cnt[x]] * ifac[cnt[x] - 1]);

        cnt[x]--;
        if (cnt[x] > 0) {
            base = base * ifac[cnt[x]] % MOD;
            add(x, fac[cnt[x]] * ifac[cnt[x] - 1]);
        }
    }
    if (n < m) ans = (ans + 1) % MOD;
    printf("%lld\n", ans);
    return 0;
}
