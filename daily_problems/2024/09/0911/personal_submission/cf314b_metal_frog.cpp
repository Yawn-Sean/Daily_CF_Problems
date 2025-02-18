void solve() {
    string a, c;
    int b, d;
    cin >> b >> d >> a >> c;

    vector<int> nxt(c.length()), cnt(c.length());
    for (int i = 0, x; i < c.length(); i++) {
        x = i;
        for (int j = 0; j < a.length(); j++) {
            if (a[j] == c[x]) {
                x++;
                if (x == c.length()) {
                    cnt[i]++;
                    x = 0;
                }
            }
        }
        nxt[i] = x;
    }
    int pos = 0, ans = 0;
    for (int i = 1; i <= b; i++) {
        ans += cnt[pos];
        pos = nxt[pos];
    }
    cout << ans / d << "\n";
}
