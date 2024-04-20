// https://codeforces.com/contest/1615/submission/257390834

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n * 2);
    vector<array<int, 3>> adjs(n - 1);
    for (auto &[u, v, w]: adjs) {
        cin >> u >> v >> w;
        u--, v--;
        if (w >= 0) {
            if (__builtin_popcount(w) & 1) dsu.join(u, v + n), dsu.join(u + n, v);
            else dsu.join(u, v), dsu.join(u + n, v + n);
        }
    }
    bool ok = true;
    while (m--) {
        int u, v, x;
        cin >> u >> v >> x, u--, v--;
        if (!ok) continue;
        if (x) {
            ok &= dsu[u] != dsu[v];
            dsu.join(u, v + n), dsu.join(u + n, v);
        } else {
            ok &= dsu[u] != dsu[v + n];
            dsu.join(u, v), dsu.join(u + n, v + n);
        }
    }
    if (!ok) return NO();
    YES();
    for (auto &[u, v, w]: adjs) {
        if (w < 0) {
            if (dsu[u] == dsu[v] || dsu[u] == dsu[v + n]) {
                w = dsu[u] == dsu[v + n];
            } else {
                w = 0;
                dsu.join(u, v), dsu.join(u + n, v + n);
            }
        }
        cout << u + 1 << ' ' << v + 1 << ' ' << w << endl;
    }
}
