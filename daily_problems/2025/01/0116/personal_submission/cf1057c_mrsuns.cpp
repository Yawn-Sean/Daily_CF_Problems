void Solve() {
    int n, s, k;cin >> n >> s >> k;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    string str;cin >> str;str = ' ' + str;
    vector<array<int, 3>> v(n + 1);
    for (int i = 1;i <= n;i++) {
        v[i] = { a[i],i,(str[i] == 'R') ? 0 : ((str[i] == 'G') ? 1 : 2) };
    }
    sort(v.begin() + 1, v.end());
    vector dp(n + 1, vector<int>(k + 1, inf));
    for (int i = 1;i <= n;i++) {
        dp[i][v[i][0]] = abs(s - v[i][1]);
    }
    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) {
            if (v[i][0] < v[j][0] and v[i][2] != v[j][2]) {
                for (int u = 0;u <= k;u++) {
                    auto& ndp = dp[j][min(k, u + v[j][0])];
                    ndp = min(ndp, dp[i][u] + abs(v[i][1] - v[j][1]));
                }
            }
        }
    }
    int res = inf;
    for (int i = 1;i <= n;i++) {
        res = min(res, dp[i][k]);
    }
    cout << (res == inf ? -1 : res) << endl;
}
