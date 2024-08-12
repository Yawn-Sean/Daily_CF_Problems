#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
#define endl '\n'

const int inf = 0x3f3f3f3f;

void solve() { 
    int n, m, s, t; cin >> n >> m >> s >> t;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int> ds, dt;
    function<void(int, vector<int> &)> bfs = [&](int root, vector<int> &dist) {
        dist.resize(n + 1, inf);
        queue<int> q;
        q.emplace(root);
        dist[root] = 0;
        while (q.size()) {
            auto cur = q.front(); q.pop();
            for (auto &x : g[cur]) {
                if (dist[cur] + 1 < dist[x]) {
                    dist[x] = dist[cur] + 1;
                    q.emplace(x);
                }
            }
        }
        return;
    };
    bfs(s, ds);
    bfs(t, dt);
    int distance = ds[t], ans = 0;
    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            int a = ds[u] + dt[v] + 1;
            int b = ds[v] + dt[u] + 1;
            if (min(a, b) >= distance) ans += 1;
        }
    }
    cout << ans - m << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
