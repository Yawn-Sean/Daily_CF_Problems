int n;
string s;

void solve() {
    cin >> s;
    n = sz(s);
    // 可以视为一个环
    s += s;
    int last = 0, res = 0;
    for (int i = 0; i < sz(s); i ++) {
        if (i and s[i] == s[i - 1]) {
            res = max(res, last);
            last = 1;
        }
        else {
            last += 1;
        }
    }
    res = max(res, last);
    res = min(res, n);
    cout << res << endl;
}