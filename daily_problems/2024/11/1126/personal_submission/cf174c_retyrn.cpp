int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> b(n + 1);
    for (int i = 0; i < n; i ++) {
        b[i] = a[i] - (i - 1 >= 0 ? a[i - 1] : 0);
        b[n] -= b[i];
    }
    vector<pii> stk;
    vector<pii> res;
    for (int i = 0; i <= n; i ++) {
        if (b[i] > 0) {
            stk.emplace_back(i, b[i]);
            continue;
        }
        int t = -b[i];
        while (t --) {
            res.emplace_back(stk.back().fi + 1, i);
            if (--stk.back().se == 0) stk.pop_back();
        }
    }
    cout << sz(res) << endl;
    for (auto& p : res) {
        cout << p << endl;
    }
}