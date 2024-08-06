int n, q, c;

void solve() {
    cin >> n >> q >> c;
    vector<vector<vector<int>>> a(c + 1, vector<vector<int>>(110, vector<int>(110, 0)));
    
    for (int i = 0; i < n; i ++) {
        int x, y, s;
        cin >> x >> y >> s;
        for (int i = 0; i <= c; i ++) {
            a[i][x][y] += (s + i) % (c + 1);
        }
    }
        
    vector<PrefixSum2D<int>> f(c + 1, PrefixSum2D<int>(100, 100));
    for (int i = 0; i <= c; i ++) {
        f[i].init(a[i]);
    }
    
    while (q --) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= (c + 1);
        cout << f[t].sum(x1, y1, x2, y2) << endl;
    }
}