void Solve() {
    int n, x;cin >> n >> x;
    vector<array<int, 2>> e(n + 1);
    vector<int> a(1);a.push_back(x);
    for (int i = 1;i <= n;i++) {
        int l, r;cin >> l >> r;
        e[i] = { l,r };
        a.push_back(l);
        a.push_back(r);
    }
    sort(a.begin() + 1, a.end());
    a.erase(unique(a.begin() + 1, a.end()), a.end());
    int m = a.size() - 1;
    const ll inf = 1e18;
    vector<int> dp(m + 1, inf);
    vector<int> ndp(m + 1, inf);
    vector<int> dp1(m + 1, inf);
    vector<int> ndp1(m + 1, inf);
    vector<int> dp2(m + 2, inf);
    vector<int> ndp2(m + 2, inf);
    auto cost = [&](int l, int r, int x)->ll {
        if (x < l) return l - x;
        else if (r < x) return x - r;
        else return 0;
        };
    dp[lower_bound(a.begin() + 1, a.end(), x) - a.begin()] = 0;
    for (int j = 1;j <= m;j++) dp1[j] = min(dp1[j - 1], dp[j] - a[j]);
    for (int j = m;j >= 1;j--) dp2[j] = min(dp2[j + 1], dp[j] + a[j]);
    for (int i = 1;i <= n;i++) {
        auto [l, r] = e[i];
        for (int j = 1;j <= m;j++) {
            ndp[j] = min(dp1[j] + a[j], dp2[j] - a[j])
                + cost(l, r, a[j]);
        }
        for (int j = 1;j <= m;j++) ndp1[j] = min(ndp1[j - 1], ndp[j] - a[j]);
        for (int j = m;j >= 1;j--) ndp2[j] = min(ndp2[j + 1], ndp[j] + a[j]);
        swap(dp, ndp);
        swap(dp1, ndp1);
        swap(dp2, ndp2);
    }
    ll res = inf;
    for (int i = 1;i <= m;i++) res = min(res, dp[i]);
    cout << res << endl;
}
