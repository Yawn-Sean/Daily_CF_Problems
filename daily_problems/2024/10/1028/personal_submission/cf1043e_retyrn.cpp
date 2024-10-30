int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i] >> b[i];
    }
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) {
        return a[x] - b[x] < a[y] - b[y];
    });
    
    vector<ll> sa(n + 1), sb(n + 1);
    
    for (int i = 1; i <= n; i ++) {
        auto idx = id[i-1];
        sa[i] = sa[i-1] + a[idx];
        sb[i] = sb[i-1] + b[idx];
    }
    vector<ll> res(n);
    for (int i = 0; i < n; i ++) {
        auto idx = id[i];
        res[idx] = (ll)a[idx] * (n - i - 1) + (ll)b[idx] * i + sb[n] - sb[i + 1] + sa[i];
    }
    
    while (m --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        auto t = min(a[x] + b[y], a[y] + b[x]);
        res[x] -= t;
        res[y] -= t;
    }
    cout << res << endl;
}