int n, m, k, w;
using ai3 = array<int, 3>;

int cal(vector<string>& a, vector<string>& b) {
    int res = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            res += (a[i][j] != b[i][j]);
        }
    }
    return res;
}
void solve() {
    cin >> n >> m >> k >> w;
    vector<vector<string>> g(k, vector<string>(n));
    cin >> g;
    vector<ai3> e;
    for (int i = 0; i < k; i ++) {
        for (int j = i + 1; j < k; j ++) {
            int t = cal(g[i], g[j]) * w;
            e.push_back({t, i, j});
        }
    }
    for (int i = 0; i < k; i ++) {
        e.push_back({m * n, k, i});
    }
    sort(all(e));
    vector<vector<int>> ans(k + 1);
    
    int res = 0;
    DSU dsu(k + 1);
    for (auto [c, x, y] : e) {
        if (dsu.same(x, y)) continue;
        dsu.merge(x, y);
        res += c;
        ans[x].push_back(y);
        ans[y].push_back(x);
    }
    
    auto dfs = [&](auto&& dfs, int u, int fa) -> void {
        for (auto x : ans[u]) {
            if (x == fa) continue;
            cout << (x + 1) << ' ' << (u == k ? 0 : u + 1) << endl;
            dfs(dfs, x, u);
        }
    };
    cout << res << endl;
    dfs(dfs, k, -1);
}