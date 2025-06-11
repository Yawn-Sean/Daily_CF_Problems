#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
struct EDCC {
    vector<vector<int>> g, ng;
    vector<int> dfn, low, dcc, din;
    vector<pair<int, int>> bridges;
    stack<int> stk;
    int tot, cnt, n;
    EDCC(int n) {
        this->n = n;
        g.resize(n + 1);
        ng.resize(n + 1);
        dfn.resize(n + 1);
        low.resize(n + 1);
        dcc.resize(n + 1);
        din.resize(n + 1);
        tot = cnt = 0;
    }
    void add_edge(int x, int y) {
        g[x].push_back(y);
        g[y].push_back(x);
    }
    void work() {
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(i, 0);
        for (int x = 1; x <= n; x++) {
            for (int y : g[x]) {
                if (dcc[x] == dcc[y]) continue;
                din[dcc[x]]++;
                ng[dcc[x]].push_back(dcc[y]);
            }
        }
    }
    void tarjan(int x, int fa) {
        bool vis = false;
        dfn[x] = low[x] = ++tot;
        stk.push(x);
        for (int y : g[x]) {
            if (y == fa) {
                if (!vis) {
                    vis = true;
                    continue;
                }
            }
            if (!dfn[y]) {
                tarjan(y, x);
                low[x] = min(low[x], low[y]);
                if (low[y] > dfn[x]) {
                    bridges.push_back({x, y});
                }
            } else {
                low[x] = min(low[x], dfn[y]);
            }
        }
        if (dfn[x] == low[x]) {
            ++cnt;
            while (true) {
                int y = stk.top();
                stk.pop();
                dcc[y] = cnt;
                if (y == x) break;
            }
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    EDCC edcc(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edcc.add_edge(x, y);
    }
    edcc.work();
    vector<int> sz(edcc.cnt + 1);
    for (int i = 1; i <= n; i++) sz[edcc.dcc[i]]++;
    int mod = 1e9 + 7;
    vector<int> mi(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        mi[i] = mi[i - 1] * 2 % mod;
    }
    vector<int> dp(edcc.cnt + 1), dep(edcc.cnt + 1);
    vector<vector<int>> pa(edcc.cnt + 1, vector<int>(20));
    function<void(int, int)> dfs = [&](int u, int fa) -> void {
        dp[u] = dp[fa];
        dep[u] = dep[fa] + 1;
        pa[u][0] = fa;
        for (int i = 1; i < 20; i++) {
            pa[u][i] = pa[pa[u][i - 1]][i - 1];
        }
        if (sz[u] > 1) dp[u]++;
        for (int v : edcc.ng[u]) {
            if (v == fa) continue;
            dfs(v, u);
        }
    };
    dfs(1, 0);
    auto lca = [&](int x, int y) -> int {
        if (dep[x] < dep[y]) swap(x, y);
        for (int i = 19; i >= 0; i--) {
            if (dep[pa[x][i]] >= dep[y]) x = pa[x][i];
        }
        if (x == y) return x;
        for (int i = 19; i >= 0; i--) {
            if (pa[x][i] != pa[y][i]) x = pa[x][i], y = pa[y][i];
        }
        return pa[x][0];
    };
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u = edcc.dcc[u], v = edcc.dcc[v];
        int l = lca(u, v);
        int ans = dp[u] + dp[v] - 2 * dp[l];
        if(sz[l] > 1) ans++;
        cout << mi[ans] << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}