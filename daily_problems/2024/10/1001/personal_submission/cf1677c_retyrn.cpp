int n;

void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;
    DSU dsu(n);
    for (int i = 0; i < n; i ++) {
        int x = a[i] - 1, y = b[i] - 1;
        dsu.merge(x, y);
    }
    vector<int> con;
    
    for (int i = 0; i < n; i ++) {
        if (dsu.leader(i) == i) {
            con.push_back(dsu.size(i));
        }
    }
    
    sort(all(con));
    ll res = 0;
    int l = 1, r = n;
    for (auto x : con) {
        x = x & ((1 << 20) - 2);
        for (int i = 0; i < x / 2; i ++) {
            res += (r - l) * 2;
            l ++;
            r --; 
        }
    }
    cout << res << endl;
}