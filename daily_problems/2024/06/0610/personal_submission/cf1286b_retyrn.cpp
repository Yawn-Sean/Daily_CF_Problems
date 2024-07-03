int n;

void solve() {
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> c(n);
    
    int root = -1;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x >> c[i];
        x --;
        if (x >= 0) g[x].push_back(i);
        else root = i;
    }
    vector<int> res(n);
    bool ok = true;
    
    function<vector<int>(int)> dfs = [&](int u) -> vector<int> {
        vector<int> son;
        for (auto x : g[u]) {
            auto t = dfs(x);
            for (auto y : t) {
                if (sz(son) and res[y] <= res[son.back()]) {
                    res[y] = res[son.back()] + 1;
                }
                son.push_back(y);
            }
        }
        if (sz(son) < c[u]) {
            ok = false;
            return {};
        }
        if (c[u] > 0) res[u] = res[son[c[u] - 1]] + 1;
        else res[u] = 1;
        
        if (c[u] < sz(son) and res[u] == res[son[c[u]]]) {
            for (int i = c[u]; i < sz(son); i ++) {
                res[son[i]] += 1;
            }
        }
        son.push_back(u);
        sort(all(son), [&](int x, int y) {
            return res[x] < res[y];
        });
        // dbg(u, son);
        return son;
    };
    
    dfs(root);
    if (ok) {
        cout << "YES" <<endl;
        cout << res << endl;
    }
    else {
        cout << "NO" << endl;
    }
}