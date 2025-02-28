int n;

void solve() {
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO" << endl;
        return;
    }
    int root = 0;
    vector<vector<int>> g(n);
    vector<int> p(n);
    vector<int> d(n);
    for (int i = 0; i < n; i ++) {
        int fa;
        cin >> fa;
        if (!fa) {
            root = i;
            continue;
        }
        fa --;
        g[fa].push_back(i);
        p[i] = fa;
        d[i] += 1;
        d[fa] += 1;
    }
    
    vector<int> st(n, true);
    vector<int> res;
    
    auto dfs1 = [&](auto&& self, int u) -> void {
        res.push_back(u + 1);
        st[u] = false;
        for (auto x : g[u]) {
            if (st[x]) self(self, x);
        }
    };
    
    auto dfs2 = [&](auto&& self, int u) -> void {
        for (auto x : g[u]) {
            self(self, x);
        }
        if (d[u] % 2 == 0) {
            if (u != root) {
                d[p[u]] -= 1;
            }
            dfs1(dfs1, u);
        }
    };
    
    dfs2(dfs2, root);
    cout << "YES" << endl;
    for (auto x : res) {
        cout << x << endl;
    }
}