// https://codeforces.com/contest/1019/submission/260100025

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> p(m);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p[x - 1].emplace_back(y);
    }
    for (int i = 1; i < m; ++i) ranges::sort(p[i]);
    i64 ans = 1e18;
    for (int k = p[0].size(); k <= n; ++k) {
        i64 cur = 0, cnt = p[0].size();
        vector<int> a;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < p[i].size(); ++j) {
                if (j + k <= p[i].size()) {
                    cur += p[i][j], cnt++;
                } else {
                    a.emplace_back(p[i][j]);
                }
            }
        }
        if (cnt < k) {
            ranges::nth_element(a, a.begin() + k - cnt);
            cur += accumulate(a.begin(), a.begin() + k - cnt, 0ll);
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
}
