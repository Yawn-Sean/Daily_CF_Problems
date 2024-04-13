
void Solve(int TIME) {

    int n, k;cin >> n >> k;
    vi a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    int xsum = 0;for (int i = 1;i <= n;i++) xsum ^= a[i];
    debug(xsum);

    vvc<int> g(n + 1);
    for (int i = 1;i < n;i++) {
        int u, v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (xsum == 0) return YES, void();
    int cnt = 0;
    vi val(n + 1);
    auto dfs = [&](auto&& dfs, int u, int p)->void {
        val[u] = a[u];
        for (auto v : g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
            if (val[v] == xsum) cnt++;
            else val[u] ^= val[v];
        }
        };
    dfs(dfs, 1, 1);

    if (cnt >= 2 && k >= 3) YES;else NO;


}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);

    PreWork();

    int T = 1;
    cin >> T;

    int TIME = 0;
    while (T--) {
        Solve(++TIME);
    }

    return 0;
}
