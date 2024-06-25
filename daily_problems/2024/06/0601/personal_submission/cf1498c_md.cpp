// 0601
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    std::cin >> n >> k;
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 1; i <= k; ++i) {
        dp[i][0] = 1;
    }

    // dp[i][j] = dp[i][j-1] + dp[i-1][n-j]
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][n - j]) % MOD;
        }
    }

    cout << dp[k][n] << '\n';   
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}