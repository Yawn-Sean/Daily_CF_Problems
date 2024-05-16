int n, k;

void solve() {
    cin >> n >> k;
    vector<int> a(n - 1);
    cin >> a;
    int res = inf, cur = 0;
    for (int i = 0; i < n - 1; i ++) {
        cur += a[i];
        if (i - k >= 0) cur -= a[i - k];
        if (i >= k - 1) res = min(res, cur);
    }
    cout << res << endl;
}