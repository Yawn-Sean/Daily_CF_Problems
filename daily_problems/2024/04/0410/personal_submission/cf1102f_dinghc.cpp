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

        int ans = 0;
        map<int, pair<int, int>> cache;
        for (int v = 0; v < n; v++) {
            function<pair<int, int>(int,int)> dfs = [&] (int mask, int u) -> pair<int, int> {
                if (mask == (1 << n) - 1) {
                    return {INT_MAX, u};
                }

                int key = (u << 16) | mask;
                auto it = cache.find(key);
                if (it != cache.end()) return it->second;

                pair<int, int> res = {0, 0};
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) continue;
                    auto [mn_i, target] = dfs(mask | (1 << i), i);
                    res = max(res, {min(mn_i, mn1[i][u]), target});
                }
                return cache[key] = res;
            };
            auto [mn_v, target] = dfs(1 << v, v);
            ans = max(ans, min(mn_v, mn2[v][target]));
        }
        cout << ans << "\n";
    }

    return 0;
}

