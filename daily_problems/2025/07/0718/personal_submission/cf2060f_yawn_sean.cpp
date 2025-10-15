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

    int K = 1e5, mod = 998244353;

    vector<vector<int>> dp(17, vector<int>(K + 1, 0));
    dp[0][1] = 1;

    auto add = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };

    for (int i = 0; i < 16; i ++) {
        for (int j = 1; j <= K; j ++) {
            for (int v = 2 * j; v <= K; v += j) {
                add(dp[i + 1][v], dp[i][j]);
            }
        }
    }

    vector<int> inv(20);
    inv[0] = 1;
    for (int i = 1; i < 20; i ++)
        inv[i] = 1ll * i * inv[i - 1] % mod;
    
    for (int i = 1; i < 20; i ++)
        inv[i] = quickPow(inv[i], mod - 2, mod);
    
    int t;
    cin >> t;

    while (t --) {
        int k, n;
        cin >> k >> n;

        cout << n << ' ';

        for (int i = 2; i <= k; i ++) {
            int cur = 1, ans = 0;
            for (int j = 0; j < 17; j ++) {
                cur = 1ll * cur * (n + 1 - j) % mod;
                add(ans, 1ll * dp[j][i] * cur % mod * inv[j + 1] % mod);
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }

    return 0;
}