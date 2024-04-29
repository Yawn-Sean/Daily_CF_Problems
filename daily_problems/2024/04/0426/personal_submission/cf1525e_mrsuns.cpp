void Solve() {
    int n, m;cin >> n >> m;
    int fac = 1;
    for (int i = 1;i <= n;i++) {
        fac = fac * i % MOD;
    }
    const int ifac = inv(fac);
    vector<vector<int>> d(n + 1, vector<int>(m + 1));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) cin >> d[i][j];
    }
    int ans = 0;
    for (int i = 1;i <= m;i++) {
        vector<int> cnt(n + 2);
        for (int j = 1;j <= n;j++) {
            cnt[d[j][i]] += 1;
        }
        int res = 1, s = 0;
        for (int j = 1;j <= n;j++) {
            s += cnt[n - j + 2];
            res = res * (s - j + 1) % MOD;
        }
        ans = (ans + (fac - res + MOD) % MOD * ifac % MOD) % MOD;
    }
    cout << ans << endl;
}
