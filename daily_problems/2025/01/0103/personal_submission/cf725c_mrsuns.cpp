void Solve() {
    string s;cin >> s;
    int n = s.size();s = ' ' + s;
    vector<int> ps(26);
    int d;char x;
    int ps1, ps2;
    for (int i = 1;i <= n;i++) {
        auto c = s[i] - 'A';
        if (ps[c]) {
            if (ps[c] == i - 1) return cout << "Impossible\n", void();
            int x = i - ps[c];
            vector res(2, string(14, ' '));
            for (int j = 1;j <= (x + 1) / 2;j++) {
                res[0][j] = s[ps[c] + (x + 1) / 2 + j - 1];
                res[1][j] = s[ps[c] + (x + 1) / 2 - j];
            }
            int si = 1, sj = (x + 1) / 2;
            for (int j = ps[c] - 1;j >= 1;j--) {
                sj += (si ? 1 : -1);
                if (sj > 13) si = 0, sj = 13;
                res[si][sj] = s[j];
            }
            si = 0, sj = x / 2;
            for (int j = i + 1;j <= n;j++) {
                sj += (!si ? 1 : -1);
                if (sj > 13) si = 1, sj = 13;
                res[si][sj] = s[j];
            }
            cout << res[0].substr(1) << endl;
            cout << res[1].substr(1) << endl;
            return;
        }
        ps[s[i] - 'A'] = i;
    }
}
