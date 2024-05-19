int n;

void solve() {
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i ++) {
        int p;
        cin >> p;
        p --;
        g[p].push_back(i);
    }
    
    vector<int> f(n, 0);
    // 预处理每个节点所在的子树有几个叶子节点
    function<int(int)> dfs = [&](int u) -> int {
        if (em(g[u])) {
            f[u] = 1;
            return 1;
        }
        int res = 0;
        for (auto x : g[u]) {
            res += dfs(x);
        }
        f[u] = res;
        return res;
    };
    dfs(0);
    
    sort(all(f));
    cout << f << endl;
}