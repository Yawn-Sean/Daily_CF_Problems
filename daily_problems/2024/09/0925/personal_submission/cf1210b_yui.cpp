void solve() {
    int n;
    cin >> n;
    vec<pair<i64, i64>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }

    i64 ans = 0;
    multiset<i64> rec;
    vec<int> vis(n);
    for (auto& [x, y] : a) {
        if (rec.contains(x)) {
            for (int i = 0; i < n; i++) {
                if (vis[i]) continue;
                if ((a[i].first & x) == a[i].first) {
                    vis[i] = true;
                    ans += a[i].second;
                }
            }
        } else {
            rec.insert(x);
        }
    }

    cout << ans << '\n';
}
