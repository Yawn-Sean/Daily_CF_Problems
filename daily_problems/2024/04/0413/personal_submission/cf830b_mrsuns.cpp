void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    map<int, int> mp;for (int i = 1;i <= n;i++) mp[a[i]] = 1;
    int tot = 0;for (auto& [i, j] : mp) j = ++tot;
    for (int i = 1;i <= n;i++) a[i] = mp[a[i]];
    vector<vector<int>> pos(tot + 1);
    for (int i = 1;i <= n;i++) pos[a[i]].push_back(i);
    BIT tr(n + 1);for (int i = 1;i <= n;i++) tr.add(i, 1);
    int now = 1;ll res = 0;
    for (int i = 1;i <= tot;i++) {
        int lb = lower_bound(pos[i].begin(), pos[i].end(), now) - pos[i].begin();
        for (int j = 0;j < pos[i].size();j++) {
            int x = pos[i][(lb + j) % pos[i].size()];
            if (now <= x) {
                res += tr.query(now, x);
            }
            else {
                res += tr.query(now, n) + tr.query(1, x);
            }
            tr.add(x, -1);
            now = x;
        }
    }
    cout << res << endl;
}
