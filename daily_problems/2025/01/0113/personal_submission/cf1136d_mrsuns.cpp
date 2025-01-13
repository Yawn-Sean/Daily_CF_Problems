void Solve() {
    int n, m;cin >> n >> m;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    vector<int> pos(n + 1);for (int i = 1;i <= n;i++) pos[a[i]] = i;
    vector<vector<int>> in(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1;i <= m;i++) {
        int u, v;cin >> u >> v;
        if (pos[u] > pos[v]) continue;
        cnt[u]++;
        in[v].push_back(u);
    }
    int res = 0, t = 0;
    for (int i = n - 1;i >= 1;i--) {
        if (cnt[a[i]] >= n - i - t) {
            for (auto j : in[a[i]]) {
                cnt[j]--;
            }
            res += 1;
            t++;
        }
    }
    cout << res << endl;
