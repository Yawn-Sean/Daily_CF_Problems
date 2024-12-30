void Solve() {
    int n;cin >> n;
    string s;cin >> s;
    int m = s.size();s = ' ' + s;
    int pos = -1;
    for (int i = 1;i <= m;i++) {
        if (s[i] != s[1]) {
            pos = i;
            break;
        }
    }
    if (pos == -1) return cout << n << endl, void();
    int allx = 0, ally = 0;
    for (int i = 1;i <= m;i++) {
        if (s[i] == 'D') allx++;
        else ally++;
    }
    int yux = n - allx - 1;
    int yuy = n - ally - 1;
    int res = m + 1;
    for (int i = pos;i <= m;i++) {
        if (s[i] == 'D') {
            res += yuy;
        }
        else {
            res += yux;
        }
    }
    res += (yux + 1) * (yuy + 1) - 1;
    cout << res << endl;
}
