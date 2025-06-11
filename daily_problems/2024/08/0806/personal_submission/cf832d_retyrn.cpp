int len(int a, int b) {
    int c = lca(a, b);
    return d[a] + d[b] - d[c] * 2;
}

int cal(int a, int b, int c) {
    return (len(a, c) + len(b, c) - len(a, b)) / 2 + 1;
}

void solve() {
    cin >> n >> q;
    g.resize(n + 1);
    pre.resize(n + 10, vector<int>(m, 0));
    d.resize(n + 10, 0);
    for (int i = 2; i <= n; i ++) {
        int x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    getpre(1, 0);
    
    while (q --) {
        int x, y, z;
        cin >> x >> y >> z;
        int res = 0;
        chmax(res, cal(x, y, z));
        chmax(res, cal(x, z, y));
        chmax(res, cal(y, z, x));
        cout << res << endl;
    }
}