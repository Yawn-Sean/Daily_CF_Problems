// https://codeforces.com/contest/1525/submission/258179546

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[j][i];
        }
    }
    C(n, 0);
    Mint ans = m * fact[n];
    for (vector<int> &col: g) {
        vector<int> cnt(n + 2);
        for (int x: col) cnt[x]++;
        Mint cur = 1;
        for (int i = 1, j = 0; i <= n + 1; j += cnt[i], ++i) {
            cur *= C(i - 1 - j, cnt[i]) * fact[cnt[i]];
        }
        ans -= cur;
    }
    cout << ans / fact[n] << endl;
}
