int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    
    if (sz(s) % n) {
        int len = (sz(s) / n + 1);
        string cur = "1" + string(n - 1, '0');
        for (int i = 0; i < len; i ++) {
            cout << cur;
        }
        cout << endl;
        return;
    }
    int len = sz(s) / n;
    string cur = s.substr(0, n);
    string t;
    for (int i = 0; i < len; i ++) {
        t += cur;
    }
    if (s < t) {
        cout << t << endl;
        return;
    }
    // cur += 1
    reverse(all(cur));
    int c = 1;
    for (int i = 0; i < n and c; i ++) {
        int now = (c + cur[i] - '0');
        if (now == 10) {
            c = 1;
            cur[i] = '0';
        }
        else {
            c = 0;
            cur[i] += 1;
        }
    }
    reverse(all(cur));
    
    if (c == 0) {
        t = "";
        for (int i = 0; i < len; i ++) {
            t += cur;
        }
        cout << t << endl;
        return;
    }
    // c == 1 说明是999999 所以需要变成100100100
    len += 1;
    cur = "1" + string(n - 1, '0');
    for (int i = 0; i < len; i ++) {
        cout << cur;
    }
    cout << endl;
    return;
}