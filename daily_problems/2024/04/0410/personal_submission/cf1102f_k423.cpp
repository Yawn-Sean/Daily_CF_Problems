// https://codeforces.com/contest/1102/submission/255941678

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m, inf = 1e9 + 7;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (vector<int> &row: g) for (int &x: row) cin >> x;
    if (n == 1) {
        int ans = inf;
        for (int i = 0; i + 1 < m; ++i)
            chmin(ans, abs(g[0][i + 1] - g[0][i]));
        cout << ans << endl;
        return;
    }
    vector<vector<int>> f1(n, vector<int>(n, inf)), f2 = f1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            for (int k = 0; k < m; ++k) {
                chmin(f1[i][j], abs(g[i][k] - g[j][k]));
                if (k) chmin(f2[i][j], abs(g[i][k - 1] - g[j][k]));
            }
        }
    }
    vector f(1 << n, vector(n, vector(n, 0)));
    for (int mask = 0; mask < 1 << n; ++mask) {
        vector<int> id;
        for (int i = 0; i < n; ++i) if (mask >> i & 1) id.emplace_back(i);
        if (id.size() < 2) continue;
        auto &ff = f[mask];
        if (id.size() == 2) {
            int i = id[0], j = id[1];
            ff[i][j] = ff[j][i] = f1[i][j];
            continue;
        }
        for (int k: id) {
            int sub = mask ^ (1 << k);
            for (int i: id) {
                if (i == k) continue;
                for (int j: id) {
                    if (j == i || j == k) continue;
                    chmax(ff[i][k], min(f[sub][i][j], f1[j][k]));
                }
            }
        }
    }
    int ans = 0;
    auto &ff = f.back();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            chmax(ans, min(ff[i][j], f2[j][i]));
        }
    }
    cout << ans << endl;
}
