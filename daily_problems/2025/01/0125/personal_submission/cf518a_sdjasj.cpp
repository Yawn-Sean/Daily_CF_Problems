void solve() {
    string s, tt;
    cin >> s >> tt;
    int c = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        int t = s[i] - 'a';
        if (i == n - 1) {
            t++;
        } else {
            t += c;
        }
        if (t > 25) {
            c = 1;
            t %= 26;
        } else {
            c = 0;
        }
        s[i] = 'a' + t;
    }
    if (c == 1 || s == tt) {
        cout << "No such string";
    } else {
        cout << s << endl;
    }
    return;
}