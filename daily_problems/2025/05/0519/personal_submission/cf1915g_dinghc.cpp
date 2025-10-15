#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int64 INF = 1e15;
constexpr int A = 1000;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> g(n);
        vector<vector<int>> ws(n, vector<int>(n, -1));
        for (int i = 0, u, v, w; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            u--;
            v--;
            if (ws[u][v] == -1) {
                g[u].push_back(v);
                g[v].push_back(u);
                ws[u][v] = ws[v][u] = w;
            } else if (w < ws[u][v]) {
                ws[u][v] = ws[v][u] = w;
            }
        }
        vector<int> s(n);
        for (auto& x : s) {
            scanf("%d", &x);
        }
        vector<vector<int64>> dist(n, vector<int64>(A + 1, INF));
        dist[0][s[0]] = 0;
        priority_queue<tuple<int64, int, int>, vector<tuple<int64, int, int>>, greater<tuple<int64, int, int>>> q;
        q.emplace(0, 0, s[0]);
        while (!q.empty()) {
            auto [w, u, f] = q.top(); q.pop();
            if (w != dist[u][f]) continue;
            for (auto& v : g[u]) {
                int nf = min(f, s[v]);
                int64 nw = w + 1LL * ws[u][v] * f;
                if (nw < dist[v][nf]) {
                    dist[v][nf] = nw;
                    q.emplace(nw, v, nf);
                }
            }
        }
        int64 ans = INF;
        for (int f = 1; f <= A; f++) {
            ans = min(ans, dist[n - 1][f]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

