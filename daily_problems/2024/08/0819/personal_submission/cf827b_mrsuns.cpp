void Solve() {
    int n, k;cin >> n >> k;
    int cnt = n - 1;
    cout << (cnt / k) * 2 + min(2LL, (cnt % k)) << endl;
    for (int i = 1;i <= k;i++) {
        cout << k + 1 << " " << i << endl;
    }
    vector<int> a(k + 1);for (int i = 1;i <= k;i++) a[i] = i;
    for (int i = k + 2, j = 1;i <= n;i++, j = (j == k ? 1 : j + 1)) {
        cout << i << ' ' << a[j] << endl;
        a[j] = i;
    }
}
