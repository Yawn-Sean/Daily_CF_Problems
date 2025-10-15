void solve(){
    int n, m;
    cin >> n;
    vector <int> A(n);
    vector<vector<array<int,2>>> g(n);
    for (auto &x : A){
        cin >> x;
    }

    dsu Y(n);
    cin >> m;
    for (int i = 0,u,v; i < m; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        if (Y.merge(u, v)){
            g[u].push_back({v, i});
            g[v].push_back({u, ~i});
        }
    }

    vector <int> vis(n), ans(m);
    auto dfs = [&](auto &&self, int u, int presor)->void{
        vis[u] = 1;
        for (auto &[v, id] : g[u]){
            if (v == presor) continue;
            self(self, v, u);
            if (id >= 0) ans[id] = A[v];
            else ans[~id] = -A[v];
            A[u] += A[v];
        }
    };
    for (int i = 0; i < n; ++ i){
        if (!vis[i]){
            dfs(dfs, i, -1);
            if (A[i]){
                cout << "Impossible\n";
                return;
            }
        }
    }

    cout << "Possible\n";
    print(ans);
}

