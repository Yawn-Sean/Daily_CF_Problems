int g[N + 1];
void Prework() {
    for (int i = 2;i <= N;i++) {
        g[i] = g[Ones(i)] + 1;
    }
    g[0] = -1;
}
int f[N + 1][N + 1];
void Solve() {
    string s;cin >> s;
    int k;cin >> k;
    if (k == 0) return cout << 1 << endl, void();
    memset(f, -1, sizeof f);
    auto dp = [&](string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        auto dfs = [&](auto&& dfs, int pos, int lead, int lim, int cnt1)->ll {
            if (pos < 0) return (g[cnt1] + 1 == k);
            if (!lim && !lead && f[pos][cnt1] != -1) return f[pos][cnt1];
            int mx = lim ? s[pos] - '0' : 1;
            int t = 0;
            if (lead) (t += dfs(dfs, pos - 1, 1, 0, 0)) %= MOD;
            for (int i = lead;i <= mx;i++) {
                (t += dfs(dfs, pos - 1, 0, lim && (i == mx), cnt1 + (i == 1))) %= MOD;
            }
            if (!lim && !lead) f[pos][cnt1] = t;
            return t;
            };
        return dfs(dfs, n - 1, 1, 1, 0);
        };
    cout << dp(s) - (k == 1) << endl;
}
