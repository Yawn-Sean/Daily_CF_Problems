#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> nodes(k);
        for (auto &x: nodes) cin >> x;

        vector<vector<int>> path(n + 1);
        while (m --) {
            int u, v;
            cin >> u >> v;
            path[u].emplace_back(v);
            path[v].emplace_back(u);
        }

        int cur = 1;
        for (auto &x: nodes) {
            if (cur != x) {
                path[cur].emplace_back(x);
                path[x].emplace_back(cur);
                cur = x;
            }
        }

        vector<int> dis(n + 1, -1);
        dis[1] = 0;

        queue<int> que;
        que.push(1);

        while (!que.empty()) {
            auto u = que.front(); que.pop();
            for (auto &v: path[u]) {
                if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    que.push(v);
                }
            }
        }

        bool flg = true;
        for (int i = 1; i < k; i ++) {
            if (dis[nodes[i]] <= dis[nodes[i - 1]]) {
                flg = false;
            }
        }

        if (flg) {
            cout << (nodes[0] == 1 ? k - 1 : k) << '\n';
            cur = 1;
            for (auto &x: nodes) {
                if (cur != x) {
                    cout << cur << ' ' << x << '\n';
                    cur = x;
                }
            }
        }
        else cout << "-1\n";
    }

    return 0;
}