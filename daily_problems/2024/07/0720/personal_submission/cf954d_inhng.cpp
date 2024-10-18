#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, m, s, t, ans = 0;
    cin >> n >> m >> s >> t;
    queue<int> q;
    vector<int> g[n + 1], dist_s(n + 1, -1), dist_t(n + 1, -1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    q.emplace(s);
    dist_s[s] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist_s[v] != -1) {
                continue;
            }
            dist_s[v] = dist_s[u] + 1;
            q.emplace(v);
        }
    }
    q.emplace(t);
    dist_t[t] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist_t[v] != -1) {
                continue;
            }
            dist_t[v] = dist_t[u] + 1;
            q.emplace(v);
        }
    }
    for (int u = 1; u <= n; ++u) {
        for (int v = u + 1; v <= n; ++v) {
            ans += (min(dist_s[u] + dist_t[v], dist_s[v] + dist_t[u]) + 1 >= dist_s[t]);
        }
    }
    cout << ans - m << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
