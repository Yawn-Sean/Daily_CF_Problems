void Solve() {
    string s;cin >> s;
    int n = s.size();s = ' ' + s;
    int res = 0;
    for (int i = 1;i <= n;) {
        int ks = i;
        i++;
        while (i <= n && s[i] != s[i - 1]) i++;
        res = max(res, i - ks);
    }
    if (s[1] != s[n]) {
        vector<int> pre(n + 1);
        vector<int> suf(n + 2);
        pre[1] = 1;
        for (int i = 2;i <= n;i++) {
            if (s[i] != s[i - 1]) pre[i] = pre[i - 1] + 1;
            else {
                for (int j = i;j <= n;j++) pre[j] = pre[i - 1];
                break;
            }
        }
        suf[n] = 1;
        for (int i = n - 1;i >= 1;i--) {
            if (s[i] != s[i + 1]) suf[i] = suf[i + 1] + 1;
            else {
                for (int j = i;j >= 1;j--) suf[j] = suf[i + 1];
                break;
            }
        }

        for (int i = 1;i < n;i++) {
            res = max(res, pre[i] + suf[i + 1]);
        }
    }
    cout << res << endl;
}
