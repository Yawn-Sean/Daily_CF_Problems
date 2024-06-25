void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        int pre = f[a[i]];
        f[a[i]] = a[i] * (sum(a[i]) + 1) % MOD;
        add(a[i], (MOD + f[a[i]] - pre) % MOD);
    }
    cout << sum(maxn) << endl;
}
