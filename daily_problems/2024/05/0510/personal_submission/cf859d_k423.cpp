// https://codeforces.com/contest/859/submission/260201592

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    int N = 1 << n;
    vector<vector<ld>> f(N, vector<ld>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            f[i][j] = ld(x) / 100;
        }
    }
    function<pair<vld, vld>(int, int)> dfs = [&](int l, int r) -> pair<vld, vld> {
        if (l == r) return {vld{1}, vld{0}};
        int k = (r - l + 1) / 2;
        auto [Lp, Lv] = dfs(l, l + k - 1);
        auto [Rp, Rv] = dfs(l + k, r);
        vector<ld> p(k * 2), v(k * 2);
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                int x = l + i, y = l + k + j;
                p[i] += Lp[i] * Rp[j] * f[x][y];
                p[j + k] += Lp[i] * Rp[j] * f[y][x];
            }
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                int x = l + i, y = l + k + j;
                chmax(v[i], Lv[i] + Rv[j] + k * p[i]);
                chmax(v[j + k], Lv[i] + Rv[j] + k * p[j + k]);
            }
        }
        return {std::move(p), std::move(v)};
    };
 
    cout << ranges::max(dfs(0, N - 1).second) << endl;
}
