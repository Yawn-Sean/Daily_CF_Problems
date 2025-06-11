void solve() {
    int n;
    cin >> n;
    vec<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        a[i] = {x, y};
    }
    
    vec<int> p(n);
    iota(p.begin(), p.end(), 0);
    ranges::sort(p, {}, [&](auto x){ return pair<int, int>{a[x].first, -a[x].second}; });

    vec<int> ans(n, -1);
    int cur = 2e9, idx = -1;
    for (int i : p) {
        if (a[i].second <= cur) {
            cur = a[i].second;
            idx = i;
        } else {
            ans[i] = idx + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}
