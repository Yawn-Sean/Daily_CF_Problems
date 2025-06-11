void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);
    int res = 0;
    for (int i = n;i >= 1;) {
        int msk = (1 << __lg(i) + 1) - 1;
        for (int j = i;j >= (i ^ msk);j--) {
            a[j] = j ^ msk;
        }
        res += (i - (i ^ msk) + 1) * msk;
        i = (i ^ msk) - 1;
    }
    cout << res << endl;
    for (int i = 0;i <= n;i++) {
        cout << a[i] << ' ';
    }
}
