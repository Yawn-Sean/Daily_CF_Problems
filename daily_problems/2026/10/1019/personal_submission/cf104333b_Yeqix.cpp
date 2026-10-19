#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int md = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<i64> a(n), b(n);
    for (auto& x : a) {
        cin >> x;
    }
    for (auto& x : b) {
        cin >> x;
    }

    i64 ans = 0;
    for (int i = 0; i < 30; i++) {
        vector<vector<int>> f(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                f[j][k] = (a[j] + b[k]) >> i & 1;
            }
        }
        vector<vector<i64>> dp(2, vector<i64>(1 << n));
        dp[0][0] = 1LL << i;
        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = __builtin_popcount(mask);
            for (int j = 0; j < n; j++) {
                if (mask >> j & 1) {
                    continue;
                }
                for (int k = 0; k < 2; k++) {
                    int nxt = k ^ f[cnt][j], g = mask | (1 << j);
                    dp[nxt][g] = (dp[nxt][g] + dp[k][mask]) % md;
                }
            }
        }
        ans = (ans + dp[1].back()) % md;
    }

    cout << ans;
    return 0;
}