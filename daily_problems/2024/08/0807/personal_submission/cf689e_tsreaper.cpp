#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, K;
long long ans;

long long fac[MAXN + 10], ifac[MAXN + 10];

long long C(int a, int b) {
    if (a < b) return 0;
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

int main() {
    scanf("%d%d", &n, &K);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= n; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= n; i++) ifac[i] = ifac[i] * ifac[i - 1] % MOD;

    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int l, r; scanf("%d%d", &l, &r);
        mp[l]++; mp[r + 1]--;
    }

    int now = 0;
    for (auto it = mp.begin(); next(it) != mp.end(); it++) {
        now += it->second;
        int len = next(it)->first - it->first;
        ans = (ans + len * C(now, K)) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
