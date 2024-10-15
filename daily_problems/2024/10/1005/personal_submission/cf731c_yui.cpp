void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vec<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vec2<int> g(n);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        g[l].push_back(r);
        g[r].push_back(l);
    }

    vec<int> vis(n), cnt(k);
    vec<int> ls;
    int mx = 0, tot = 0;
    auto dfs = [&](auto&& self, int x) -> void {
        vis[x] = 1;
        cnt[a[x]]++;
        ls.push_back(a[x]);
        chmax(mx, cnt[a[x]]);
        tot++;
        for (int y : g[x]) {
            if (vis[y]) continue;
            self(self, y);
        }
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        mx = tot = 0;
        ls.clear();
        dfs(dfs, i);
        for (int i : ls) cnt[i] = 0;
        ans += tot - mx;
    }

    cout << ans << '\n';
}
