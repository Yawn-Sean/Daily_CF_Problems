// https://codeforces.com/contest/1219/submission/261114306

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    vector<i64> row(n), col(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            row[i] += g[i][j];
            col[j] += g[i][j];
        }
    }
    if (n <= 4 || m <= 4) {
        cout << accumulate(itr(row), 0ll) << endl;
        return;
    }

    auto f1 = [&](vector<int> &ids) {
        vector<i64> mx(4 - ids.size(), -1e18);
        i64 cur = 0;
        for (int i: ids) cur += row[i];
        for (int j = 0; j < m; ++j) {
            i64 v = col[j];
            for (int i: ids) v -= g[i][j];
            for (i64 &x: mx) if (v > x) swap(v, x);
        }
        return cur + accumulate(itr(mx), 0ll);
    };

    auto f2 = [&](vector<int> &ids) {
        vector<i64> mx(4 - ids.size(), -1e18);
        i64 cur = 0;
        for (int i: ids) cur += col[i];
        for (int i = 0; i < n; ++i) {
            i64 v = row[i];
            for (int j: ids) v -= g[i][j];
            for (i64 &x: mx) if (v > x) swap(v, x);
        }
        return cur + accumulate(itr(mx), 0ll);
    };

    vector<int> ids;
    i64 ans = max(f1(ids), f2(ids));
    for (int i = 0; i < n; ++i) {
        ids.emplace_back(i);
        chmax(ans, f1(ids));
        if (n <= m) {
            for (int j = i + 1; j < n; ++j) {
                ids.push_back(j);
                chmax(ans, f1(ids));
                ids.pop_back();
            }
        }
        ids.pop_back();
    }
    for (int i = 0; i < m; ++i) {
        ids.emplace_back(i);
        chmax(ans, f2(ids));
        if (n > m) {
            for (int j = i + 1; j < m; ++j) {
                ids.push_back(j);
                chmax(ans, f2(ids));
                ids.pop_back();
            }
        }
        ids.pop_back();
    }
    cout << ans << endl;
}
