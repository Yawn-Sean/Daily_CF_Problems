void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> num_id(n);

    iota(all(num_id), 0);
    sort(all(num_id), [&](int x, int y) {
        if (a[x] == a[y]) return x < y;
        return a[x] > a[y];
    });
    
    cin >> m;
    vector<pii> query(m);
    cin >> query;
    
    vector<int> id(m);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) {
        return query[x] < query[y];
    });
    
    vector<int> res(m);
    int j = 0;
    Fenwick<int> fen(n);
    
    for (auto idx : id) {
        int len = query[idx].fi, k = query[idx].se;
        while (j < len) {
            fen.add(num_id[j], 1);
            j ++;
        }
        // 需要找到第k个
        int ans = fen.select(k - 1);
        res[idx] = a[ans];
    }
    for (auto x : res) {
        cout << x << endl;
    }
}