void Solve() {
    int n, a, b, k;cin >> n >> a >> b >> k;
    string s;cin >> s;s = ' ' + s;
    vector<int> res;
    for (int i = 1;i <= n;) {
        if (s[i] == '1') {
            i++;continue;
        }
        int ks = i;
        i++;
        while (i <= n && s[i] == '0') i++;
        for (int j = ks + b - 1;j < i;j += b) res.push_back(j);
    }
    int m = res.size();
    cout << m - a + 1 << endl;
    for (int i = 0;i < m - a + 1;i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
}
