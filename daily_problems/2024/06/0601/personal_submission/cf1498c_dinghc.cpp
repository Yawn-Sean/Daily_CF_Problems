#include <bits/stdc++.h>

using namespace std;
constexpr int MOD = 1'000'000'007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> dp[2];
        dp[0] = vector<vector<int>>(n + 1, vector<int>(k + 1, 0));
        dp[1] = vector<vector<int>>(n + 1, vector<int>(k + 1, 0));
        function<int(int, int, int)> dfs = [&] (int m, int t, int d) -> int {
            if (t == 1) return 1;
            if (m > n) return 1;
            if (m < 1) return 1;
            int idx = (d >> 1) & 1;
            if (dp[idx][m][t] == 0) {
                dp[idx][m][t] = (dfs(m + d, t, d) + dfs(m - d, t - 1, -d)) % MOD;
            }
            return dp[idx][m][t];
        };
        cout << dfs(1, k, 1) << "\n";
    }
    return 0;
}

