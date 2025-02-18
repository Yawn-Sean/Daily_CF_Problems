int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<int> a(n);
    cin >> a;
    
    DSU dsu(n);
    while (m --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        dsu.merge(x, y);
    }
    
    vector<vector<int>> con(n);
    int res = 0;
    
    for (int i = 0; i < n; i ++) {
        int root = dsu.leader(i);
        con[root].pbk(i);
    }
    
    vector<int> cnt(k + 1);
    for (auto& vec : con) {
        if (sz(vec) <= 1) continue;
        int len = sz(vec), mx = 0;
        for (auto x : vec) {
            chmax(mx, ++ cnt[a[x]]);
        }
        res += len - mx;
        
        for (auto x : vec) {
            cnt[a[x]] = 0;
        }
    }
    cout << res << endl;
}