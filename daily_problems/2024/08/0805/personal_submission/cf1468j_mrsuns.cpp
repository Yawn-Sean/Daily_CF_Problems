void Solve() {
    int n, m, k;cin >> n >> m >> k;
    vector<array<int, 3>> e;
    for (int i = 1;i <= m;i++) {
        int u, v, w;cin >> u >> v >> w;
        e.push_back({ w,u,v });
    }
    DSU d(n + 1);
    vector<int> ins(m);
    sort(e.begin(), e.end());
    int res = 0, mx = 0;
    for (int i = 0;i < m;i++) {
        auto [w, u, v] = e[i];
        if (d.merge(u, v)) {
            ins[i] = 1;
            if (w > k) {
                res += w - k;
            }
            mx = max(mx, w);
        }
    }
    if (mx >= k) {
        cout << res << endl;
        return;
    }
    res = k - mx;
    for (int i = 0;i < m;i++) {
        if (!ins[i]) {
            res = min(res, abs(k - e[i][0]));
        }
    }
    cout << res << endl;

}
