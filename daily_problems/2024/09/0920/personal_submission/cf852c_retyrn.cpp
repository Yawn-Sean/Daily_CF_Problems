int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> id(n);
    iota(all(id), 0);
    
    sort(all(id), [&](int x, int y) {
        return a[x] + a[(x + 1) % n] < a[y] + a[(y + 1) % n];
    });
    
    vector<int> res(n);
    for (int i = 0; i < n; i ++) {
        res[id[i]] = i;
    }
    cout << res << endl;
}