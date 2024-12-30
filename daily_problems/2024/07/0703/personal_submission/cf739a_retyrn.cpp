int n, m;

void solve() {
    cin >> n >> m;
    int res = inf;
    while (m --) {
        int x, y;
        cin >> x >> y;
        res = min(res, y - x + 1);
    }
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        a[i] = i % res;
    }
    cout << res << endl;
    cout << a << endl;
}