void Solve() {
    array<int, 4> x, y;
    cin >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];
    int ss = x[1] * y[1] + x[2] * y[2] + x[3] * y[3];
    int s = sqrt(ss);
    if (s * s != ss) return cout << "-1\n", void();
    for (int i = 1;i <= 3;i++) {
        if (x[i] > s || y[i] > s) return cout << "-1\n", void();
    }
    if ((x[1] == s || y[1] == s) and (x[2] == s || y[2] == s) and (x[3] == s || y[3] == s)) {
        cout << s << endl;
        for (int i = 1;i <= 3;i++) {
            for (int j = 1;j <= (x[i] != s ? x[i] : y[i]);j++) cout << string(s, 'A' + i - 1) << endl;
        }
        return;
    }
    else {
        auto f = [&](int u, int v, int w) {
            if (x[u] == s || y[u] == s) {
                int goa = x[u] != s ? x[u] : y[u];
                if ((y[v] == s - goa or x[v] == s - goa) and (y[w] == s - goa or x[w] == s - goa)) {
                    cout << s << endl;
                    for (int i = 1;i <= goa;i++) cout << string(s, 'A' + u - 1) << endl;
                    for (int i = 1;i <= s - goa;i++) {
                        cout << string((x[v] != s - goa) ? x[v] : y[v], 'A' + v - 1) + string((x[w] != s - goa) ? x[w] : y[w], 'A' + w - 1) << endl;
                    }
                    return 1;
                }
            }
            return 0;
            };
        if (f(1, 2, 3) or f(2, 1, 3) or f(3, 1, 2)) return;
    }
    cout << "-1\n";
}
