void solve() {
    int n;
    i64 len;
    cin >> n >> len;
    vector<i64> a(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    a[0] = 0, a[n] = len;
    i64 res = len;
    int p1 = 0, p2 = 0;
    for (int i = 2; i < n - 1; i++) {
        while (a[p1 + 1] <= a[i] - a[p1 + 1]) {
            p1++;
        }
        while (a[p2 + 1] - a[i] <= len - a[p2 + 1]) {
            p2++;
        }
        for (int j = p1; j <= p1 + 1; j++) {
            for (int k = p2; k <= p2 + 1; k++) {
                i64 mx = max({a[j], a[i] - a[j], a[k] - a[i], len - a[k]});
                i64 mn = min({a[j], a[i] - a[j], a[k] - a[i], len - a[k]});
                res = min(res, mx - mn);
            }
        }
    }
    cout << res << '\n';
}

