#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int MOD = 1e9+7;
constexpr int N = 3e5;
int64 fact[N + 1];

auto init = [] {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    return 0;
}();

int fast_pow(int64 a, int64 b) {
    int64 ans = 1LL;
    a %= MOD;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

int inv(int a) {
    return a == 1 ? a : fast_pow(a, MOD - 2);
}

int comb(int n, int k) {
    k = min(n - k, k);
    if (k == 0) return 1;
    return (fact[n] * inv(fact[k]) % MOD) * inv(fact[n - k]) % MOD;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0, r, c; i < k; i++) {
            scanf("%d%d", &r, &c);
            n -= 2 - (r == c);
        }
        int ans = 1;
        for (int i = 2; i <= n; i += 2) {
            int k = comb(n, i);
            int f = fast_pow(2, i / 2) * fact[i - 1] % MOD * inv(fact[i / 2 - 1] * fast_pow(2, i / 2 - 1) % MOD) % MOD;
            ans = (ans + 1LL * k * f % MOD) % MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}

