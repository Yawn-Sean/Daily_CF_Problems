void solve() {
    int n, m, ql, qr;
    cin >> n >> m;
    vi l, r, v;
    map<int, int> mp;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        // 从左往右扫的过程中若发现存在包含已有区间的更大区间时，不再加入该区间，使得l、r始终有序
        if (mp.count(x)) {
            int pre_i = mp[x];
            mp[x] = i;
            if (!l.empty() and pre_i <= l.back()) continue;
            l.push_back(pre_i), r.push_back(i), v.push_back(i - pre_i);
        } else mp[x] = i;
        
    }
    int vs = v.size();
    segtree<int, fmin, e> seg(v);
    rep (i, 0, m) {
        cin >> ql >> qr;
        if (l.empty()) {
            cout << -1 << nl;
            continue;
        }
        // 对齐0读入下标
        ql--, qr--;
        int iql = lower_bound(all(l), ql) - l.begin();
        int iqr = upper_bound(all(r), qr) - r.begin();
        if (iql >= iqr) {
            cout << -1 << nl;
        } else {
            cout << seg.prod(iql, iqr) << nl;
        }
    }
}
