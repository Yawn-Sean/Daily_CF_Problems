void Solve() {
    int x, d;cin >> x >> d;
    int now = 1;
    basic_string<int> res;
    for (int i = 30;i >= 0;i--) {
        if (x >> i & 1) {
            for (int j = 1;j <= i;j++) res += now;
            now += d;
            res += now;
            now += d;
        }
    }
    cout << res.size() << endl;
    for (auto i : res) cout << i << " ";
}
