void solve() {
    int n;
    cin >> n;
    vec<int> b(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s += p[i];
    }
    vec2<int> g(n);
    for (int i = 0; i < n; i++) {
        g[i].push_back(b[i]);
    }

    vec<int> vis(n);
    auto dfs = [&](auto&& self, int x) -> void {
        vis[x] = true;
        for (int y : g[x]) {
            if (vis[y]) continue;
            self(self, y);
        }
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        ans++;
        dfs(dfs, i);
    }

    if (ans == 1) ans--;

    if (s % 2 == 0) ans++;

    cout << ans << '\n';
}
