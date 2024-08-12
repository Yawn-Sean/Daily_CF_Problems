void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    vector<vector<array<int, 3>>> evt(n + 1);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;i * (j - 1) + 2 <= n;j++) {
            int l = i * (j - 1) + 2, r = min(n, i * j + 1);
            evt[j].push_back({ l,r,i });
        }
    }
    vector<int> res(n + 1);
    BIT tr(n + 1);
    vector<array<int, 2>> c(n + 1);
    for (int i = 1;i <= n;i++) c[i] = {
        a[i],i
    };
    sort(c.begin() + 1, c.end());
    for (int i = 1;i <= n;) {
        int ks = i;i++;while (i <= n && c[i][0] == c[i - 1][0]) i++;
        int L = ks, R = i - 1;
        for (int j = L;j <= R;j++) {
            for (auto [l, r, id] : evt[c[j][1]]) {
                res[id] += tr.query(l, r);
            }
        }
        for (int j = L;j <= R;j++) tr.add(c[j][1], 1);
    }
    for (int i = 1;i < n;i++) cout << res[i] << " \n"[i == n - 1];

}
