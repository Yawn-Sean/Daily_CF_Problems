int n, m;
string str;

void solve() {
    cin >> str;
    n = sz(str);
    vector<vector<int>> s(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1];
        s[i][str[i-1] - 'a'] += 1;
    }
    cin >> m;
    while (m --) {
        int l, r;
        cin >> l >> r;
        if (str[l-1] != str[r-1] or l == r) {
            cout << "Yes" << endl;
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i ++) {
            if (s[l-1][i] != s[r][i]) cnt += 1;
        }
        if (cnt >= 3) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}