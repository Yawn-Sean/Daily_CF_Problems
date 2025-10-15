#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> path(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            path[u].push_back(v);
            path[v].push_back(u);
        }

        i64 ans = 1ll * n * (n - 1) / 2;
        int timer = 0;
        vector<int> dfn(n, -1), low(n, -1), vis(n, 0);
        vector<int> sub(n, 0);
        function<void(int,int)> dfs = [&](int u, int p) {
            vis[u] = 1;
            dfn[u] = low[u] = timer++;
            sub[u] = 1;

            for (auto& v : path[u]) {
                if (v == p) continue;

                if (vis[v]) {
                    low[u] = min(low[u], dfn[v]);
                } else {
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                    sub[u] += sub[v];

                    if (low[v] > dfn[u]) {
                        i64 s1 = sub[v];
                        i64 s2 = n - sub[v];
                        i64 cur = s1 * (s1 - 1) / 2 + s2 * (s2 - 1) / 2;
                        ans = min(ans, cur);
                    }
                }
            }
        };

        dfs(0, -1);
        cout << ans << endl;
    }
    
    return 0;
}
