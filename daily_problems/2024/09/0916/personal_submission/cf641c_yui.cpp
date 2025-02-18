void solve() {
    int n, q;
    cin >> n >> q;

    int s = 0;
    int x = 0, y = 1;
    for (int i = 0; i < q; i++) {
        int op, m;
        cin >> op;
        if (op == 1) {
            cin >> m;
            s += m;
            x = ((x + m) % n + n) % n;
            y = ((y + m) % n + n) % n;
        } else {
            x = (x ^ 1) % n;
            y = (y ^ 1) % n;
        }
    }

    vec<int> ans(n);
    int even = n / 2, odd = n - even;
    int idx = x, cur = 1;
    for (int i = 0; i < odd; i++) {
        ans[idx] = cur;
        cur += 2;
        idx = (idx + 2) % n;
    }
    idx = y, cur = 2;
    for (int i = 0; i < even; i++) {
        ans[idx] = cur;
        cur += 2;
        idx = (idx + 2) % n;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}
