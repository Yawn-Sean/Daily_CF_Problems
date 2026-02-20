void solve() {
    int n;
    i64 l, r, k;
    cin >> n >> l >> r >> k;
    vector<i64> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    i64 mn = *min_element(a.begin(), a.end());
    if (mn <= k || r < k) {
        cout << -1;
        return;
    }
    i64 res = 1;
    __int128 mx = 1e12;
    for (i64 x: a) {
        res = min(mx, (__int128) x * res / gcd(x, res));
    }
    res = (r - k) / res * res + k;
    cout << (l <= res and res <= r ? res : -1);
}
