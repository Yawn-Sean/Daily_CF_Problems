void Solve() {
    int n, m;cin >> n >> m;
    DSU d(2 * n + 1);
    for (int i = 1;i <= m;i++) {
        int u, v;cin >> u >> v;
        d.merge(u, v + n);
        d.merge(v, u + n);
    }
    int mx = 0;
    for (int i = 1;i <= n;i++) {
        if (d.same(i, i + n)) {
            return cout << "0 1\n", void();
        }
    }
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        a[d.find(i)] += 1;
    }
    for (int i = 1;i <= n;i++) mx = max(mx, a[i]);
    if (mx > 1) {
        int res = 0;
        for (int i = 1;i <= n;i++) {
            res += a[i] * (a[i] - 1) / 2;
        }
        cout << 1 << " " << res << endl;
    }
    else {
        if (m == 0) {
            cout << 3 << ' ' << n * (n - 1) * (n - 2) / 6 << endl;
        }
        else {
            cout << 2 << " " << m * (n - 2) << endl;
        }
    }
}
