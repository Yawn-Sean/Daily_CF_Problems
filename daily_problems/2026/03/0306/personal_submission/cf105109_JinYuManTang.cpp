void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    i64 res = 0;
    for (int i = 0; i < n; i++) {
        i64 sum = 0;
        int l = i, r = i + 1;
        while (l && sum + a[l - 1] < a[i]) {
            sum += a[--l];
        }
        for (; l <= i; l++) {
            while (r < n && sum + a[r] < a[i]) {
                sum += a[r++];
            }
            res += r - i;
            sum -= a[l];
        }
    }
    cout << res << '\n';
}
