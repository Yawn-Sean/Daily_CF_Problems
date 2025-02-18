int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    vector<pii> b(m);
    cin >> a;
    cin >> b;
    
    vector<int> id(n, 0);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) {
        return a[x] < a[y];
    });
    
    vector<int> res(n);
    vector<int> pos(110);
    for (int i = 0; i < n; i ++) {
        if (i & 1) {
            res[id[i]] = 1;
            pos[a[id[i]]] = 1;
        }
        else {
            res[id[i]] = 0;
            pos[a[id[i]]] = -1;
        }
    }
    for (auto [l, r] : b) {
        int sum = 0;
        for (int i = l; i <= r; i ++) {
            sum += pos[i];
        }
        if (abs(sum) > 1) {
            cout << -1 << endl;
            return;
        }
    }
    cout << res << endl;
}