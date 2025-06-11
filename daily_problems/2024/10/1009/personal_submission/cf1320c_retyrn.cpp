int op(int x, int y) {
    return max(x, y);
}

int e() {
    return -inf;
}

int mapping(int x, int y) {
    return x + y;
}

int composition(int x, int y) {
    return x + y;
}

int id() {
    return 0;
}

int n, m, p;

void solve() {
    cin >> n >> m >> p;
    vector<pii> a(n);
    vector<pii> b(m);
    vector<ai3> mon(p);
    
    cin >> a >> b;
    for (int i = 0; i < p; i ++) {
        for (int j = 0; j < 3; j ++) {
            cin >> mon[i][j];
        }
    }
    
    sort(all(a));
    sort(all(b));
    vector<int> vals;
    for (auto [x, y] : b) {
        if (em(vals) or vals.back() != x) vals.pbk(x);
    }
    map<int, int> mp;
    int k = sz(vals);
    
    for (int i = 0; i < k; i ++) {
        mp[vals[i]] = i;
    }
    
    sort(all(mon));
    vector<int> A(k, -inf);
    for (int i = 0; i < m; i ++) {
        A[mp[b[i].fi]] = max(A[mp[b[i].fi]], -b[i].se);
    }
    
    lazy_segtree<int, op, e, int, mapping, composition, id> tree(A);
    
    int j = 0;
    int res = -inf * 2;
    
    for (int i = 0; i < n; i ++) {
        while (j < p and a[i].fi > mon[j][0]) {
            int l = 0, r = k - 1;
            while (l <= r) {
                auto mid = (l + r) >> 1;
                if (vals[mid] > mon[j][1]) r = mid - 1;
                else l = mid + 1;
            }
            tree.apply(l, k, mon[j][2]);
            j ++;
        }
        res = max(res, tree.all_prod() - a[i].se);
    }
    
    cout << res << endl;
}