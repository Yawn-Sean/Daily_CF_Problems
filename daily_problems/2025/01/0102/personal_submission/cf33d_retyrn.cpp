ll dis(int x1, int y1, int x2, int y2) {
    return (ll)(x1 - x2) * (x1 - x2) + (ll)(y1 - y2) * (y1 - y2);
}

int n, m, q;

void solve() {
    cin >> n >> m >> q;
    vector<int> rs(n + m + 1, 0), xs(n + m + 1, 0), ys(n + m + 1, 0);
    rs[0] = inf;
    
    for (int i = 1; i <= n; i ++) {
        rs[i] = 0;
        cin >> xs[i] >> ys[i];
    }
    for (int i = n + 1; i < n + m + 1; i ++) {
        cin >> rs[i] >> xs[i] >> ys[i];
    }
    
    // 根节点是最大的圆
    vector<int> id(n + m + 1);
    iota(all(id), 0);
    sort(all(id), [&rs](int x, int y) {
        return rs[x] > rs[y];
    });
    int len = n + m + 1;
    
    g.resize(len + 1);
    d.resize(len + 5, 0);
    pre.resize(len + 5, vector<int>(M, 0));
    
    for (int i = 0; i < len; i ++) {
        int x = id[i];
        for (int j = i - 1; j >= 0; j --) {
            int y = id[j];
            ll d = dis(xs[x], ys[x], xs[y], ys[y]);
            if (d < (ll)(rs[y] - rs[x]) * (rs[y] - rs[x])) {
                // j圆是i圆的父亲
                g[y + 1].pbk(x + 1);
                break;
            }
        }
    }
    
    getpre(1, 0);
    
    while (q --) {
        int x, y;
        cin >> x >> y;
        x ++, y ++;
        if (x == y) {
            cout << 0 << endl;
            continue;
        }
        auto z = lca(x, y);
        cout << d[x] + d[y] - d[z] * 2 - 2 << endl;
    }
}