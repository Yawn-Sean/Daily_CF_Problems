int n, k;

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].pbk(y);
        g[y].pbk(x);
    }
    
    int t = 0;
    for (auto x : a) {
        t ^= x;
    }
    if (t == 0) {
        // 一定可以
        cout << "YES" << endl;
        return;
    }
    
    if (k == 2) {
        cout << "NO" << endl;
        return;
    }
    
    int cnt = 0;
    function<int(int, int)> dfs = [&](int u, int fa) {
        int res = a[u];
        for (auto x : g[u]) {
            if (x == fa) continue;
            res ^= dfs(x, u);
        }
        if (res == t) {
            cnt ++;
            return 0;
        }
        return res;
    };
    
    dfs(0, -1);
    
    cout << (cnt >= 3 ? "YES" : "NO") << endl;
}
