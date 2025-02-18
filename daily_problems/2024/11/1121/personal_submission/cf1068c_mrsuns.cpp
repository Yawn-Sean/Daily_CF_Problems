void Solve() {
    int n, m;cin >> n >> m;
    vector<vector<array<int, 2>>> a(n + 1);
    for (int i = 1;i <= n;i++) {
        a[i].push_back({ i,i });
    }
    for (int i = 1;i <= m;i++) {
        int u, v;cin >> u >> v;
        a[u].push_back({ u,n + i });
        a[v].push_back({ v,n + i });
    }
    for (int i = 1;i <= n;i++) {
        cout << a[i].size() << endl;
        for (auto [x, y] : a[i]) {
            cout << x << ' ' << y << endl;
        }
    }
}
