void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<int> cnt(1e5 + 10);
    for (int i = 1;i <= n;i++) {
        int x = a[i];
        while (x) {
            cnt[x] += 1;
            x /= 2;
        }
    }
    int lc = 0;
    for (int i = 1e5;i >= 1;i--) {
        if (cnt[i] == n) {
            lc = i;break;
        }
    }
    cnt.assign(1e5 + 10, 0);for (int i = 1;i <= n;i++) cnt[a[i]] += 1;
    int res = 1e9, now = 0;
    vector<int> dis(1e5 + 10), szcnt(1e5 + 10);
    auto dfs0 = [&](auto&& dfs0, int u)->void {
        for (int v = 2 * u;v <= 2 * u + 1;v++) {
            if (v <= 1e5) {
                dis[v] = dis[u] + 1;
                now += dis[v] * cnt[v];
                dfs0(dfs0, v);
                szcnt[u] += szcnt[v];
            }
        }
        szcnt[u] += cnt[u];
        };
    dfs0(dfs0, lc);
    //cout << "lc :" << lc << endl;
    res = now;
    vector<int> f(1e5 + 10);f[lc] = now;
    auto dfs = [&](auto&& dfs, int u)->void {
        if (2 * u <= 1e5) {
            int v = 2 * u;
            f[v] = f[u] + (n - szcnt[v]) - szcnt[v];
            res = min(res, f[v]);
            dfs(dfs, v);
        }
        };
    dfs(dfs, lc);
    cout << res << endl;

}
