int n, d;

void solve() {
    cin >> n >> d;
    vector<int> a(n);
    cin >> a;
    // 维护可行的区间
    int l = 0, r = 0, res = 0;
    for (auto x : a) {
        if (x == 0) {
            l = max(l, 0);
            if (r < 0) {
                r = d;
                res += 1;
            }
        }
        l += x;
        r += x;
        r = min(r, d);
        if (l > r) {
            cout << -1 << endl;
            return;
        }
    }
    cout << res << endl;
}