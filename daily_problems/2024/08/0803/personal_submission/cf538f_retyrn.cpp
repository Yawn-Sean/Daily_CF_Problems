int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) {
        if (a[x] == a[y]) return x < y;
        return a[x] < a[y];
    });
    
    Fenwick<int> fen(n);
    vector<int> res(n);
    
    for (auto idx : id) {
        for (int k = 1; k < n; k ++) {
            int l = k * idx + 1, r = min(k * (idx + 1), n - 1);
            if (l >= n) break;
            res[k] += fen.rangeSum(l, r + 1);
        }
        fen.add(idx, 1);
    }
    
    for (int i = 1; i < n; i ++) {
        cout << res[i] << ' ';
    }
    cout << endl;
}