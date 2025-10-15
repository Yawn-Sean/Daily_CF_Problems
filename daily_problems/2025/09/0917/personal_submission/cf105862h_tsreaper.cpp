#include <bits/stdc++.h>
#define MOD ((int) 1e9 + 7)
using namespace std;

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

void solve() {
    int n; scanf("%d", &n);
    long long sm = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        sm += x;
    }
    sm %= MOD;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int g = gcd(i, n);
        g = n / g;
        ans = (ans + sm * g) % MOD;
    }
    printf("%lld\n", ans * power(1LL * n * n % MOD, MOD - 2) % MOD);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
