// https://codeforces.com/contest/1912/submission/256715397

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    i64 ans, n;
    cin >> ans >> n;
    vector<vector<pii>> g(n);
    priority_queue<pii> Q;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        i64 val = 0, min_val = 0, x;
        for (int j = 0; j < m; ++j) {
            cin >> x;
            if (x < 0 && val > 0) {
                g[i].emplace_back(min_val, val);
                val = min_val = x;
            } else {
                val += x;
                min_val = min(val, min_val);
            }
        }
        if (val > 0) g[i].emplace_back(min_val, val);
        ranges::reverse(g[i]);
        if (!g[i].empty()) Q.emplace(g[i].back().first, i);
    }
    while (!Q.empty() && Q.top().first + ans >= 0) {
        auto [_, i] = Q.top();
        Q.pop();
        auto [x, y] = g[i].back();
        g[i].pop_back();
        ans += y;
        if (!g[i].empty()) Q.emplace(g[i].back().first, i);
    }
    cout << ans << endl;
}
