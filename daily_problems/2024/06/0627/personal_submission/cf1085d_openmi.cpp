void solve() {
    int n;
    double s;
    cin >> n >> s;
    vc<vc<int>> g(n);
    vi ind(n);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[--x].push_back(--y);
        g[y].push_back(x);        
        ind[x]++;
        ind[y]++;
    }
    int end_point = 0;
    rep (i, 0, n) {
        if (ind[i] == 1) end_point++;
    }
    cout << setprecision(10) << (s / end_point) * 2 ;
}
