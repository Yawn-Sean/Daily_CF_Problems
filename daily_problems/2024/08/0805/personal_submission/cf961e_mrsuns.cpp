void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    vector<vector<int>> c(n + 1);for (int i = 1;i <= n;i++) {
        if (a[i] <= n) c[a[i]].push_back(i);
    }
    BIT tr(n + 1);int res = 0;
    for (int i = 1;i <= n;i++) tr.add(i, 1);
    for (int i = 1;i <= n;i++) {
        res += tr.query(i + 1, min(a[i], n));
        for (auto j : c[i]) tr.add(j, -1);
    }
    cout << res << endl;
}
