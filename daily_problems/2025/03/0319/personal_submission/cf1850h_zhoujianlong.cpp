#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAXN int(2e5 + 10)
#define MOD int(1e9 + 7)
#define rep(i, start, end) for (int i = start; i <= end; ++i)
#define erp(i, end, start) for (int i = end; i >= start; --i)

using i64 = long long;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

vector<bool> vis;
vector<i64> w;
vector<vector<pii>> g;

bool dfs(int x) {
    if (vis[x])
        return true;
    vis[x] = true;

    bool ok = true;
    for (auto [y, v] : g[x]) {
        i64 c_w = w[x] + v;
        if (w[y] == INT_MAX)
            w[y] = c_w;
        else if (w[y] != c_w)
            return false;
        ok &= dfs(y);
    }
    return ok;
};

void solve() {
    int n, m;
    cin >> n >> m;
    g = vector<vector<pii>>(n + 1);
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, -w});
    }

    vis = vector<bool>(n + 1, false);
    w = vector<i64>(n + 1, INT_MAX);

    rep(i, 1, n) {
        if (vis[i])
            continue;
        w[i] = 0;
        if (!dfs(i)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
