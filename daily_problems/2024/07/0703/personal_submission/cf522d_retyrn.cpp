int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    vector<pii> query(m);
    for (auto& q : query) {
        cin >> q.fi >> q.se;
        q.fi -= 1;
        q.se -= 1;
    }
    
    vector<int> res(m);
    vector<int> id(m);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) {
        return query[x].se < query[y].se;
    });
    map<int, int> mp;
    SegmentTree tree(n);
    int cur = 0;
    
    for (auto idx : id) {
        while (cur <= query[idx].se) {
            if (mp.count(a[cur])) {
                int l = mp[a[cur]], r = cur;
                tree.modify(1, 1, n, l + 1, r - l);
            }
            mp[a[cur]] = cur;
            cur ++;
        }
        int ans = tree.query(1, 1, n, query[idx].fi + 1, query[idx].se + 1);
        res[idx] = (ans >= inf / 2 ? -1 : ans);
    }
    
    for (auto x : res) {
        cout << x << endl;
    }
}