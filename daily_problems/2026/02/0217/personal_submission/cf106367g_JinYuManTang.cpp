int op(int x, int y) {
    return max(x, y);
}

int e() {
    return 0;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    segtree<int, op, e> seg(b);
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        i64 res = 0;
        while (1) {
            l = seg.max_right(l, [&](int s) {
                return s < x;
            });
            if (l >= r) {
                break;
            }
            res += b[l];
            seg.set(l, 0);
        }
        cout << res << '\n';
    }
}
