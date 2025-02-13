inline void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> g;
    for(int i=1; i<=m; i++) {
        int a, b, e;
        cin >> a >> b >> e;
        g.push_back({e, a, b});
    }
    DSU dsu1(n), dsu2(n);
    sort(g.begin()+1, g.end());
    dsu1.merge(g[0][1], g[0][2]);
    for(int i=1; i<m; i++) {
        auto [w, u, v] = g[i];
        if(!dsu1.same(u, v)) {
            dsu1.merge(u, v);
            dsu2.merge(u, v);
        }
    }
    for(int i=1; i<m; i++) {
        auto [w, u, v] = g[i];
        if(!dsu2.same(u, v)) {
            cout << w << endl;
            return;
        }
    }
    cout << (int)1e9 << endl;

}
