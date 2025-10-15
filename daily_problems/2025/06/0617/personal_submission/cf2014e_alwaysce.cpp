#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;
i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> horse(n);
        for (int i = 0; i < h; i++) {
            int x;
            cin >> x;
            --x;
            horse[x] = 1;
        }

        vector<vector<pair<int,int> >> path(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            path[u].push_back({v, w});
            path[v].push_back({u, w});
        }


        auto dij = [&](int start) {
            vector<i64> dis(2 * n, 1e18);
            dis[start] = 0;
            priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;

            pq.push({0, start});
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > dis[u]) continue;

                bool has_horse = false;
                if (u >= n) {
                    u -= n;
                    has_horse = true;
                } else if (horse[u]) {
                    has_horse = true;
                }

                for (auto& [v, w]: path[u]) {
                    int new_v;
                    i64 new_d;
                    if (has_horse) {
                        new_v = v + n;
                        new_d = d + w / 2;
                    } else {
                        new_v = v;
                        new_d = d + w;
                    }
                    if (new_d < dis[new_v]) {
                        dis[new_v] = new_d;
                        pq.push({dis[new_v], new_v});
                    }
                }
            }
            return dis;
        };

        vector<i64> d1 = dij(0);
        vector<i64> d2 = dij(n - 1);

        i64 ans = inf;
        for (int i = 0; i < n; i++) {
            ans = min(ans, max(min(d1[i], d1[i + n]), min(d2[i], d2[i + n])) );
        }
        cout << (ans == inf ? -1 : ans) << '\n';
    }
    return 0;
}
