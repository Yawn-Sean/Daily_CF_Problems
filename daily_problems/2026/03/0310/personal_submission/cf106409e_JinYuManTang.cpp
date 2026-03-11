void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> cnt(26);
    for (char c: s) {
        cnt[c - 'a']++;
    }
    for (int &x: cnt) {
        x /= 2;
    }
    i64 res = 0;
    vector<int> first, second;
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (cnt[c]) {
            cnt[c]--;
            first.push_back(c);
            res += i;
        } else {
            second.push_back(c);
        }
    }
    int m = n / 2;
    res -= 1LL * (m - 1) * m / 2;
    vector<vector<int>> pos1(26), pos2(26);
    for (int i = 0; i < m; i++) {
        pos1[first[i]].push_back(i);
        pos2[second[i]].push_back(i);
    }
    vector<int> perm(m);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < pos1[i].size(); j++) {
            perm[pos1[i][j]] = pos2[i][j];
        }
    }
    Fenwick<int> fwk(m);
    for (int i = 0; i < m; i++) {
        res += fwk.rangeSum(perm[i], m);
        fwk.add(perm[i], 1);
    }
    cout << res << '\n';
}
