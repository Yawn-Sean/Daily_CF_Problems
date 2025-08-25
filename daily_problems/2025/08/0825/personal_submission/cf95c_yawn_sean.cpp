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

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    s --, t --;

    vector<vector<pair<int, int>>> path(n);
    
    while (m --) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        path[u].emplace_back(v, w);
        path[v].emplace_back(u, w);
    }

    long long inf = 1e14;
    vector<vector<long long>> dis(n, vector<long long>(n, inf));

    for (int i = 0; i < n; i ++) {
        dis[i][i] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        pq.push({0, i});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (dis[i][u] == d) {
                for (auto &[v, w]: path[u]) {
                    long long nd = d + w;
                    if (nd < dis[i][v]) {
                        dis[i][v] = nd;
                        pq.push({nd, v});
                    }
                }
            }
        }
    }

    vector<int> ts(n), cs(n);
    for (int i = 0; i < n; i ++)
        cin >> ts[i] >> cs[i];

    vector<long long> ans(n, inf);
    ans[s] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (u == t) return cout << d, 0;

        if (ans[u] == d) {
            for (int v = 0; v < n; v ++) {
                if (dis[u][v] <= ts[u]) {
                    long long nd = d + cs[u];
                    if (nd < ans[v]) {
                        ans[v] = nd;
                        pq.push({nd, v});
                    }
                }
            }
        }
    }

    cout << -1;

    return 0;
}