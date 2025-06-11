void solve() {
    int n;
    string s;
    int x, y;
    cin >> n >> s >> x >> y;
    vec<int> sx(n + 1), sy(n + 1);
    for (int i = 0; i < n; i++) {
        sx[i + 1] = sx[i];
        sy[i + 1] = sy[i];
        if (s[i] == 'U') {
            sy[i + 1]++;
        } else if (s[i] == 'D') {
            sy[i + 1]--;
        } else if (s[i] == 'L') {
            sx[i + 1]--;
        } else {
            sx[i + 1]++;
        }
    }
    int dx = x - sx[n], dy = y - sy[n];
    if (dx == 0 && dy == 0) {
        cout << "0\n";
        return;
    }

    auto check = [&](int m) -> bool {
        for (int j = m; j <= n; j++) {
            int i = j - m;
            // [i, j)
            int ox = sx[n] - sx[j] + sx[i];
            int oy = sy[n] - sy[j] + sy[i];
            ox = abs(ox - x);
            oy = abs(oy - y);
            if (ox + oy <= m && (ox + oy - m) % 2 == 0) {
                return true;
            }
        }
        return false;
    };
    
    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    if (r == n + 1) {
        cout << "-1\n";
        return;
    }

    cout << r << '\n';
}
