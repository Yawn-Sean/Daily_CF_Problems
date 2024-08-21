#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL
#include "C:\Program Files\DEBUG\debug.h"
#else
#define debug(...) 114514
#define ps 114514
#endif

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> in(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    vector<int> a(n + 1, 1e9);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    auto dfs = [&](auto self, int u, int fa) -> void {
       // debug(u);
        for (auto v : adj[u]) {
            self(self, v, u);
        }
        if (a[u] == u) {
            ans.push_back(u);
        } else if (a[u] != a[fa]) {
            cout << -1 << endl;
            exit(0);
        }
    };
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            dfs(dfs, i, 0);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}
