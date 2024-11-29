void Solve() {
    int n, m, k;cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++) cin >> a[i][j];
    int res_sco = 0, res_ope = 0;
    for (int j = 1;j <= m;j++) {
        vector<int> s(n + 1);
        for (int i = 1;i <= n;i++) {
            s[i] = s[i - 1] + (a[i][j] == 1);
        }
        int sco = 0, ope = 0, cnt = 0;
        for (int i = 1;i <= n;i++) {
            if (a[i][j] == 1) {
                int t = s[min(n, i + k - 1)] - s[i - 1];
                if (t > sco) {
                    sco = t, ope = cnt;
                }
                cnt++;
            }
        }
        res_sco += sco, res_ope += ope;
    }
    cout << res_sco << ' ' << res_ope << endl;
}
