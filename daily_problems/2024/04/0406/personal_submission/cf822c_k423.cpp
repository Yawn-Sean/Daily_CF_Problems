// https://codeforces.com/contest/822/submission/255308272

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m, inf = 2e9 + 1;
    cin >> n >> m;
    vector<array<int, 3>> p(n);
    for (auto &[l, r, v]: p) cin >> l >> r >> v;
    int ans = inf;
    ranges::sort(p);
    map<int, int> mn;
    priority_queue<pii, vector<pii>, greater<>> Q;
    for (int i = 0; i < n; ++i) {
        while (!Q.empty() && Q.top().first < p[i][0]) {
            auto [_, j] = Q.top();
            Q.pop();
            int x = p[j][1] - p[j][0] + 1, y = p[j][2];
            if (mn.contains(x)) mn[x] = min(mn[x], y);
            else mn[x] = y;
        }
        int x = p[i][1] - p[i][0] + 1, y = p[i][2];
        if (mn.contains(m - x)) ans = min(ans, mn[m - x] + y);
        Q.emplace(p[i][1], i);
    }
    if (ans == inf) ans = -1;
    cout << ans << endl;
}
