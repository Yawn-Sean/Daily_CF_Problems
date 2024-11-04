int T;
string s;

void solve1() {
    cin >> s;
    int n = s.size();
    s = " " + s;
    int q;
    cin >> q;
    vector<vector<int>> cnt(n + 2, vector<int>(26, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            cnt[i][j] = cnt[i - 1][j];
        }
        cnt[i][s[i] - 'a']++;
    }
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "Yes\n";
        } else {
            int type_cnt = 0;
            for (int j = 0; j < 26; j++) {
                if (cnt[r][j] - cnt[l - 1][j] != 0) {
                    type_cnt++;
                }
            }
            if (type_cnt <= 2 && s[l] == s[r]) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        }
    }
}      
