int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    
    double res = 0.0;
    while (m --) {
        int x, y, w;
        cin >> x >> y >> w;
        x --, y --;
        res = max(res, 1.0 * (a[x] + a[y]) / w);
    }
    cout << res << endl;
}