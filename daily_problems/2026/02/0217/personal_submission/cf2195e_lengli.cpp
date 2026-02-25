#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> path(n + 1);
        path[0].push_back(1);

        for (int i = 1; i <= n; i++) {
            int u, v;
            cin >> u >> v;
            if (u && v) {
                path[i].push_back(u);
                path[i].push_back(v);
            }
        }

        vector<int> que;
        que.reserve(n + 1);
        que.push_back(0);

        vector<int> parent(n + 1, -1);

        for (int i = 0; i < (int)que.size(); i++) {
            int u = que[i];
            for (int v : path[u]) {
                parent[v] = u;
                que.push_back(v);
            }
        }

        vector<ll> sz(n + 1, 0);


        for (int i = (int)que.size() - 1; i >= 0; i--) {
            int node = que[i];
            if (!path[node].empty() && node > 0) {
                int u = path[node][0];
                int v = path[node][1];
                sz[node] = (sz[u] + 2 + sz[v] + 2) % mod;
            }
        }

        for (int node : que) {
            for (int child : path[node]) {
                sz[child] += sz[node] + 1;
                sz[child] %= mod;
            }
        }

        // 输出 1..n
        for (int i = 1; i <= n; i++) {
            cout << sz[i] << (i < n ? ' ' : '\n');
        }
    }

    return 0;
}
