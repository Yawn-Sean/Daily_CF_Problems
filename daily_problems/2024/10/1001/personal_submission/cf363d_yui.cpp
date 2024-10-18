void solve() {
    int n, m, a;
    cin >> n >> m >> a;
    vec<int> b(n), p(m);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> p[i];

    ranges::sort(b);
    ranges::sort(p);
    
    auto check = [&](int m) -> pair<bool, int> {
        int need = 0, res = 0;
        int pi = 0, bi = n - m;
        for (int i = 0; i < m; i++) {
            if (b[bi] >= p[pi]) {
                res += p[pi];
            } else {
                need += p[pi] - b[bi];
                res += b[bi];
            }
            bi++, pi++;
        }
        if (need > a) return {false, 0};
        chmin(res, max(0ll, res - a + need));
        return {true, res};
    };

    int cost = 0;
    int l = -1, r = min(n, m) + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        auto [ok, c] = check(m);
        if (ok) {
            l = m;
            cost = c;
        } else {
            r = m;
        }
    }

    cout << l << ' ' << cost << '\n';
}
