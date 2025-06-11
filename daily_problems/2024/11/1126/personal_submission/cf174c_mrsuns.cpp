void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = n;i >= 1;i--) a[i] -= a[i - 1];
    vector<int> b;
    for (int i = 1;i <= n;i++) {
        if (a[i] < 0) {
            for (int j = 0;j < -a[i];j++) b.push_back(i);
        }
    }
    reverse(b.begin(), b.end());
    vector<array<int, 2>> res;
    for (int i = 1;i <= n;i++) {
        if (a[i] > 0) {
            while (a[i]) {
                a[i]--;
                if (b.size()) res.push_back({ i, b.back() - 1 }), b.pop_back();
                else res.push_back({ i,n });
            }
        }
    }
    cout << res.size() << endl;
    for (auto [x, y] : res) {
        cout << x << " " << y << endl;
    }
}
