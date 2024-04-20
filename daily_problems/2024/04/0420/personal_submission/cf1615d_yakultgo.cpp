#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    vector<pair<int, int>> X[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        if (w == -1) continue;
        w = __builtin_popcount(w) & 1;
        X[u].push_back({v, w});
        X[v].push_back({u, w});
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        X[u].push_back({v, w});
        X[v].push_back({u, w});
    }
    bool flag = false;
    vector<int> vis(n + 1, 0), sta(n + 1, 0);
    function<void(int, int)> f1 = [&](int u, int val) -> void {
        vis[u] = 1;
        sta[u] = val;
        for (auto [v, w] : X[u]) {
            if (vis[v] && w ^ val != sta[v])
                flag = true;
            if (!vis[v])
                f1(v, val ^ w);
        }
    };
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        f1(i, 0);
    }
    if (flag) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> ans(n + 1, 0);
    function<void(int, int)> dfs = [&](int u, int fa) -> void {
        for (auto [v, w] : g[u]) {
            if (v == fa) continue;
            ans[v] = (w == -1 ? sta[u] ^ sta[v] : w);
            cout << u << " " << v << " " << ans[v] << endl;
            dfs(v, u);
        }
    };
    dfs(1, 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}