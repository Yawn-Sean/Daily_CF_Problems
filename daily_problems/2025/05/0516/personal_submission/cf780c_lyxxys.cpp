void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<unordered_set<int>> vis(n);

    for (int i = 0,u,v; i < n-1; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <int> ans(n);
    auto dfs_find = [&](auto &&self, int u, int presor)->void{
        int j = 0;
        for (auto &v : g[u]){
            if (v == presor) continue;
            vis[v].insert(ans[u]);

            while (vis[u].count(j)) j += 1;

            ans[v] = j;
            vis[v].insert(j);
            vis[u].insert(j);
        }

        for (auto &v : g[u]){
            if (v == presor) continue;
            self(self, v, u);
        }
    };

    vis[0].insert(0);
    dfs_find(dfs_find, 0, -1);

    int ma = *max_element(ans.begin(), ans.end());
    cout << ma+1 << "\n";
    print(ans, 1);
}
