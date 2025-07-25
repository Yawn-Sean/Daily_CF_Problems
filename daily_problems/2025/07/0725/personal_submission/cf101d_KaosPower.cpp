#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        path[u].emplace_back(v, w);
        path[v].emplace_back(u, w);
    }

    vector<int> sz(n, 1), szt(n, 0), weight(n);
    vector<long long> dp(n, 0);

    auto dfs = [&] (auto &self, int u, int p) -> void {
        vector<int> sons;
        for (auto &[v, w]: path[u]) {
            if (v != p) {
                sons.emplace_back(v);

                self(self, v, u);

                sz[u] += sz[v];
                szt[u] += w + szt[v];
                dp[u] += dp[v] + sz[v] * w;

                weight[v] = szt[v] + w;
            }
        }

        sort(sons.begin(), sons.end(), [&] (int i, int j) {
            return 1ll * weight[i] * sz[j] < 1ll * weight[j] * sz[i];
        });

        int total_sz = sz[u] - 1;

        for (auto &v: sons) {
            total_sz -= sz[v];
            dp[u] += 2ll * weight[v] * total_sz;
        }
    };

    dfs(dfs, 0, -1);

    cout << fixed << setprecision(15) << (long double)1 * dp[0] / (n - 1);

    return 0;
}
