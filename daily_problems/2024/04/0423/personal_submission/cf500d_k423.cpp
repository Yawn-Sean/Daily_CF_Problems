// https://codeforces.com/contest/500/submission/257800877

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<vector<pii>> g(n);
    vector<i64> cnt(n), val(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v >> val[i], --u, --v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    vector<int> h(n, 1);
    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto [v, i]: g[u]) {
            if (v == p) continue;
            dfs(v, u);
            i64 x = h[v], y = n - x;
            cnt[i] = x * (x - 1) / 2 * y + x * y * (y - 1) / 2;
            h[u] += x;
        }
    };
    dfs(0, -1);
    ld K = i64(n) * (n - 1) * (n - 2) / 6, S = 0;
    for (int i = 1; i < n; ++i) S += cnt[i] * val[i];
    int q;
    cin >> q;
    while (q--) {
        int i, w;
        cin >> i >> w;
        S += cnt[i] * (w - val[i]);
        val[i] = w;
        cout << S / K * 2 << endl;
    }
}
