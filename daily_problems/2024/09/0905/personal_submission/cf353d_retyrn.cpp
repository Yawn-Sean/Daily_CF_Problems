int n;
string s;

void solve() {
    cin >> s;
    n = sz(s);
    int cnt = 0, res = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'M') {
            cnt += 1;
            continue;
        }
        if (cnt > 0) res = max(cnt, res + 1);
    }
    cout << res << endl;
}
