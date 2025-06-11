#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, u, v;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n+1);
    vector<int> d(n+1), par(n+1, -1);
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
        d[u]++;
        d[v]++;
    }
    int mx = *max_element(d.begin(), d.end());
    vector<int> color(n);
    int root = 1;
    for (int i = 1; i <= n; ++i) {
        if (d[i] == mx) {
            root = i;
            break;
        }
    }
    par[root] = 0;
    function<void(int)> dfs;
    dfs = [&](int v) {
        int pc = 0, cur = 1;
        for (auto [u, idx] : adj[v]) {
            if (par[v] == u) {
                pc = color[idx];
                break;
            }
        }
        for (auto [u, idx] : adj[v]) {
            if (par[v] == u) {
                continue;
            }
            if (par[u] == -1) {
                par[u] = v;
                if (cur == pc) {
                    cur++;
                }
                color[idx] = cur;
                cur++;
                dfs(u);
            }
        }
    };
    dfs(root);
    vector<vector<int>> ans(mx+1);
    for (int i = 1; i < n; ++i) {
        ans[color[i]].emplace_back(i);
    }
    cout << mx << '\n';
    for (int i = 1; i <= mx; ++i) {
        cout << ans[i].size();
        for (int& x : ans[i]) {
            cout << ' ' << x;
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}