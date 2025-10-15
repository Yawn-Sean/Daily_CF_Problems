void Solve() {
    int n, m, c;cin >> n >> m >> c;
    vector<int> a(n + 1);
    auto ask = [&](int x) {
        cout << x << endl;
        int ret;cin >> ret;
        return ret;
        };
    int left_r = 0, right_l = n + 1;
    for (int i = 1;i <= m;i++) {
        if (left_r + 1 == right_l) break;
        int p;cin >> p;
        if (p <= c / 2) {
            auto f = [&]() {
                for (int j = 1;j <= n;j++) {
                    if (!a[j]) {
                        a[j] = p;
                        left_r = max(left_r, j);
                        cout << j << endl;
                        return;
                    }
                    if (a[j] > p) {
                        a[j] = p;
                        left_r = max(left_r, j);
                        cout << j << endl;
                        return;
                    }
                }
                };
            f();
        }
        else {
            auto f = [&]() {
                for (int j = n;j >= 1;j--) {
                    if (!a[j]) {
                        a[j] = p;
                        right_l = min(right_l, j);
                        cout << j << endl;
                        return;
                    }
                    if (a[j] < p) {
                        a[j] = p;
                        right_l = min(right_l, j);
                        cout << j << endl;
                        return;
                    }
                }
                };
            f();
        }
    }
}
