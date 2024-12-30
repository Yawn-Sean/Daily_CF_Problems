void Solve() {
    int n, l;cin >> n >> l;
    vector<int> a(n);for (int i = 1;i < n;i++) cin >> a[i];
    int sum = 0;
    int mn = 1e9;
    for (int i = 1;i < l;i++) {
        sum += a[i];
    }
    for (int i = l;i < n;i++) {
        sum += a[i];
        sum -= a[i - l];
        mn = min(mn, sum);
    }
    cout << mn << endl;
}
