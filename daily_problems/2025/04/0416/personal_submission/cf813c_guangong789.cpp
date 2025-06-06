#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> time1(n+1, 0), time2(n+1, 0);
    auto dfs = [&](this auto&& self, int cur, int fa, int cnt, vector<int>& time) -> void {
        for (int node : adj[cur]) {
            if (node != fa) {
                self(node, cur, cnt+1, time);
            }
        }
        time[cur] = cnt;
    };
    dfs(1, 0, 0, time1);
    dfs(x, 0, 0, time2);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (time1[i] > time2[i]) {
            ans = max(ans, 2 * time1[i]);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
