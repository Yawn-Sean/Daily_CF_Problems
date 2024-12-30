void solve() {
    int n, q;
    cin >> n >> q;
    vc<int> a(n);
    in(a);
    int i = 0, last_p0 = -1;
    while (i < n and a[i] == 0) a[i] = 1, last_p0 = i, i++;
    int pre = 0,  hasq = 0;
    while (i < n) {
        if (a[i] == 0) a[i] = pre, last_p0 = i;
        else if (a[i] == q) hasq = 1;
        pre = a[i];
        ++i;
    }
    if (!hasq) {
        if (last_p0 == -1) {
            p(0);
            return;
        } else a[last_p0] = q;
    } 
    segtree<int, fmin, e> seg(a);
    unordered_map<int, pii> v_lr;
    rep (j, 0, n) {
        int x = a[j];
        if (v_lr.count(x)) {
            v_lr[x].second = j;
        } else {
            v_lr[x] = make_pair(j, j);
        }
    }
    for (auto& [k, pr]: v_lr) {
        auto &[l, r] = pr;
        if (seg.prod(l, r + 1) < k) {
            p(0);
            return ;
        } 
    }
    p(1);
    printv(a, ' ', false);
}
