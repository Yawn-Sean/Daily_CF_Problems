void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> vis(n);
    vector<vector<int>> deps(n+1);
    vector <array<int,2>> ans;
    for (int i = 0, x; i < n; ++ i){
        cin >> x;
        deps[x].push_back(i);
    }

    auto dfs_find = [&](auto &&self, int u, int dep)->void{
        vis[u] = 1;
        int cnt = !dep ? k : k-1;
        while (!deps[dep+1].empty() && cnt){
            cnt -= 1;
            int x = deps[dep+1].back();
            deps[dep+1].pop_back();
            ans.push_back({u+1, x+1});
            self(self, x, dep+1);
        }
    };
    if (deps[0].size()) dfs_find(dfs_find, deps[0][0], 0);
    bool jug = 0;
    for (int i = 0; i < n; ++ i){
        if (!vis[i]){
            jug = 1;
        }
    }
    if (jug) return void(cout << -1 << "\n");

    cout << ans.size() << "\n";
    for (auto &[x, y] : ans){
        cout << x << " " << y << "\n";
    }
}
