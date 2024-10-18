int n, m;

void solve() {
    cin >> n >> m;
    // 优先排下面的节点 再排父节点
    // 每个人必须送给离他最近的有礼物的祖先节点
    
    vector<vector<int>> son(n);
    vector<int> fa(n, -1);
    
    while (m --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        son[x].push_back(y);
        fa[y] = x;
    }
    
    vector<int> g(n);
    vector<int> have_gift(n, false);
    for (int i = 0; i < n; i ++) {
        cin >> g[i];
        g[i] -= 1;
        have_gift[g[i]] = true;
    }
    
    vector<int> res;
    vector<int> st(n, false);
    vector<int> target(n);
    
    auto dfs = [&](auto&& dfs, int u, int t) -> void {
        st[u] = true;
        if (have_gift[u]) t = u;
        for (auto x : son[u]) {
            dfs(dfs, x, t);
        }
        target[u] = t;
        if (have_gift[u]) res.push_back(u);
    };
    
    for (int i = 0; i < n; i ++) {
        if (st[i]) continue;
        int root = i;
        while (fa[root] >= 0) root = fa[root];
        dfs(dfs, root, -1);
    }

    if (g != target) {
        cout << -1 << endl;
        return;
    }
    
    cout << sz(res) << endl;
    for (auto x : res) {
        cout << x + 1 << endl;
    }
}