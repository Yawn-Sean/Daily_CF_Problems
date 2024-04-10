// https://codeforces.com/contest/439/submission/255939063

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;
    ranges::sort(a), ranges::sort(b);
    if (a[0] >= b[m - 1]) {
        cout << 0 << endl;
        return;
    }
    vector<i64> fa(n + 1), fb(m + 1);
    for (int i = 0; i < n; ++i) fa[i + 1] = fa[i] + a[i];
    for (int i = 0; i < m; ++i) fb[i + 1] = fb[i] + b[i];
 
    i64 ans = 1e18;
    auto help = [&](int k) {
        i64 i = ranges::upper_bound(a, k) - a.begin();
        i64 j = ranges::lower_bound(b, k) - b.begin();
        i64 cur = k * i - fa[i] + fb[m] - fb[j] - k * (m - j);
        ans = min(ans, cur);
    };
    for (int x: a) help(x);
    for (int x: b) help(x);
    cout << ans << endl;
}
