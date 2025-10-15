void solve() {
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    vector<int> tr1(n + 1), tr2(n + 1);
    auto lowbit = [](int x) -> int {
        return x & -x;
    };
    auto add = [&](vector<int>& tr, int x, int v) -> void {
        for (int i = x; i <= n; i += lowbit(i)) {
            tr[i] += v;
        }
    };
    auto query = [&](vector<int>& tr, int x) -> int {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tr[i];
        }
        return ans;
    };
    while (q--) {
        int op, x, y;
        cin >> op >> x;
        if (op == 1) cin >> y;
        if (op == 1) {
            int v = query(tr1, x) - query(tr1, x - 1);
            if (v < b) {
                add(tr1, x, min(b - v, y));
            }
            v = query(tr2, x) - query(tr2, x - 1);
            if (v < a) {
                add(tr2, x, min(a - v, y));
            }
        } else {
            int ans = query(tr1, x - 1);
            if (x + k <= n) {
                ans += query(tr2, n) - query(tr2, x + k - 1);
            }
            cout << ans << endl;
        }
    }
}