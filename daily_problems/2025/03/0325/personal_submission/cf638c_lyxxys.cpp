void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n), ans, days(n+1);
    vector <int> who(n, -1), edgs;
    for (int i = 0,u,v; i < n-1; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        edgs.push_back(u+v);
        g[u].push_back(i);
        g[v].push_back(i);
    }

    // dfs 保证最大度数时 最多天
    auto dfs_find = [&](auto &&self, int u, int presor, int lst)->void{
        int tot = -1;

        for (auto &i : g[u]){
            int v = edgs[i]-u;
            if (v == presor) continue;
            ++ tot;
            if (tot == lst) ++ tot;
            days[tot].push_back(i);
            who[i] = tot;
        }
        for (auto &i : g[u]){
            int v = edgs[i]-u;
            if (v == presor) continue;
            self(self, v, u, who[i]);
        }
    };

    dfs_find(dfs_find, 0, -1, -1);
    for (int i = 0; i <= n; ++ i){
        if (days[i].size()){
            ans.push_back(days[i]);
        }
    }

    cout << ans.size() << "\n";
    for (auto &vec : ans){
        cout << vec.size();
        for (auto &x : vec){
            cout << " " << x+1;
        }
        cout << "\n";
    }
}
