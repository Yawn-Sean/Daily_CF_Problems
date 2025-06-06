void solve(){
    int n;
    cin >> n;
    vector<vector<int>> cnts(n,vector<int>(n));
    vector<array<int,2>> edgs;
    vector<vector<int>> g(n);
    vector <int> A(n), order(n), fa_edge(n);
    for (auto &x : A){
        cin >> x;
    }
    for (int i = 0,u,v,w; i < n-1; ++ i){
        cin >> u >> v >> w;
        u -= 1, v -= 1;
        g[u].push_back(i);
        g[v].push_back(i);
        edgs.push_back({u+v, w});
    }

    auto dfs_find = [&](auto &&self, int u, int presor)->void{
        for (auto &id : g[u]){
            int v = edgs[id][0]-u;
            if (v == presor) continue;
            fa_edge[v] = id;
            self(self, v, u);
        }
    };
    dfs_find(dfs_find, 0, -1);

    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](auto &u, auto &v){
        return A[u] < A[v];
    });

    vector <int> ans(n);
    for (auto &i : order){
        int u = i, snap = 0;
        while (u > 0){
            auto [uv, w] = edgs[fa_edge[u]];
            int father = uv-u;
            while (cnts[u][snap] == w){
                snap += 1;
            }
            cnts[u][snap] += 1;
            snap += 1;
            u = father;
        }
        ans[i] = snap;
    }

    print(ans);
}
