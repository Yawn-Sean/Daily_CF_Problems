void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        a[i] --;
    }
    for (int i = 0; i < n; i ++ ) {
        cin >> b[i];
        b[i] --;
    }

    vector<int> p(n, -1), st(n);
    for (int i = 0; i < n; i ++ ) {
        p[a[i]] = b[i];
    }

    int tot = 0;
    for (int i = 0; i < n; i ++ ) {
        if (!st[i]) {
            int cnt = 0;
            int j = i;
            while (!st[j]) {
                st[j] = 1;
                cnt ++;
                j = p[j];
            }
            tot += cnt / 2;
        }
    }
    cout << 1LL * tot * (n - tot) * 2 << endl;
}
