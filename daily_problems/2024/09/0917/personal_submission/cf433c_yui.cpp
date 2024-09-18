void solve() {
    int n, m;
    cin >> n >> m;
    vec<i64> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    i64 ans = 0;
    vec<i64> rec(n + 1);
    vec2<int> g(n + 1);
    for (int i = 1; i < m; i++) {
        i64 d = abs(a[i] - a[i - 1]);
        ans += d;

        if (a[i] != a[i - 1]) {
            rec[a[i]] += d;
            rec[a[i - 1]] += d;
            g[a[i]].push_back(a[i - 1]);
            g[a[i - 1]].push_back(a[i]);
        }
    }

    i64 d = 0;

    for (int i = 1; i <= n; i++) {
        if (g[i].empty()) continue;
        ranges::sort(g[i]);

        int mid = g[i][g[i].size() / 2];
        i64 s = 0;
        for (int y : g[i]) {
            s += 1LL * abs(y - mid);
        }

        chmax(d, rec[i] - s);
    }

    cout << ans - d << '\n'; 
}
