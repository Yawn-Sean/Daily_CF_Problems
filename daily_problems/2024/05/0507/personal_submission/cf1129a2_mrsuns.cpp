void Solve() {
    int n, m;cin >> n >> m;
    vector<int> a(m + 1), b(m + 1);
    for (int i = 1;i <= m;i++) cin >> a[i] >> b[i];
    vector<int> cnt(n + 1);
    vector<int> mn(n + 1, n);
    for (int i = 1;i <= m;i++) {
        mn[a[i]] = min(mn[a[i]], (b[i] - a[i] + n) % n);
        cnt[a[i]]++;
    }
    vector<int> res(n + 1);
    for (int i = 1;i <= n;i++) {
        for (int step = 0;step < n;step++) {
            int j = (i + step - 1) % n + 1;
            if (cnt[j]) {
                res[i] = max(res[i], step + (cnt[j] - 1) * n + mn[j]);
            }
        }
    }
    for (int i = 1;i <= n;i++) cout << res[i] << " \n"[i == n];
}
