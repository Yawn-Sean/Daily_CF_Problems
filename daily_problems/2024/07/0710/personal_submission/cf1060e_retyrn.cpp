int n;

void solve() {
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    // 换根dp
    // 按照距离分奇偶
    vector<ll> f0(n, 0LL), f1(n, 0LL);
    vector<int> size0(n, 0), size1(n, 0);
    function<void(int, int)> dfs1 = [&](int u, int fa) {
        for (auto x : g[u]) {
            if (x == fa) continue;
            dfs1(x, u);
            f0[u] += f1[x] + size1[x];
            f1[u] += f0[x] + size0[x];
            size0[u] += size1[x];
            size1[u] += size0[x];
        }
        size0[u] += 1;
    };
    dfs1(0, -1);
    
    vector<ll> dist0(n), dist1(n);
    
    dist0[0] = f0[0], dist1[0] = f1[0];
    vector<int> odd(n), even(n);
    odd[0] = size1[0], even[0] = n - odd[0];
    
    ll res = 0;
    
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        res += (dist1[u] + odd[u]) / 2 + dist0[u] / 2;
        for (auto x : g[u]) {
            if (x == fa) continue;
            odd[x] = even[u], even[x] = odd[u];
            dist0[x] = dist1[u] - size0[x] + (odd[u] - size0[x]);
            dist1[x] = dist0[u] - size1[x] + (even[u] - size1[x]);
            dfs2(x, u);
        }
    };
    dfs2(0, -1);
    res >>= 1;
    cout << res << endl;
}