void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    int m;cin >> m;
    vector<int> b(m + 1);for (int i = 1;i <= m;i++) cin >> b[i];
    vector<array<int, 2>> e;
    for (int i = 1, j = 1;;j++) {
        int x = 0, l = i;
        while (i <= n and x < b[j]) x += a[i], i++;
        if (x != b[j]) return cout << "NO\n", void();
        e.push_back({ l,i - 1 });
        if (j == m) {
            if (i == n + 1) break;
            else return cout << "NO\n", void();
        }
    }
    vector<array<int, 2>> res;
    for (int i = e.size() - 1;i >= 0;i--) {
        auto [l, r] = e[i];
        //cout << l << ' ' << r << endl;
        auto  mx = *max_element(a.begin() + l, a.begin() + r + 1);
        auto run = [&]()->int {
            for (int i = l;i <= r;i++) {
                if (a[i] == mx and ((i - 1 >= l and a[i - 1] < a[i]) or (i + 1 <= r and a[i + 1] < a[i]))) {
                    int p = i;
                    if ((i - 1 >= l and a[i - 1] < a[i])) {
                        for (int j = i - 1;j >= l;j--, p--) {
                            res.push_back({ p,0 });
                        }
                        for (int j = i + 1;j <= r;j++) {
                            res.push_back({ p,1 });
                        }
                    }
                    else {
                        for (int j = i + 1;j <= r;j++) {
                            res.push_back({ p,1 });
                        }
                        for (int j = i - 1;j >= l;j--, p--) {
                            res.push_back({ p,0 });
                        }
                    }
                    return 1;
                }
            }
            return (r - l == 0);
            };
        if (!run()) return cout << "NO\n", void();
    }
    cout << "YES\n";
    for (auto [x, y] : res) {
        cout << x << " ";
        if (y == 0) cout << "L\n";
        else cout << "R\n";
    }
}
