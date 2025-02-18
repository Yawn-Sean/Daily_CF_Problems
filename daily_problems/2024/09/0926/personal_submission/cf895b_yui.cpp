void solve() {
    int n;
    i64 x, k;
    cin >> n >> x >> k;
    vec<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ranges::sort(a);

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        i64 l = (((a[i] + x - 1) / x) + k - 1) * x, r = l + x - 1;
        if (k == 0) {
            if (a[i] % x == 0) continue;
            l = a[i];
        }
        ans += lower_bound(a.begin(), a.end(), r + 1) - lower_bound(a.begin(), a.end(), l);
    }
    cout << ans << '\n';
}
