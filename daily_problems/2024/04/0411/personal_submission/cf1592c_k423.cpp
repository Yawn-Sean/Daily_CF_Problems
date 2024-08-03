// https://codeforces.com/contest/1592/submission/256081448

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector<int> a(n);
    for (int &x: a) cin >> x;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v, u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int s = accumulate(itr(a), 0, bit_xor<>{});
    if (!s) return YES();
    if (k == 2) return NO();
    function<pii(int, int)> dfs = [&](int u, int p) -> pii {
        int x = 0, y = a[u];
        for (int v: g[u]) {
            if (v == p) continue;
            auto [xx, yy] = dfs(v, u);
            x += xx, y ^= yy;
        }
        if (y == s) x++, y = 0;
        return {x, y};
    };
    dfs(0, -1).first >= 2 ? YES() : NO();
}
