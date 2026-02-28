i64 op(i64 a, i64 b) {
    return max(a, b);
}

i64 e() {
    return 0;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<i64> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    segtree<i64, op, e> seg(k + 10);
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        if (l) {
            seg.set(l, seg.get(l) + x);
        }
        if (r < n - 1) {
            seg.set(r + 1, seg.get(r + 1) - x);
        }
        int res = n - (lower_bound(a.begin(), a.end(), seg.all_prod()) - a.begin());
        cout << res << '\n';
    }
}
