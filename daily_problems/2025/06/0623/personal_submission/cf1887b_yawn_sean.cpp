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

    int n, t; 
    cin >> n >> t;

    vector<vector<pair<int, int>>> path(n);

    for (int i = 1; i <= t; i ++) {
        int m;
        cin >> m;
        
        while (m --) {
            int u, v;
            cin >> u >> v;
            u --, v --;
            path[u].emplace_back(i, v);
            path[v].emplace_back(i, u);
        }
    }

    int k;
    cin >> k;

    vector<vector<int>> pos(t + 1);
    for (int i = 1; i <= k; i ++) {
        int x;
        cin >> x;
        pos[x].emplace_back(i);
    }

    vector<int> dis(n, k + 1);
    dis[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (dis[u] == d) {
            for (auto [e_id, v]: path[u]) {
                auto pt = lower_bound(pos[e_id].begin(), pos[e_id].end(), d + 1);
                if (pt != pos[e_id].end()) {
                    int nd = *pt;
                    if (nd < dis[v]) {
                        dis[v] = nd;
                        pq.push({nd, v});
                    }
                }
            }
        }
    }

    cout << (dis.back() <= k ? dis.back() : -1);

    return 0;
}