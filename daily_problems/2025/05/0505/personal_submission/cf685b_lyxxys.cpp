void solve(){
    int n, q;
    cin >> n >> q;
    vector <int> ans(n), p(n, -1), sz(n, 1), tree_ma(n, -1);
    vector<vector<int>> g(n);
    
    for (int i = 1; i < n; ++ i){
        cin >> p[i];
        p[i] -= 1;
        g[p[i]].push_back(i);
    }

    auto better = [&](int u, int tot)->bool{
        return 2*max(tree_ma[u], tot-sz[u]) > tot;
    };
    auto dfs_find = [&](auto &&self, int u)->void{
        int chose = -1;
        for (auto &v : g[u]){
            self(self, v);
            if (chose == -1 || sz[v] > sz[chose]){
                chose = v;
            }
            sz[u] += sz[v];
        }

        if (chose == -1 || 2*sz[chose] <= sz[u]){
            ans[u] = u;
        } else {
            int j = ans[chose];
            tree_ma[u] = sz[chose];

            while (better(j, sz[u])){
                j = p[j];
            }
            assert(2*max(tree_ma[j], sz[u]-sz[j]) <= sz[u]);
            ans[u] = j;
        }
    };
    dfs_find(dfs_find, 0);

    while (q--){
        int x;
        cin >> x;
        x -= 1;
        cout << ans[x]+1 << "\n";
    }
}
