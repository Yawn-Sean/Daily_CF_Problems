#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;
i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> p(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> p[i];
        }

        vector<vector<int>> path(n);
        for (int i = 0; i < n - 1; i++) {
            path[p[i] - 1].push_back(i + 1);
        }

        vector<int> order;
        vector<int> vis(n);        
        vector<int> sz(n);

        int time = 1;
        function<int(int)> dfs = [&](int u) {
            vis[u] = time++;
            sz[u] = 1;
            order.push_back(u);
            for (int v : path[u]) {
                if (!vis[v]) {
                    sz[u] += dfs(v);
                }
            }
            return sz[u];
        };

        dfs(0);

        while (q--) {
            int u, k;
            cin >> u >> k;
            --u;

            if (k > sz[u]) {
                cout << -1 << "\n";
            } else {
                cout << order[vis[u] + k - 2] + 1 << endl;
            }
        }
    }

    return 0;
}
