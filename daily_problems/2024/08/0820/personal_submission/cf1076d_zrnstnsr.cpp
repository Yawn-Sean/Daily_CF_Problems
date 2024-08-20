#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> G(n+1);
    map<pair<int, int>, int> E;
    vector<int> fa(n+1), in(n+1), ans(m);
    vector<ll> d(n+1, linf);
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        if (u > v) swap(u, v);
        G[u].push_back({v, w}); G[v].push_back({u, w});
        E[{u, v}] = i;
    }
    m = E.size();
    priority_queue<pair<int, int>> q;
    q.push({0, 1}); d[1] = 0;
    while (!q.empty()) {
        auto [D, u] = q.top(); q.pop();
        if (-D > d[u]) continue;
        for (auto [v, w]: G[u]) if (d[v] > d[u] + w) {
            fa[v] = u;
            d[v] = d[u] + w;
            q.push({-d[v], v});
        }
    }
    for (auto p = E.begin(); p != E.end(); ) {
        auto [u, v] = p->first;
        if (fa[u] != v && fa[v] != u) p = E.erase(p);
        else ++p;
    }
    for (int i = 2; i <= n; ++i) ++in[fa[i]];
    queue<int> t;
    for (int i = 2; i <= n; ++i) if (!in[i]) t.push(i);
    while (E.size() > k) {
        auto u = t.front(); t.pop();
        E.erase({min(u,fa[u]),max(u,fa[u])});
        if (!--in[fa[u]]) t.push(fa[u]);
    }
    cout << E.size() << '\n';
    for (auto& [_, ans]: E) cout << ans << ' ';
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
