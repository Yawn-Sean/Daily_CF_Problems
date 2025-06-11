int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    vvi g(n);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (accumulate(ALL(a), 0) == n) {
        cout << 1 << "\n";
        return 0;
    } 
    vi ans = {1};
    auto dfs = [&](auto &&self, int u, int pa) -> void {
        for (auto v : g[u]) {
            if (v == pa) continue;
            ans.pb(v + 1);
            a[v] *= -1;
            self(self, v, u);
            a[u] *= -1;
            ans.pb(u + 1);
        }
        if (a[u] == -1) {
            if (pa != -1) {
                ans.pb(pa + 1);
                ans.pb(u + 1);
                a[u] *= -1;
                a[pa] *= -1;
            } else {
                ans.pop_back();
            }
        }
    };
    dfs(dfs, 0, -1);
    for (auto v : ans) cout << v << " ";
}
