void Solve() {
    int n, k, x;cin >> n >> k >> x;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1;i <= n;i++) pre[i] = pre[i - 1] | a[i];
    for (int i = n;i >= 1;i--) suf[i] = suf[i + 1] | a[i];
    auto gc = [&](int p) {
        int res = 0;
        int y = a[p];for (int i = 1;i <= k;i++) y *= x;
        res = pre[p - 1] | y | suf[p + 1];
        return res;
        };
    int res = 0;
    for (int i = 1;i <= n;i++) res = max(res, gc(i));
    cout << res << endl;
}
