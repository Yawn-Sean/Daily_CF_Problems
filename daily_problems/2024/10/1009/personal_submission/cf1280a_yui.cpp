#define int i64

void solve() {
    int x;
    string s;
    cin >> x >> s;

    int n = s.length();
    int i = 0;
    for (; i < x; i++) {
        if (n >= x) break;
        int c = s[i] - '0';
        if (c == 1) continue;

        string t = s.substr(i + 1);
        s += t;
        if (c == 3) s += t;
        n = s.length();
    }
    Z ans = s.length();
    for (; i < x; i++) {
        int c = s[i] - '0';
        if (c == 1) continue;
        else if (c == 2) ans += (ans - i - 1);
        else if (c == 3) ans += (ans - i - 1) * 2;
    }

    cout << ans << '\n';
}
