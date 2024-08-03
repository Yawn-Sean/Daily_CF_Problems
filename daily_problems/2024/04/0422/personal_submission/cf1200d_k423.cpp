// https://codeforces.com/contest/1200/submission/257683210

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, k;
    cin >> n >> k;
    vector g(n, vector<int>(n)), f1 = g, f2 = g;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            g[i][j] = s[j] == 'B';
        }
    }
    auto flip = [&](vector<vector<int>> &a) {
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                swap(a[i][j], a[j][i]);
    };

    auto range_sum = [&](vector<int> &a, int l, int r) {
        return a[r] - (l ? a[l - 1] : 0);
    };

    auto help = [&](vector<vector<int>> &f) {
        vector<int> pf1(n), pf2(n);
        vector p = g;
        for (int v = 0, i = 0; i < n; ++i) {
            v += ranges::count(g[i], 1) == 0;
            pf1[i] = v;
            for (int j = 1; j < n; ++j) {
                p[i][j] += p[i][j - 1];
            }
        }
        for (int j = 0; j + k <= n; ++j) {
            for (int i = 0, v = 0; i < n; ++i) {
                v += range_sum(p[i], j, j + k - 1) == p[i][n - 1];
                pf2[i] = v;
            }
            for (int i = 0; i + k <= n; ++i) {
                f[i][j] = pf1[n - 1] - range_sum(pf1, i, i + k - 1) + range_sum(pf2, i, i + k - 1);
            }
        }
    };
    help(f1);
    flip(g), help(f2), flip(f2);
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans = max(ans, f1[i][j] + f2[i][j]);
    cout << ans << endl;
}
