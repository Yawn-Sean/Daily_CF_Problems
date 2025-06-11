void solve() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto check = [&](int cnt) -> bool {
        int t = k;
        for(int i = cnt - 1, j = n - 1; i >= 0; i --, j --) {
            // cerr << i << ' ' << j << ' ' << a[j] << ' ' << b[i] << ' ' << t << endl;
            if (t + a[j] < b[i]) return false;
            t -= max(0, b[i] - a[j]);
        }
        return true;
    };
    // cerr << check(2) << endl;

    int l = 0, r = min(n, m);
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    for (int i = 0; i < r; i ++ ) {
        k -= b[i];
    }
    cout << l << ' ' << abs(min(0, k)) * (l != 0) << endl;
}
