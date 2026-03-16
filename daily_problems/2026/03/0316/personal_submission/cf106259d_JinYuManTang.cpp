void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    sort(a.begin(), a.end());
    int res = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        chmin(res, a[i] ^ a[i + 1]);
    }
    cout << res << '\n';
}
