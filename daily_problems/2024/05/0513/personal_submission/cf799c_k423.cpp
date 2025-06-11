// https://codeforces.com/contest/799/submission/260751500

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, C, D;
    cin >> n >> C >> D;
    vector<pii> c, d;
    for (int i = 0; i < n; ++i) {
        int x, y;
        char z;
        cin >> x >> y >> z;
        if (z == 'C' && y <= C) c.push_back({x, y});
        if (z == 'D' && y <= D) d.push_back({x, y});
    }
    auto help = [&](vector<pii> &a, int V) -> pii {
        fenwick<int> fmax(V + 1);
        int v1 = -1e9, v2 = -1e9;
        for (auto &[x, y]: a) {
            v1 = max(v1, x);
            v2 = max(v2, x + fmax.get(V - y));
            fmax.modify(y, x);
        }
        return {v1, v2};
    };
    auto [x1, x2] = help(c, C);
    auto [y1, y2] = help(d, D);
    cout << max({x1 + y1, x2, y2, 0}) << endl;
}
