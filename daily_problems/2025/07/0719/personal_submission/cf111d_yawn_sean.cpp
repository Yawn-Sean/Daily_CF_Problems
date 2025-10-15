#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, mod = 1e9 + 7;
    cin >> n >> m >> k;

    int M = 1e6 + 1;
    vector<int> fac(M), fac_inv(M);

    fac[0] = 1;
    for (int i = 1; i < M; i ++) fac[i] = 1ll * i * fac[i - 1] % mod;
    fac_inv[M - 1] = quickPow(fac[M - 1], mod - 2, mod);
    for (int i = M - 1; i > 0; i --) fac_inv[i - 1] = 1ll * i * fac_inv[i] % mod;

    auto comb = [&] (int x, int y) -> int {
        if (x < 0 || y < 0 || y > x) return 0;
        return 1ll * fac[x] * fac_inv[y] % mod * fac_inv[x - y] % mod;
    };

    auto add = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };

    if (m == 1) return cout << quickPow(k, n, mod), 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i ++) {
        for (int j = i; j > 0; j --) {
            dp[j] = (1ll * j * dp[j] + dp[j - 1]) % mod;
        }
        dp[0] = 0;
    }

    for (int i = 0; i <= n; i ++)
        dp[i] = 1ll * dp[i] * fac[i] % mod;
    
    int ans = 0;
    for (int i = 0; i <= n; i ++) {
        int val = quickPow(i, n * (m - 2), mod);
        for (int j = i; j <= n; j ++) {
            add(ans, 1ll * comb(k, i) % mod * comb(k - i, 2 * (j - i)) % mod * comb(2 * (j - i), j - i) % mod * dp[j] % mod * dp[j] % mod * val % mod);
        }
    }

    cout << ans;

    return 0;
}