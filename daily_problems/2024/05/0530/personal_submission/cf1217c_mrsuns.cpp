void Solve() {
    string s;cin >> s;
    int n = s.size();s = ' ' + s;
    auto calc = [&](int l, int r) {
        int res = 0;
        for (int i = l;i <= r;i++) {
            res = (res * 2 + s[i] - '0');
        }
        return res;
        };
    int res = 0;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        if (s[i] == '0') a[i] = a[i - 1] + 1;
        else a[i] = 0;
    }
    for (int i = 1;i <= n;i++) {
        if (s[i] == '0') continue;
        for (int len = 1;len <= 20 && i + len - 1 <= n;len++) {
            int r = i + len - 1;
            int zhi = calc(i, r);
            if (a[i - 1] + len >= zhi && zhi >= len) res += 1;
        }
    }
    cout << res << endl;
}
