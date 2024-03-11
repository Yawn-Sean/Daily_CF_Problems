#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (auto& wi : w) {
        cin >> wi;
    }
    vector<vector<pair<int, int>>> g(n, vector<pair<int,int>>());
    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    int64 ans = 0ll;
    function<int64(int,int,int)> dfs = [&] (int u, int p, int uc) -> int64 {
        int64 mx1 = 0ll, mx2 = 0ll;
        for (auto& [v, c] : g[u]) {
            if (v == p) continue;
            int64 gl = dfs(v, u, c);
            if (gl > mx1) {
                mx2 = mx1;
                mx1 = gl;
            } else if (gl > mx2) {
                mx2 = gl;
            }
        }
        ans = max(ans, mx1 + mx2 + w[u]);
        return mx1 + w[u] - uc;
    };

    dfs(0, -1, 0);
    cout << ans << endl;

    return 0;
}