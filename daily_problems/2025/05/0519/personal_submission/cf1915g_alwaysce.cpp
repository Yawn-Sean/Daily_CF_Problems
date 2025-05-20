#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
using i64 = long long;

i64 inf = 1e16;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> path(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            path[u].emplace_back(v, w);
            path[v].emplace_back(u, w);
        }

        vector<int> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        vector<vector<i64>> dist(n, vector<i64>(n, inf));
        dist[0][0] = 0;

        priority_queue<tuple<i64, int,int>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [d, u, b] = pq.top();
            pq.pop();
            d = -d;

            if (d > dist[u][b]) {
                continue;
            }
            for (auto& pr: path[u]) {
                int v = pr.first, w = pr.second;
                i64 nd = d + 1ll * w * s[b];
                int nb = (s[v] < s[b] ? v : b);
                if (nd < dist[v][nb]) {
                    dist[v][nb] = nd;
                    pq.emplace(-nd, v, nb);
                }
            }
        }

        i64 ans = inf;
        for (int b = 0; b < n; b++) {
            if (dist[n - 1][b] < ans) {
                ans = dist[n - 1][b];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
