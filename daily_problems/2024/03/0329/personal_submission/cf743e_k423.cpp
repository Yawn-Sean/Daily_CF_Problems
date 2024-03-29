// https://codeforces.com/contest/743/submission/253874557

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> a(n), cnt(8);
    vector<vector<int>> idx(8);
    for (int &x: a) cin >> x, x--, cnt[x]++;
    for (int i = 0; i < n; ++i) idx[a[i]].emplace_back(i);
    int ans = 1, m = ranges::min(cnt);
    for (int k = 0; k <= m; ++k) {
        vector<vector<int>> f(n + 1, vector<int>(1 << 8, -1e9));
        vector<int> rem = cnt;
        f[0][0] = 0;
        for (int i = 0; i < n; rem[a[i]]--, ++i) {
            for (int j = 0; j < 1 << 8; ++j) {
                chmax(f[i + 1][j], f[i][j]);
            }
            int x = a[i];
            if (rem[x] < k) continue;
            int l = idx[x].size() - rem[a[i]];
            int r1 = k ? idx[x][l + k - 1] : -1;
            int r2 = l + k < idx[x].size() ? idx[x][l + k] : -1;
            for (int j = 0; j < 1 << 8; ++j) {
                if (j >> x & 1) continue;
                if (r1 >= 0) chmax(f[r1 + 1][j | (1 << x)], f[i][j] + k);
                if (r2 >= 0) chmax(f[r2 + 1][j | (1 << x)], f[i][j] + k + 1);
            }
        }
        chmax(ans, k ? f[n][255] : ranges::max(f[n]));
    }
    cout << ans << endl;
}