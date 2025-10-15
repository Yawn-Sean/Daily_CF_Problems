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

    int n, l;
    cin >> n >> l;

    vector<int> pos = {0, l};
    vector<array<int, 3>> edges(n);

    for (int i = 0; i < n; i ++) {
        int x, d, t, p;
        cin >> x >> d >> t >> p;
        edges[i] = {x - p, x + d, p + t};
        if (x >= p) pos.emplace_back(x - p), pos.emplace_back(x + d);
    }

    sort(pos.begin(), pos.end());

    int N = unique(pos.begin(), pos.end()) - pos.begin();

    vector<vector<array<int, 3>>> path(N);
    for (int i = 1; i < N; i ++) {
        int d = pos[i] - pos[i - 1];
        path[i].push_back({0, i - 1, d});
        path[i - 1].push_back({0, i, d});
    }

    for (int i = 0; i < n; i ++) {
        auto [u, v, d] = edges[i];
        if (u < 0) continue;
        int pu = lower_bound(pos.begin(), pos.begin() + N - 1, u) - pos.begin();
        int pv = lower_bound(pos.begin(), pos.begin() + N - 1, v) - pos.begin();
        path[pu].push_back({i + 1, pv, d});
    }

    int inf = 2e9;

    vector<int> dis(N, inf);
    vector<pair<int, int>> pre(N);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[0] = 0;
    pq.push({0, 0});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dis[u] == d) {
            for (auto &[eid, v, nd]: path[u]) {
                if (dis[v] > d + nd) {
                    dis[v] = d + nd;
                    pre[v] = {eid, u};
                    pq.push({dis[v], v});
                }
            }
        }
    }

    for (int i = 0; i < N; i ++) {
        if (pos[i] - pos[0] == l) {
            cout << dis[i] << '\n';

            int cur = i;
            vector<int> ans;

            while (cur) {
                auto [eid, ncur] = pre[cur];
                cur = ncur;
                if (eid) ans.emplace_back(eid);
            }
            
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            for (auto &v: ans) cout << v << ' ';

            break;
        }
    }

    return 0;
}