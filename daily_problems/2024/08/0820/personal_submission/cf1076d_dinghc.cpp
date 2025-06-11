#include <bits/stdc++.h>

using namespace std;
constexpr long long INF = 1e18;
constexpr int N = 300'000;
vector<array<int, 3>> g[N];
long long d[N];
int last[N];

vector<int> dijkstra(int n, int k, int s) {
    if (k == 0) return {};
    k = min(k, n - 1);
    vector<int> ans(k);
    int ai = 0;
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        last[i] = -1;
    }
    d[s] = 0LL;
    set<pair<long long, int>> q;
    q.emplace(0LL, s);
    while (!q.empty()) {
        auto [du, u] = *q.begin(); q.erase(q.begin());
        if (last[u] >= 0) {
            ans[ai++] = last[u];
            if (ai == k) break;
        }
        for (auto& [v, wv, i] : g[u]) {
            if (d[v] > du + wv) {
                auto it = q.lower_bound(make_pair(d[v], v));
                if (it != q.end()) q.erase(it);
                d[v] = du + wv;
                last[v] = i;
                q.emplace(d[v], v);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0, x, y, w; i < m; i++) {
        cin >> x >> y >> w;
        x--, y--;
        g[x].push_back(array<int, 3>{y, w, i});
        g[y].push_back(array<int, 3>{x, w, i});
    }
    vector<int> ans = dijkstra(n, k, 0);
    cout << ans.size() << "\n";
    for (auto& v : ans) {
        cout << v + 1 << " ";
    }
    cout << "\n";
    return 0;
}

