int n;

void solve() {
    cin >> n;
    DSU dsu(n + 1);
    vector<vector<int>> f(n + 1);
    for (int i = 1; i <= n; i ++) {
        f[i].push_back(i);
    }
    
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        x = dsu.leader(x);
        y = dsu.leader(y);
        if (dsu.size(x) < dsu.size(y)) swap(x, y);
        
        // y->x
        dsu.merge(x, y);
        for (auto val : f[y]) {
            f[x].push_back(val);
        }
    }
    
    int t = dsu.leader(1);
    cout << f[t] << endl;
}