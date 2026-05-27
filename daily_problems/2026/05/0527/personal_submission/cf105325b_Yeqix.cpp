#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> edge(n);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }

    vector<vector<int>> dp(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] >= inf) {
                continue;
            }
            for (const auto& [v, w] : edge[j]) {
                dp[i - 1][v] = min(dp[i - 1][v], dp[i][j] + w * i);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (dp[0][i] >= inf) {
            cout << "-1 ";
        } else {
            cout << dp[0][i] << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}