int n;

void solve() {
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
    }
    
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) {
        return a[x] < a[y];
    });
    
    vector<int> res(n, -1);
    set<pii> S;
    int j = 0;
    
    for (int i = 0; i < n; i ++) {
        auto idx = id[i];
        while (j < i and a[id[j]].fi < a[id[i]].fi) {
            S.insert(mpr(a[id[j]].se, id[j] + 1));
            j ++;
        }
        
        if (sz(S)) {
            auto it = S.lower_bound(mpr(a[idx].se, -1));
            if (it == S.begin()) continue;
            it --;
            res[idx] = it->se;
        }
    }
    cout << res << endl;
}