#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    if (n == 1) {
        int ans = INT_MAX;
        for (int u = 0; u < m - 1; u++) {
            ans = min(ans, abs(a[0][u] - a[0][u + 1]));
        }
        cout << ans << "\n";
    } else {
        vector<vector<int>> mn1(n, vector<int>(n, INT_MAX));
        vector<vector<int>> mn2(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = 0; k < m - 1; k++) {
                    mn1[j][i] = mn1[i][j] = min(mn1[i][j], abs(a[i][k] - a[j][k]));
                    mn2[i][j] = min(mn2[i][j], abs(a[i][k + 1] - a[j][k]));
                    mn2[j][i] = min(mn2[j][i], abs(a[i][k] - a[j][k + 1]));
                }
                mn1[j][i] = mn1[i][j] = min(mn1[i][j], abs(a[i][m - 1] - a[j][m - 1]));
            }
        }

        int m = 1 << n;
        vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n));
        for (int i = 0; i < n; i++) {
            dp[m - 1][i] = pair<int, int>{INT_MAX, i};
        }
        for (int msk = m - 2; msk > 0; msk--) {
            for (int u = 0; u < n; u++) {
                pair<int, int> res = {0, 0};
                for (int i = 0; i < n; i++) {
                    if (msk & (1 << i)) continue;
                    auto [mn_i, target] = dp[msk | (1 << i)][i];
                    res = max(res, {min(mn_i, mn1[u][i]), target});
                }
                dp[msk][u] = res;
            }
        }
        int ans = 0;
        for (int v = 0; v < n; v++) {
            auto [mn_v, target] = dp[1 << v][v];
            ans = max(ans, min(mn_v, mn2[v][target]));
        }
        cout << ans << "\n";
    }

    return 0;
}

